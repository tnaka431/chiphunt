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
	//------------------------------------------------
	int num = TITLE_state;
	int Flow = gamestart;

	int cnt = 0;

	//ゲームの流れ
	/*int nagare0 = loadImage("0_チップを配ります.png");
	int nagare1 = loadImage("1_チップ支払う.png");
	int nagare2 = loadImage("2_サイコロを振ります.png");
	int nagare3 = loadImage("3_カードを引きますか.png");
	int nagare4 = loadImage("4_カードを加えます.png");
	int nagare5 = loadImage("5_バーストしました.png");
	int nagare6 = loadImage("6_上乗せしますか.png");
	int nagare7 = loadImage("7_どのくらいしますか.png");
	int nagare8 = loadImage("8_勝負から降りますか.png");
	int yazirusi = loadImage("矢印1.png");

	float Ypx = 820.0f;
	int ycnt = 0;
	int nagarecnt = 1;*/
	//------------------------------------------------
	setRandSeed();
	while (msgProc()) {
		getInput();
		clearTarget(COLOR(0.0f, 0.255f, 0.0f));
		switch (num) {

		case TITLE_state:
			title->titledraw(c);
			if (isTrigger(KEY_Z)) {
				num = RULE_state;
			}
			break;

		case RULE_state:
			rule->ruledraw(c);
			if (isTrigger(KEY_Z)) {
				num = PLAY_state;
				//トランプ
				cnt = 0;
				//trumpnumber = 0;
				//hyouzicard = 0;
				//cardgoukei = 0;
				player_card->CardCnt = 0;
				//ダイス
				player_dice->DiceCnt = 0;
				//ゲームの流れ
			}
			break;

		case PLAY_state:
			play->playdraw(number);
			player_chip->player_chipdraw(number);
			player_dice->player_diceupdate();
			player_dice->player_dicedraw(number);
			player_card->player_cardupdate();
			player_card->player_carddraw(number);
			cpu_chip->cpu_chipdraw(number);
			cpu_dice->cpu_diceupdate();
			cpu_dice->cpu_dicedraw(number);
			cpu_card->cpu_cardupdate();
			cpu_card->cpu_carddraw2(number);
			//drawImage(nagare0, 450.0f, 250.0f);
			/*switch(Flow) {
			case gamestart:

				break;
			case paychip:
				break;
			case round:
				break;
			case shakedice:
				break;
			case disgame_1:
				break;
			case pullcard:
				break;
			case addcard:
				break;
			case burst:
				break;
			case addchip:
				break;
			case muchchip:
				break;
			case disgame_2:
				break;
			case fight:
				break;
			case win:
				break;
			case lose:
				break;
			case draw:
				break;
			}*/

			break;
		case RESULT_state:
			result->resultdraw();
			if (isTrigger(KEY_Z)) {
				num = TITLE_state;
			}
			break;
		}
		present();
	}

}