#include<stdio.h>
#include "graphic.h"
#include "window.h"
#include "framework.h"
#include "rand.h"
#include "input.h"
#include "COLOR.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"RULE.h"
#include"PLAY.h"
#include"NUMBER.h"
#include"PLAYER_CHIP.h"
#include"PLAYER_DICE.h"
#include"PLAYER_CARD.h"
#include"CPU_CHIP.h"
#include"CPU_DICE.h"
#include"CPU_CARD.h"
#include"RESULT.h"
#include"GAME.h"
#define TITLE_state 0
#define RULE_state 1
#define PLAY_state 2
#define RESULT_state 3 

#define gamestart 0 
#define givechip  1
#define round     2
#define paychip   3
#define shakedice 4 
#define pullcard  5
#define addcard   6
#define burst     7
#define addchip   8
#define muchchip  9
#define disgame   10
#define fight     11
#define win       12
#define lose      13
#define draw      14

GAME::GAME(){
	c = new CONTAINER;
	title = new TITLE;
	rule = new RULE;
	play = new PLAY;
	number = new NUMBER;
	player_chip = new PLAYER_CHIP;
	player_dice = new PLAYER_DICE;
	player_card = new PLAYER_CARD;
	cpu_chip = new CPU_CHIP;
	cpu_dice = new CPU_DICE;
	cpu_card = new CPU_CARD;
	result = new RESULT;
	for (int i = 0; i < 15; i++) {
		FlowImg[i] = c->flowimg[i];
	}
	FlowPx = c->flowpx;
	FlowPy = c->flowpy;
	ArrowImg = c->arrowimg;
	ArrowPx1 = c->arrow1px;
	ArrowPx2 = c->arrow2px;
	ArrowPy = c->arrowpy;
}
GAME::~GAME(){
	delete c;
	delete title;
	delete rule;
	delete play;
	delete number;
	delete player_chip ;
	delete player_dice ;
	delete player_card ;
	delete cpu_chip ;
	delete cpu_dice ;
	delete cpu_card ;
	delete result ;
}


