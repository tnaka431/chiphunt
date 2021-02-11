#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"NUMBER.h"
#include"PLAYER_CHIP.h"
#include"PLAYER_DICE.h"
#include"PLAYER_CARD.h"
#include"CPU_CHIP.h"
#include"CPU_DICE.h"
#include"CPU_CARD.h"
#include"FLOW.h"
#include "STATE.h"
#include"FADE.h"

void FLOW::init(CONTAINER* c) {
	for (int i = 0; i < FlowNumber; i++) {
		FlowImg[i] = c->flowimg[i];
	}
	YesImg = c->yesimg;
	NoImg = c->noimg;
	FlowPx = c->flowpx;
	FlowPy = c->flowpy;
	ArrowImg = c->arrowimg;
	ArrowPx1 = c->arrow1px;
	ArrowPx2 = c->arrow2px;
	ArrowPy = c->arrowpy;
	YesPx = c->yespx;
	YesPy = c->yespy;
	NoPx = c->nopx;
	NoPy = c->nopy;
	//��
	ResultBgm = c->resultbgm;
	Enter = c->enter;
	ChipSe1 = c->chipse1;
	ChipSe2 = c->chipse2;
	DiceSe = c->dicese1;
	CardSe = c->cardse1;
	BurstSe = c->burstse;
	WinSe = c->winse;
	LoseSe = c->losese;
	DrawSe = c->drawse;
}
void FLOW::update(NUMBER* number, PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice,
	CPU_CARD* cpu_card,CPU_CHIP* cpu_chip, CPU_DICE* cpu_dice,STATE*state,FADE*fade) {
	player_chip->player_chipdraw(number);
	cpu_chip->cpu_chipdraw(number);
	player_dice->player_dicedraw(number);
	player_card->player_carddraw(number, player_dice);
	cpu_card->cpu_carddraw1();
	drawImage(cpu_card->S_Card, S_CardPx, S_CardPy);
	drawImage(cpu_dice->S_Dice, S_DicePx, S_DicePy);


	switch (FlowState) {

		//�Q�[���X�^�[�g
	case GAMESTART:
		drawImage(FlowImg[0], FlowPx, FlowPy);
		player_chip->HaveChip = 0;
		cpu_chip->HaveChip = 0;
		if (isTrigger(KEY_Z)) {
			FlowState = GIVECHIP;
			playSound(Enter);
		}
		break;

		//�`�b�v��z��
	case GIVECHIP:
		drawImage(FlowImg[1], FlowPx, FlowPy);
		for (int i = 0; i < HaveChipRoop; i++) {
			if (i % HaveChipRoop != 0) {
				continue;
			}
			if (player_chip->HaveChip < MaxHaveChip) {
				player_chip->HaveChip += one;
				cpu_chip->HaveChip += one;
				playSound(ChipSe1);
			}
		}
		if (player_chip->HaveChip == MaxHaveChip && cpu_chip->HaveChip == MaxHaveChip) {
			if (isTrigger(KEY_Z)) {
				//state->RoundCnt++;
				playSound(Enter);
				FlowState = ROUND;
			}
		}
		break;

		//������
	case ROUND:
		//������
		player_dice->player_dicenew();
		player_card->player_cardnew();
		cpu_dice->cpu_dicenew();
		cpu_card->cpu_cardnew();
		BurstCnt = 0;
		cpu_card->BurstCnt = 0;
		Cnt = 0;
		HaveCnt = 0;
		AddChipCnt = 0;
		DisCpuCnt = 0;
		DisPlayerCnt = 0;
		Difference = 0;
		CpuAddCnt = 0;
		CpuAddChip = 0;
		//��
		number->Value =state->RoundCnt;
		number->NumberPx = CountNumberPx;
		number->NumberPy = CountNumberPy;
		number->m_numberdraw();
		//�摜
		drawImage(FlowImg[2],FlowImgPx2, FlowPy);
		if (isTrigger(KEY_Z)) { FlowState = PAYCHIP; }
		break;
		//�`�b�v���x����
	case PAYCHIP:
		drawImage(FlowImg[3], FlowImgPx3, FlowPy);
		if (Cnt == 0) {
			while (Cnt < MinGiveChip) {
				player_chip->HaveChip -= one;
				player_chip->GiveChip += one;
				cpu_chip->HaveChip -= one;
				cpu_chip->GiveChip += one;
				playSound(ChipSe2);
				Cnt++;
			}
		}
		else {
			HaveCnt = player_chip->HaveChip;
			if (isTrigger(KEY_Z)) {
				Cnt = 0;
				playSound(Enter);
				FlowState = SHAKEDICE;
			}
		}
		break;
		//�_�C�X��U��
	case SHAKEDICE:
		drawImage(FlowImg[4], FlowPx, FlowPy);
		player_dice->player_diceupdate();
		cpu_dice->cpu_diceupdate();
		playSound(DiceSe);
		if (player_dice->DiceCnt == 2) {
			if (isTrigger(KEY_Z)) {
				FlowState = PULLCARD;
				playSound(Enter);
			}
		}
		break;
		//�J�[�h��������
	case PULLCARD:
		drawImage(FlowImg[5], FlowPx, FlowPy);
		drawImage(YesImg, YesPx,YesPy);
		drawImage(NoImg, NoPx, NoPy);
		//�͂�
		if (isTrigger(KEY_LEFT)) {
			Cnt = 0;
			playSound(Enter);
		}
		if (Cnt == 0) {
			drawImage(ArrowImg, ArrowPx1, ArrowPy);
			if (isTrigger(KEY_Z)) {
				Cnt = 0;
				playSound(Enter);
				playSound(CardSe);
				FlowState = ADDCARD;

			}
		}
		//������
		if (isTrigger(KEY_RIGHT)) {
			Cnt = 1;
			playSound(Enter);
		}
		if (Cnt == 1) {
			drawImage(ArrowImg, ArrowPx2, ArrowPy);
			if (isTrigger(KEY_Z)) {
				cpu_card->cpu_cardupdate(cpu_dice);
				playSound(Enter);
				Cnt = 0;
				FlowState = ADDCHIP;
			}
		}
		break;
		//�J�[�h�������܂�
	case ADDCARD:
		drawImage(FlowImg[6], FlowPx, FlowPy);
		player_card->player_cardupdate();
		if (isTrigger(KEY_Z)) {
			if (player_dice->DiceSum < player_card->Player_CardTotal) {
				FlowState = BURST;
				playSound(Enter);
				playSound(BurstSe);
			}
			else {
				FlowState = PULLCARD;
				playSound(Enter);
			}
		}
		break;
		//�o�[�X�g���܂���
	case BURST:
		cpu_card->cpu_cardupdate(cpu_dice);
		drawImage(FlowImg[7], FlowPx, FlowPy);
		BurstCnt = 1;
		if (isTrigger(KEY_Z)) {
			FlowState = FIGHT;
			playSound(Enter);
		}
		break;
		//�`�b�v����悹���܂���
	case ADDCHIP:
		drawImage(FlowImg[8], FlowPx, FlowPy);
		drawImage(YesImg, YesPx, YesPy);
		drawImage(NoImg, NoPx, NoPy);

		//�͂�
		if (isTrigger(KEY_LEFT)) {
			Cnt = 0;
			playSound(Enter);
		}
		if (Cnt == 0) {
			drawImage(ArrowImg, ArrowPx1, ArrowPy);
			if (isTrigger(KEY_Z)) {
				playSound(Enter);
				Cnt = 0;
				FlowState = MUCHCHIP;
			}
		}
		//������
		if (isTrigger(KEY_RIGHT)) {
			Cnt = 1;
			playSound(Enter);
		}
		if (Cnt == 1) {
			drawImage(ArrowImg, ArrowPx2, ArrowPy);
			if (isTrigger(KEY_Z)) {
				//����̏�悹--------------------------------
				if (CpuAddCnt == 0) {
					if (cpu_card->BurstCnt == 0) {
						if (getRand() % AddRadam + AddRadam < cpu_card->Cpu_CardTotal) {
							CpuAddChip = getRand() % cpu_chip->HaveChip / DisChip;
							cpu_chip->GiveChip += CpuAddChip;
							cpu_chip->HaveChip -= CpuAddChip;
							CpuAddCnt++;
						}
					}
				}
				//--------------------------------------------
				playSound(Enter);
				Cnt = 0;
				FlowState = DISGAME;
			}
		}
		break;
		//�ǂ̂��炢��悹���܂���
	case MUCHCHIP:
		drawImage(FlowImg[9], FlowPx, FlowPy);
		//�}�C�i�X
		if (AddChipCnt > 0) {
			if (isTrigger(KEY_LEFT)) {
				playSound(Enter);
				AddChipCnt--;
				player_chip->HaveChip++;
				player_chip->GiveChip--;
			}
		}
		//�v���X
		if (AddChipCnt < HaveCnt) {
			if (isTrigger(KEY_RIGHT)) {
				playSound(Enter);
				AddChipCnt++;
				player_chip->HaveChip--;
				player_chip->GiveChip++;
			}
		}
		number->Value = AddChipCnt;
		number->NumberPx = addNumberPx;
		number->NumberPy = addNumberPy;
		drawImage(ArrowImg, ArrowRightPx, ArrowRightPy);//�E
		drawImage(ArrowImg, ArrowLeftPx, ArrowLeftPy, ArrowRad);//��
		number->b_numberdraw();
		if (isTrigger(KEY_Z)) {
			//����̏�悹----------------------------------------
			if (CpuAddCnt == 0) {
				if (cpu_card->BurstCnt == 0) {
					if (getRand() % AddRadam + AddRadam < cpu_card->Cpu_CardTotal) {
						CpuAddChip = getRand() % cpu_chip->HaveChip / DisChip;
						cpu_chip->GiveChip += CpuAddChip;
						cpu_chip->HaveChip -= CpuAddChip;
						CpuAddCnt++;
					}
				}
			}
			//----------------------------------------------------
			FlowState = DISGAME;
			playSound(Enter);
		}
		break;
		//�Q�[������~��܂���
	case DISGAME:
		drawImage(FlowImg[10], FlowPx, FlowPy);
		drawImage(YesImg, YesPx, YesPy);
		drawImage(NoImg, NoPx, NoPy);
		//����̍~��
		if (cpu_dice->DiceSum < CpuDisDice) { DisCpuCnt = 1; }
		//�͂�
		if (isTrigger(KEY_LEFT)) {
			Cnt = 0; 
			playSound(Enter);
		}
		if (Cnt == 0) {
			drawImage(ArrowImg, ArrowPx1, ArrowPy);
			if (DisCpuCnt == 1) {
				//����������ʂ�
				if (isTrigger(KEY_Z)) {
					Cnt = 0;
					FlowState = DRAW;
					playSound(Enter);
				}
			}
			else {
				//������ʂ�
				if (isTrigger(KEY_Z)) {
					DisPlayerCnt = 1;
					Cnt = 0;
					FlowState = LOSE;
					playSound(LoseSe);
					playSound(Enter);
				}
			}
		}
		//������
		if (isTrigger(KEY_RIGHT)) {
			Cnt = 1; 
			playSound(Enter);
		}
		if (Cnt == 1) {
			drawImage(ArrowImg, ArrowPx2, ArrowPy);
			if (isTrigger(KEY_Z)) {
				Cnt = 0;
				FlowState = FIGHT;
				playSound(Enter);
			}
		}
		break;
		//����
	case FIGHT:
		drawImage(FlowImg[11], FlowImgPx11, FlowImgPy11);
		//����̍~��
		if (cpu_dice->DiceSum < CpuDisDice) { DisCpuCnt = 1; }
		//����������ʂ�
		if (player_card->Player_CardTotal == cpu_card->Cpu_CardTotal || BurstCnt == 1 && cpu_card->BurstCnt == 1) {
			if (isTrigger(KEY_Z)) {
				FlowState = DRAW; 
				playSound(Enter);
			}
		}
		//������ʂ�
		else if (player_card->Player_CardTotal > cpu_card->Cpu_CardTotal && BurstCnt == 0 || cpu_card->BurstCnt == 1 || DisCpuCnt == 1) {
			if (isTrigger(KEY_Z)) { 
				FlowState = WIN; 
				playSound(WinSe);
				playSound(Enter);
			}
		}
		//������ʂ�
		else if (player_card->Player_CardTotal < cpu_card->Cpu_CardTotal && cpu_card->BurstCnt == 0 || BurstCnt == 1) {
			if (isTrigger(KEY_Z)) {
				FlowState = LOSE; 
				playSound(LoseSe);
				playSound(Enter);
			}
		}
		break;
		//�������
	case WIN:
		if (Cnt == 0) {
			if (DisCpuCnt == 0) {
				if (player_chip->GiveChip > cpu_chip->GiveChip) {
					Difference = player_chip->GiveChip - cpu_chip->GiveChip;
					if (Difference > cpu_chip->HaveChip) {
						player_chip->HaveChip += cpu_chip->HaveChip;
						player_chip->HaveChip += cpu_chip->GiveChip + player_chip->GiveChip;
						cpu_chip->HaveChip = 0;
						Cnt++;
					}
					else {
						cpu_chip->HaveChip -= Difference;
						player_chip->HaveChip += Difference;
						player_chip->HaveChip += player_chip->GiveChip + cpu_chip->GiveChip;
						Cnt++;
					}
				}
				else {
					player_chip->HaveChip += player_chip->GiveChip + cpu_chip->GiveChip;
					Cnt++;
				}
			}
			else {
				cpu_chip->GiveChip = cpu_chip->GiveChip - DisChip;
				cpu_chip->HaveChip += cpu_chip->GiveChip;
				player_chip->GiveChip = player_chip->GiveChip + DisChip;
				player_chip->HaveChip += player_chip->GiveChip;
				Cnt++;
			}
		}
		cpu_chip->GiveChip = 0;
		player_chip->GiveChip = 0;
		player_dice->player_dicedraw(number);
		player_card->player_carddraw(number, player_dice);
		cpu_dice->cpu_dicedraw(number);
		cpu_card->cpu_carddraw2(number, cpu_dice);
		drawImage(FlowImg[12], FlowPx, FlowImgPy12);
		if (cpu_chip->HaveChip < MinGiveChip) {
			if (isTrigger(KEY_Z)) {
				state->GameState = state->RESULT_STATE;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				state->RoundCnt = 0;
				playSound(WinSe);
				playSound(Enter);
				FlowState = GAMESTART;
			}
				break;
		}
		if (state->RoundCnt == 4) {
			if (isTrigger(KEY_Z)) { 
				state->GameState = state->RESULT_STATE;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				state->RoundCnt = 0;
				playSound(WinSe);
				playSound(Enter);
				FlowState = GAMESTART;
			}
			break;
		}
		else {
			if (isTrigger(KEY_Z)) {
				state->RoundCnt++;
				playSound(Enter);
				FlowState = ROUND;
			}
			break;
		}
		break;

		//�������
	case LOSE:
		if (Cnt == 0) {
			if (DisPlayerCnt == 0) {
				if (cpu_chip->GiveChip > player_chip->GiveChip) {
					Difference = cpu_chip->GiveChip - player_chip->GiveChip;
					if (Difference > player_chip->HaveChip) {
						cpu_chip->HaveChip += player_chip->HaveChip;
						cpu_chip->HaveChip += player_chip->GiveChip + cpu_chip->GiveChip;
						player_chip->HaveChip = 0;
						Cnt++;
					}
					else {
						player_chip->HaveChip -= Difference;
						cpu_chip->HaveChip += Difference;
						cpu_chip->HaveChip += player_chip->GiveChip + cpu_chip->GiveChip;
						Cnt++;
					}
				}
				else {
					cpu_chip->HaveChip += player_chip->GiveChip + cpu_chip->GiveChip;
					Cnt++;
				}
			}
			else {
				player_chip->GiveChip = player_chip->GiveChip - 2;
				player_chip->HaveChip += player_chip->GiveChip;
				cpu_chip->GiveChip = cpu_chip->GiveChip + 2;
				cpu_chip->HaveChip += cpu_chip->GiveChip;
				Cnt++;
			}
		}
		cpu_chip->GiveChip = 0;
		player_chip->GiveChip = 0;
		player_dice->player_dicedraw(number);
		player_card->player_carddraw(number, player_dice);
		cpu_dice->cpu_dicedraw(number);
		cpu_card->cpu_carddraw2(number, cpu_dice);
		drawImage(FlowImg[13], FlowImgPx13, FlowImgPy13);
		if (player_chip->HaveChip < 3) {
			if (isTrigger(KEY_Z)) {
				state->GameState = state->RESULT_STATE;
				state->RoundCnt = 0;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				playSound(Enter);
				playSound(LoseSe);
				FlowState = GAMESTART;
			}
			break;
		}
		if (state->RoundCnt == 4) {
			if (isTrigger(KEY_Z)) {
				state->GameState = state->RESULT_STATE;
				state->RoundCnt = 0;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				playSound(LoseSe);
				playSound(Enter);
				FlowState = GAMESTART;
			}
			break;
		}
		else {
			if (isTrigger(KEY_Z)) {
				state->RoundCnt++;
				playSound(Enter);
				FlowState = ROUND;
			}
			break;
		}
		break;

		//�����������
	case DRAW:
		cpu_chip->GiveChip = 0;
		player_chip->GiveChip = 0;
		player_dice->player_dicedraw(number);
		player_card->player_carddraw(number, player_dice);
		cpu_dice->cpu_dicedraw(number);
		cpu_card->cpu_carddraw2(number, cpu_dice);

		drawImage(FlowImg[14], FlowPx, FlowImgPy14);
		if (player_chip->HaveChip < 3) {
			if (isTrigger(KEY_Z)) {
				state->GameState = state->RESULT_STATE;
				state->RoundCnt = 0;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				playSound(Enter);
				playSound(DrawSe);
				FlowState = GAMESTART;
			}
			break;
		}
		if (state->RoundCnt == 4) {
			if (isTrigger(KEY_Z)) { 
				state->GameState = state->RESULT_STATE;
				state->RoundCnt = 0;
				stopSound(state->GameBgm);
				playLoopSound(state->ResultBgm);
				playSound(DrawSe);
				playSound(Enter);
				FlowState = GAMESTART;
			}
		}

		else {
			if (isTrigger(KEY_Z)) {
				state->RoundCnt++;
				playSound(Enter);
				FlowState = ROUND;
			}
		}
		break;
	}
}