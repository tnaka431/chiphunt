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
	//音
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

		//ゲームスタート
	case GAMESTART:
		drawImage(FlowImg[0], FlowPx, FlowPy);
		player_chip->HaveChip = 0;
		cpu_chip->HaveChip = 0;
		if (isTrigger(KEY_Z)) {
			FlowState = GIVECHIP;
			playSound(Enter);
		}
		break;

		//チップを配る
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

		//何回戦目
	case ROUND:
		//初期化
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
		//仮
		number->Value =state->RoundCnt;
		number->NumberPx = CountNumberPx;
		number->NumberPy = CountNumberPy;
		number->m_numberdraw();
		//画像
		drawImage(FlowImg[2],FlowImgPx2, FlowPy);
		if (isTrigger(KEY_Z)) { FlowState = PAYCHIP; }
		break;
		//チップを支払う
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
		//ダイスを振る
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
		//カードを引くか
	case PULLCARD:
		drawImage(FlowImg[5], FlowPx, FlowPy);
		drawImage(YesImg, YesPx,YesPy);
		drawImage(NoImg, NoPx, NoPy);
		//はい
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
		//いいえ
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
		//カードを引きます
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
		//バーストしました
	case BURST:
		cpu_card->cpu_cardupdate(cpu_dice);
		drawImage(FlowImg[7], FlowPx, FlowPy);
		BurstCnt = 1;
		if (isTrigger(KEY_Z)) {
			FlowState = FIGHT;
			playSound(Enter);
		}
		break;
		//チップを上乗せしますか
	case ADDCHIP:
		drawImage(FlowImg[8], FlowPx, FlowPy);
		drawImage(YesImg, YesPx, YesPy);
		drawImage(NoImg, NoPx, NoPy);

		//はい
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
		//いいえ
		if (isTrigger(KEY_RIGHT)) {
			Cnt = 1;
			playSound(Enter);
		}
		if (Cnt == 1) {
			drawImage(ArrowImg, ArrowPx2, ArrowPy);
			if (isTrigger(KEY_Z)) {
				//相手の上乗せ--------------------------------
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
		//どのくらい上乗せしますか
	case MUCHCHIP:
		drawImage(FlowImg[9], FlowPx, FlowPy);
		//マイナス
		if (AddChipCnt > 0) {
			if (isTrigger(KEY_LEFT)) {
				playSound(Enter);
				AddChipCnt--;
				player_chip->HaveChip++;
				player_chip->GiveChip--;
			}
		}
		//プラス
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
		drawImage(ArrowImg, ArrowRightPx, ArrowRightPy);//右
		drawImage(ArrowImg, ArrowLeftPx, ArrowLeftPy, ArrowRad);//左
		number->b_numberdraw();
		if (isTrigger(KEY_Z)) {
			//相手の上乗せ----------------------------------------
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
		//ゲームから降りますか
	case DISGAME:
		drawImage(FlowImg[10], FlowPx, FlowPy);
		drawImage(YesImg, YesPx, YesPy);
		drawImage(NoImg, NoPx, NoPy);
		//相手の降り
		if (cpu_dice->DiceSum < CpuDisDice) { DisCpuCnt = 1; }
		//はい
		if (isTrigger(KEY_LEFT)) {
			Cnt = 0; 
			playSound(Enter);
		}
		if (Cnt == 0) {
			drawImage(ArrowImg, ArrowPx1, ArrowPy);
			if (DisCpuCnt == 1) {
				//引き分け画面へ
				if (isTrigger(KEY_Z)) {
					Cnt = 0;
					FlowState = DRAW;
					playSound(Enter);
				}
			}
			else {
				//負け画面へ
				if (isTrigger(KEY_Z)) {
					DisPlayerCnt = 1;
					Cnt = 0;
					FlowState = LOSE;
					playSound(LoseSe);
					playSound(Enter);
				}
			}
		}
		//いいえ
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
		//勝負
	case FIGHT:
		drawImage(FlowImg[11], FlowImgPx11, FlowImgPy11);
		//相手の降り
		if (cpu_dice->DiceSum < CpuDisDice) { DisCpuCnt = 1; }
		//引き分け画面へ
		if (player_card->Player_CardTotal == cpu_card->Cpu_CardTotal || BurstCnt == 1 && cpu_card->BurstCnt == 1) {
			if (isTrigger(KEY_Z)) {
				FlowState = DRAW; 
				playSound(Enter);
			}
		}
		//勝ち画面へ
		else if (player_card->Player_CardTotal > cpu_card->Cpu_CardTotal && BurstCnt == 0 || cpu_card->BurstCnt == 1 || DisCpuCnt == 1) {
			if (isTrigger(KEY_Z)) { 
				FlowState = WIN; 
				playSound(WinSe);
				playSound(Enter);
			}
		}
		//負け画面へ
		else if (player_card->Player_CardTotal < cpu_card->Cpu_CardTotal && cpu_card->BurstCnt == 0 || BurstCnt == 1) {
			if (isTrigger(KEY_Z)) {
				FlowState = LOSE; 
				playSound(LoseSe);
				playSound(Enter);
			}
		}
		break;
		//勝ち画面
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

		//負け画面
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

		//引き分け画面
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