void GAME::Proc() {
	title->titleinit(c);
	rule->ruleinit(c);
	play->playinit(c);
	number->numberinit(c);
	player_chip->player_chipinit(c);
	player_dice->player_diceinit(c);
	player_card->player_cardinit(c);
	cpu_chip->cpu_chipinit(c);
	cpu_dice->cpu_diceinit(c);
	cpu_card->cpu_cardinit(c);
	result->resultinit(c);
	//仮
	int hai = loadImage("「はい」.png");
	int iie = loadImage("「いいえ」.png");
	setRandSeed();
	while (msgProc()) {
		getInput();
		clearTarget(COLOR(0.0f, 0.255f, 0.0f));
		switch (State) {
		//タイトル画面
		case TITLE_state:
			title->titledraw(c);
			if (isTrigger(KEY_Z)) { State = RESULT_state; }
			break;
		//ルール画面
		case RULE_state:
			//play内の初期化
			player_dice->player_dicenew();
			player_card->player_cardnew();
			cpu_dice->cpu_dicenew();
			cpu_card->cpu_cardnew();
			player_chip->HaveChip = 0;
			cpu_chip->HaveChip = 0;
			RoundCnt = 0;
			Flow = 0;
			//ルール説明
			if (isTrigger(KEY_LEFT)) { Cnt = 0; }
			if (Cnt == 0) { 
				rule->ruledraw1(c);
				drawImage(ArrowImg, ArrowPx1+1000.0f, ArrowPy+300.0f);
			}
			if (isTrigger(KEY_RIGHT)) { Cnt = 1; }
			if (Cnt == 1) {
				rule->ruledraw2(c);
				drawImage(ArrowImg, ArrowPx1-650.0f, ArrowPy+300.0f,3.14f);
			}
			if (isTrigger(KEY_Z)) { State = PLAY_state; }
			break;

		//プレイ画面
		case PLAY_state:
			play->playdraw(number);
			player_chip->player_chipdraw(number);
			cpu_chip->cpu_chipdraw(number);
			player_dice->player_dicedraw(number);
			player_card->player_carddraw(number, player_dice);
			cpu_card->cpu_carddraw1();
			switch (Flow) {

			//ゲームスタート
			case gamestart:
				drawImage(FlowImg[0], FlowPx, FlowPy);
				if (isTrigger(KEY_Z)) { Flow = givechip; }
				break;

			//チップを配る
			case givechip:
				drawImage(FlowImg[1], FlowPx, FlowPy);
				for (int i = 0; i < 10; i++) {
					if (i % 10 != 0) {
						continue;
					}
					if (player_chip->HaveChip < 30) {
						player_chip->HaveChip += 1;
						cpu_chip->HaveChip += 1;
					}
				}
				if (player_chip->HaveChip == 30 && cpu_chip->HaveChip == 30) {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = round;
					}
				}
				break;

			//何回戦目
			case round:
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
				number->Value = RoundCnt;
				number->NumberPx = 650.0f;
				number->NumberPy = 470.0f;
				number->b_numberdraw();
				//画像
				drawImage(FlowImg[2], FlowPx+200.0f, FlowPy);
				if (isTrigger(KEY_Z)) { Flow = paychip; }
				break;
			//チップを支払う
			case paychip:
				drawImage(FlowImg[3], FlowPx, FlowPy);
				if (Cnt == 0) {
					while (Cnt < 3) {
						player_chip->HaveChip -= 1;
						player_chip->GiveChip += 1;
						cpu_chip->HaveChip -= 1;
						cpu_chip->GiveChip += 1;
						Cnt++;
					}
				}
				else {
					HaveCnt = player_chip->HaveChip;
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = shakedice;
					}
				}
				break;
			//ダイスを振る
			case shakedice:
				drawImage(FlowImg[4], FlowPx, FlowPy);
				player_dice->player_diceupdate();
				cpu_dice->cpu_diceupdate();
				if (player_dice->DiceCnt == 2) {
					if (isTrigger(KEY_Z)) { Flow = pullcard; }
				}
				break;
			//カードを引くか
			case pullcard:
				drawImage(FlowImg[5], FlowPx, FlowPy);
				//はい
				if (isTrigger(KEY_LEFT)) { Cnt = 0; }
				if (Cnt == 0) {
					drawImage(ArrowImg, ArrowPx1, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = addcard;

					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { Cnt = 1; }
				if (Cnt == 1) {
					drawImage(ArrowImg, ArrowPx2, ArrowPy);
					if (isTrigger(KEY_Z)) {
						cpu_card->cpu_cardupdate(cpu_dice);
						Cnt = 0;
						Flow = addchip;
					}
				}
				break;
			//カードを引きます
			case addcard:
				drawImage(FlowImg[6], FlowPx, FlowPy);
				player_card->player_cardupdate();
				if (isTrigger(KEY_Z)) {
					if (player_dice->DiceSum < player_card->Player_CardTotal) {
						Flow = burst;
					}
					else {
						Flow = pullcard;
					}
				}
				break;
			//バーストしました
			case burst:
				cpu_card->cpu_cardupdate(cpu_dice);
				drawImage(FlowImg[7], FlowPx, FlowPy);
				BurstCnt = 1;
				if (isTrigger(KEY_Z)) { Flow = fight; }
				break;
			//チップを上乗せしますか
			case addchip:
				drawImage(FlowImg[8], FlowPx, FlowPy);
				drawImage(hai, 800.0f, 650.0f);
				drawImage(iie, 1080.0f, 650.0f);

				//はい
				if (isTrigger(KEY_LEFT)) { Cnt = 0; }
				if (Cnt == 0) {
					drawImage(ArrowImg, ArrowPx1, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = muchchip;
					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { Cnt = 1; }
				if (Cnt == 1) {
					drawImage(ArrowImg, ArrowPx2, ArrowPy);
					if (isTrigger(KEY_Z)) {
						//相手の上乗せ--------------------------------
						if (CpuAddCnt == 0) {
							if (cpu_card->BurstCnt == 0) {
								if (getRand() % 15 + 15 < cpu_card->Cpu_CardTotal) {
									CpuAddChip = getRand() % cpu_chip->HaveChip / 2;
									cpu_chip->GiveChip += CpuAddChip;
									cpu_chip->HaveChip -= CpuAddChip;
									CpuAddCnt++;
								}
							}
						}
						//--------------------------------------------
						Cnt = 0;
						Flow = disgame;
					}
				}
				break;
			//どのくらい上乗せしますか
			case muchchip:
				drawImage(FlowImg[9], FlowPx, FlowPy);
				//マイナス
				if (AddChipCnt > 0) {
					if (isTrigger(KEY_LEFT)) {
						AddChipCnt--;
						player_chip->HaveChip++;
						player_chip->GiveChip--;
					}
				}
				//プラス
				if (AddChipCnt < HaveCnt) {
					if (isTrigger(KEY_RIGHT)) {
						AddChipCnt++;
						player_chip->HaveChip--;
						player_chip->GiveChip++;
					}
				}
				number->Value = AddChipCnt;
				number->NumberPx = 800.0f;
				number->NumberPy = 550.0f;
				drawImage(ArrowImg, ArrowPx2-30.0f, ArrowPy-60.0f);
				drawImage(ArrowImg, ArrowPx1, ArrowPy-50.0f, 3.14f);
				number->b_numberdraw();
				if (isTrigger(KEY_Z)) {
					//相手の上乗せ----------------------------------------
					if (CpuAddCnt == 0) {
						if (cpu_card->BurstCnt == 0) {
							if (getRand() % 15 + 15< cpu_card->Cpu_CardTotal) {
								CpuAddChip = getRand() % cpu_chip->HaveChip / 2;
								cpu_chip->GiveChip += CpuAddChip;
								cpu_chip->HaveChip -= CpuAddChip;
								CpuAddCnt++;
							}
						}
					}
					//----------------------------------------------------
					Flow = disgame;
				}
				break;
			//ゲームから降りますか
			case disgame:
				drawImage(FlowImg[10], FlowPx, FlowPy);
				drawImage(hai, 800.0f, 650.0f);
				drawImage(iie, 1080.0f, 650.0f);
				//相手の降り
				if (cpu_dice->DiceSum < 10) { DisCpuCnt = 1; }
				//はい
				if (isTrigger(KEY_LEFT)) { Cnt = 0; }
				if (Cnt == 0) {
					drawImage(ArrowImg, ArrowPx1, ArrowPy);
					if (DisCpuCnt == 1) {
						//引き分け画面へ
						if (isTrigger(KEY_Z)) {
							Cnt = 0;
							Flow = draw;
						}
					}
					else {
						//負け画面へ
						if (isTrigger(KEY_Z)) {
							DisPlayerCnt = 1;
							Cnt = 0;
							Flow = lose;
						}
					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { Cnt = 1; }
				if (Cnt == 1) {
					drawImage(ArrowImg, ArrowPx2, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = fight;
					}
				}
				break;
			//勝負
			case fight:
				drawImage(FlowImg[11], FlowPx - 70.0f, FlowPy - 40.0f);
				//相手の降り
				if (cpu_dice->DiceSum < 10) { DisCpuCnt = 1; }
				//相手の上乗せ
				if (CpuAddCnt == 0) {
					if (cpu_card->BurstCnt == 0) {
						if (getRand() % 15 + 15 < cpu_card->Cpu_CardTotal) {
							CpuAddChip = getRand()%cpu_chip->HaveChip/2;
							cpu_chip->GiveChip += CpuAddChip;
							cpu_chip->HaveChip -= CpuAddChip;
							CpuAddCnt++;
						}
					}
				}
				number->Value = CpuAddChip;
				number->NumberPy = 500.0f;
				number->NumberPx = 200.0f;
				number->s_numberdraw();
				//引き分け画面へ
				if (player_card->Player_CardTotal == cpu_card->Cpu_CardTotal || BurstCnt == 1 && cpu_card->BurstCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = draw; }
				}
				//勝ち画面へ
				else if (player_card->Player_CardTotal > cpu_card->Cpu_CardTotal && BurstCnt == 0 || cpu_card->BurstCnt == 1 || DisCpuCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = win; }
				}
				//負け画面へ
				else if (player_card->Player_CardTotal < cpu_card->Cpu_CardTotal && cpu_card->BurstCnt == 0 || BurstCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = lose; }
				}
				break;
			//勝ち画面
			case win:
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
						cpu_chip->GiveChip = cpu_chip->GiveChip-2;
						cpu_chip->HaveChip += cpu_chip->GiveChip;
						player_chip->GiveChip = player_chip->GiveChip+2;
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
				drawImage(FlowImg[12], FlowPx, FlowPy - 100.0f);
				if (cpu_chip->HaveChip < 3) {
					if (isTrigger(KEY_Z)) {
						State = RESULT_state;
					}
				}
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_state; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = round;
					}
				}
				break;

			//負け画面
			case lose:
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
				drawImage(FlowImg[13], FlowPx + 20.0f, FlowPy - 40.0f);
				if (player_chip->HaveChip < 3) {
					if (isTrigger(KEY_Z)) {
						State = RESULT_state;
					}
				}
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_state; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = round;
					}
				}
				break;

			//引き分け画面
			case draw:
				cpu_chip->GiveChip = 0;
				player_chip->GiveChip = 0;
				player_dice->player_dicedraw(number);
				player_card->player_carddraw(number, player_dice);
				cpu_dice->cpu_dicedraw(number);
				cpu_card->cpu_carddraw2(number, cpu_dice);

				drawImage(FlowImg[14], FlowPx, FlowPy - 25.0f);
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_state; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = round;
					}
				}
				break;
			}

			break;

		//リザルト画面
		case RESULT_state:
			result->resultdraw();
			result->playerscore(number);
			result->cpuscore(number);
			result->PlayerScore = player_chip->HaveChip;
			result->CpuScore = cpu_chip->HaveChip;

			if (result->PlayerScore > result->CpuScore) {
				drawImage(FlowImg[12], FlowPx, FlowPy + 130.0f);
			}
			else if (result->PlayerScore < result->CpuScore) {
			drawImage(FlowImg[13], FlowPx + 20.0f, FlowPy +140.0f);
			}
			else {
			drawImage(FlowImg[14], FlowPx, FlowPy +125.0f);
			}
			if (isTrigger(KEY_Z)) { State = TITLE_state; }
			break;
		}
		present();
	}

}