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
#include"sound.h"
#include"FLOW.h"
#include"STATE.h"

#include"FADE.h"


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
	flow = new FLOW;
	state = new STATE;
	fade = new FADE;
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
	flow->init(c);
	state->init(c);

	fade->init(c);

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
	delete flow;
	delete state;

	delete fade;
 }


void GAME::Proc() {

	playLoopSound(state->TitleBgm);
	setRandSeed();
	while (msgProc()) {
		getInput();
		clearTarget();
	
		//clearTarget(COLOR(0.0f, 0.255f, 0.0f));
		state->update(c, title, rule, play, result, number, player_card, player_chip, player_dice, cpu_card, cpu_chip, cpu_dice, flow, state,game,fade);
		present();
	}

}
	/*/仮
	int hai = loadImage("「はい」.png");
	int iie = loadImage("「いいえ」.png");
	int motichip = loadImage("持ちチップの数.png");
	int bachip = loadImage("場のチップ.png");
	int cardsu = loadImage("カードの合計値.png");
	int dicesu = loadImage("出目の合計数.png");
	int titlebgm = loadSound("タイトルBGM.wav");
	int gamebgm = loadSound("ゲームBGM.wav");
	int dicese1 = loadSound("サイコロSE1.wav");
	int dicese2 = loadSound("サイコロSE2.wav");
	int chipse1 = loadSound("チップSE1.wav");
	int chipse2 = loadSound("チップSE2.wav");
	int enter = loadSound("決定ボタンSE.wav");*/
	//playLoopSound(titlebgm);
		/*switch (State) {
		//タイトル画面
		case TITLE_STATE:
			title->titledraw(c);
			if (isTrigger(KEY_Z)) {
				playSound(enter);
				State = RULE_STATE; }
			break;
		//ルール画面
		case RULE_STATE:
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
			if (isTrigger(KEY_LEFT)) { 
				playSound(enter);
				Cnt = 0; 
			}
			if (Cnt == 0) { 
				rule->ruledraw1(c);
				drawImage(ArrowImg, ArrowPx1+1000.0f, ArrowPy+300.0f);
			}
			if (isTrigger(KEY_RIGHT)) {
				playSound(enter);
				Cnt = 1; 
			}
			if (Cnt == 1) {
				rule->ruledraw2(c);
				drawImage(ArrowImg, ArrowPx1-650.0f, ArrowPy+300.0f,3.14f);
			}
			if (isTrigger(KEY_Z)) {
				State = PLAY_STATE; 
				playSound(enter);
				stopSound(titlebgm);
				playLoopSound(gamebgm);
			}
			break;

		//プレイ画面
		case PLAY_STATE:
			play->playdraw(number);
			flow->update(number,player_card,player_chip,player_dice,cpu_card,cpu_chip,cpu_dice);
			break;

		//リザルト画面
		case RESULT_STATE:
			result->resultdraw();
			result->playerscore(number);
			result->cpuscore(number);
			result->PlayerScore = player_chip->HaveChip;
			result->CpuScore = cpu_chip->HaveChip;
			Cnt = 0;

			if (result->PlayerScore > result->CpuScore) {
				drawImage(FlowImg[12], FlowPx, FlowPy + 130.0f);
			}
			else if (result->PlayerScore < result->CpuScore) {
			drawImage(FlowImg[13], FlowPx + 20.0f, FlowPy +140.0f);
			}
			else {
			drawImage(FlowImg[14], FlowPx, FlowPy +125.0f);
			}
			if (isTrigger(KEY_Z)) { State = TITLE_STATE; }
			break;
		}*/



			/*player_chip->player_chipdraw(number);
			cpu_chip->cpu_chipdraw(number);
			player_dice->player_dicedraw(number);
			player_card->player_carddraw(number, player_dice);
			cpu_card->cpu_carddraw1();
			//仮
			drawImage(motichip, 0.0f, 210.0f);
			drawImage(motichip, 0.0f, 800.0f);
			drawImage(bachip, 0.0f, 400.0f);
			drawImage(bachip, 0.0f, 600.0f);
			drawImage(cardsu, 700.0f, 210.0f);
			drawImage(cardsu, 700.0f, 800.0f);
			drawImage(dicesu, 1500.0f, 210.0f);
			drawImage(dicesu, 1500.0f, 800.0f);
			
			switch (Flow) {

			//ゲームスタート
			case GAMESTART:
				drawImage(FlowImg[0], FlowPx, FlowPy);
				if (isTrigger(KEY_Z)) { 
					Flow = GIVECHIP; 
					playSound(enter);
				}
				break;

			//チップを配る
			case GIVECHIP:
				drawImage(FlowImg[1], FlowPx, FlowPy);
				for (int i = 0; i < 10; i++) {
					if (i % 10 != 0) {
						continue;
					}
					if (player_chip->HaveChip < 30) {
						player_chip->HaveChip += 1;
						cpu_chip->HaveChip += 1;
						playSound(chipse1);
					}
				}
				if (player_chip->HaveChip == 30 && cpu_chip->HaveChip == 30) {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						playSound(enter);
						Flow = ROUND;
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
				number->Value = RoundCnt;
				number->NumberPx = 650.0f;
				number->NumberPy = 470.0f;
				number->b_numberdraw();
				//画像
				drawImage(FlowImg[2], FlowPx+200.0f, FlowPy);
				if (isTrigger(KEY_Z)) { Flow = PAYCHIP; }
				break;
			//チップを支払う
			case PAYCHIP:
				drawImage(FlowImg[3], FlowPx, FlowPy);
				if (Cnt == 0) {
					while (Cnt < 3) {
						player_chip->HaveChip -= 1;
						player_chip->GiveChip += 1;
						cpu_chip->HaveChip -= 1;
						cpu_chip->GiveChip += 1;
						playSound(chipse2);
						Cnt++;
					}
				}
				else {
					HaveCnt = player_chip->HaveChip;
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						playSound(enter);
						Flow = SHAKEDICE;
					}
				}
				break;
			//ダイスを振る
			case SHAKEDICE:
				drawImage(FlowImg[4], FlowPx, FlowPy);
				player_dice->player_diceupdate();
				cpu_dice->cpu_diceupdate();
				playSound(dicese1);
				if (player_dice->DiceCnt == 2) {
					if (isTrigger(KEY_Z)) {
						Flow = PULLCARD; 
						playSound(enter);
					}
				}
				break;
			//カードを引くか
			case PULLCARD:
				drawImage(FlowImg[5], FlowPx, FlowPy);
				//はい
				if (isTrigger(KEY_LEFT)) { 
					Cnt = 0; 
					playSound(enter);
				}
				if (Cnt == 0) {
					drawImage(ArrowImg, ArrowPx1, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = ADDCARD;

					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { 
					Cnt = 1; 
					playSound(enter);
				}
				if (Cnt == 1) {
					drawImage(ArrowImg, ArrowPx2, ArrowPy);
					if (isTrigger(KEY_Z)) {
						cpu_card->cpu_cardupdate(cpu_dice);
						Cnt = 0;
						Flow = ADDCHIP;
					}
				}
				break;
			//カードを引きます
			case ADDCARD:
				drawImage(FlowImg[6], FlowPx, FlowPy);
				player_card->player_cardupdate();
				if (isTrigger(KEY_Z)) {
					if (player_dice->DiceSum < player_card->Player_CardTotal) {
						Flow = BURST;
						playSound(enter);
					}
					else {
						Flow = PULLCARD;
						playSound(enter);
					}
				}
				break;
			//バーストしました
			case BURST:
				cpu_card->cpu_cardupdate(cpu_dice);
				drawImage(FlowImg[7], FlowPx, FlowPy);
				BurstCnt = 1;
				if (isTrigger(KEY_Z)) { 
					Flow = FIGHT; 
					playSound(enter);
				}
				break;
			//チップを上乗せしますか
			case ADDCHIP:
				drawImage(FlowImg[8], FlowPx, FlowPy);
				drawImage(hai, 800.0f, 650.0f);
				drawImage(iie, 1080.0f, 650.0f);

				//はい
				if (isTrigger(KEY_LEFT)) {
					Cnt = 0; 
					playSound(enter);
				}
				if (Cnt == 0) {
					drawImage(ArrowImg, ArrowPx1, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = MUCHCHIP;
					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { 
					Cnt = 1; 
					playSound(enter);
				}
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
						Flow = DISGAME;
					}
				}
				break;
			//どのくらい上乗せしますか
			case MUCHCHIP:
				drawImage(FlowImg[9], FlowPx, FlowPy);
				//マイナス
				if (AddChipCnt > 0) {
					if (isTrigger(KEY_LEFT)) {
						playSound(enter);
						AddChipCnt--;
						player_chip->HaveChip++;
						player_chip->GiveChip--;
					}
				}
				//プラス
				if (AddChipCnt < HaveCnt) {
					if (isTrigger(KEY_RIGHT)) {
						playSound(enter);
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
					Flow = DISGAME;
					playSound(enter);
				}
				break;
			//ゲームから降りますか
			case DISGAME:
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
							Flow = DRAW;
						}
					}
					else {
						//負け画面へ
						if (isTrigger(KEY_Z)) {
							DisPlayerCnt = 1;
							Cnt = 0;
							Flow = LOSE;
						}
					}
				}
				//いいえ
				if (isTrigger(KEY_RIGHT)) { Cnt = 1; }
				if (Cnt == 1) {
					drawImage(ArrowImg, ArrowPx2, ArrowPy);
					if (isTrigger(KEY_Z)) {
						Cnt = 0;
						Flow = FIGHT;
					}
				}
				break;
			//勝負
			case FIGHT:
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
				//引き分け画面へ
				if (player_card->Player_CardTotal == cpu_card->Cpu_CardTotal || BurstCnt == 1 && cpu_card->BurstCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = DRAW; }
				}
				//勝ち画面へ
				else if (player_card->Player_CardTotal > cpu_card->Cpu_CardTotal && BurstCnt == 0 || cpu_card->BurstCnt == 1 || DisCpuCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = WIN; }
				}
				//負け画面へ
				else if (player_card->Player_CardTotal < cpu_card->Cpu_CardTotal && cpu_card->BurstCnt == 0 || BurstCnt == 1) {
					if (isTrigger(KEY_Z)) { Flow = LOSE; }
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
						State = RESULT_STATE;
					}
				}
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_STATE; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = ROUND;
					}
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
				drawImage(FlowImg[13], FlowPx + 20.0f, FlowPy - 40.0f);
				if (player_chip->HaveChip < 3) {
					if (isTrigger(KEY_Z)) {
						State = RESULT_STATE;
					}
				}
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_STATE; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = ROUND;
					}
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

				drawImage(FlowImg[14], FlowPx, FlowPy - 25.0f);
				if (RoundCnt == 5) {
					if (isTrigger(KEY_Z)) { State = RESULT_STATE; }
				}
				else {
					if (isTrigger(KEY_Z)) {
						RoundCnt++;
						Flow = ROUND;
					}
				}
				break;
			}*/