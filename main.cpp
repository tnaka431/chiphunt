#include "graphic.h"
#include "window.h"
#include "framework.h"
#include "input.h"
#include"COLOR.h"
#include<stdio.h>
#include"Title.h"
#include"Rule.h"
#include"box.h"
#include"Trump.h"
#include "rand.h"
#include"Trump.h"
#include "Gameplay.h"
#define TITLE_state 0
#define RULE_state 1
#define GAME_state 2
#define RESULT_state 3




void gmain() {
	box b;
	TITLE title;
	RULE rule;
	GAMEPLAY gameplay;
	//TRUMP trump;
	TRUMP_DATA trumpdata;

	title.titleinit(&b);
	rule.ruleinit(&b);
	gameplay.gameplayinit(&b);

	int num = TITLE_state;
	int c = loadImage("black.png");
	int f = loadImage("rule3.png");
	int g = loadImage("FIGHT.png");
	int h = loadImage("LOSE.png");
	int i = loadImage("WIN.png");
	int j = loadImage("DRAW.png");
	int o = loadImage("PLAYER-CPU.png");

	//サイコロ読み込み
	int dice[6] = { loadImage("Dice_1.png"),loadImage("Dice_2.png"),loadImage("Dice_3.png"),loadImage("Dice_4.png"),loadImage("Dice_5.png"),loadImage("Dice_6.png") };


	float sc = 1.0f;
	int flag = 0;
	int cnt = 0;
	//int num=0;
	int tp[52] = { 0 };
	//追加分
	int Img = loadImage("トランプ横列.png");
	int work = 0;
	//int number = 0;


	setRandSeed();
	//トランプカード呼び込み
	trumpdata.tpinit(&trumpdata);
	//alltp = loadImage("トランプ.png");

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			tp[j+i*13] = divideImage(Img, 111.0f+140*j, 13.0f+196.0f*i, 121.0f, 180.0f);
		}
	}

	while (msgProc()) {
		getInput();
		clearTarget(COLOR(0.0f, 0.255f, 0.0f));
		int ransu;

		switch (num) {

		case TITLE_state:
			title.titledraw(&b);
			if (isTrigger(KEY_Z)) {
				num = RULE_state;
			}
			break;

		case RULE_state:
			rule.ruledraw(&b);
			drawImage(f, b.px, b.py, 0.0f);
			drawImage(c, b.px, b.py, 0.0f, COLOR(0.0f, 0.0f, 0.0f, sc));
			sc -= 0.01f;
			if (isTrigger(KEY_Z)) {
				num = GAME_state;
				sc = 1.0f;
			}
			break;

		case GAME_state:
			gameplay.gameplayerdraw();

			//tpupdate(&trumpdata);
			//tpdraw(&trumpdata);
			if (isTrigger(KEY_X)) {
				trumpdata.number = getRand() % 52;
				//num = getRand() % 52;
			}
			trumpdata.drawtrump(&trumpdata, trumpdata.number);
			//if (isTrigger(KEY_UP)) { work++; }
			//if (isTrigger(KEY_DOWN)) { if (work > 0) { work--; } }
			//drawImage(tp[work], 500.0f, 500.0f);
			//drawImage(tp[trumpdata.number], 500.0f,500.0f);

			//サイコロ
			//drawImage(dice[0], 1500.0f, 800.0f);
			if (isTrigger(KEY_Z)) {
				num = RESULT_state;
				sc = 1.0f;
			}
			break;

		case RESULT_state:
			drawImage(c, b.px, b.py, 0.0f, COLOR(0.0f, 0.0f, 0.0f, sc));
			sc -= 0.01f;
			if (isTrigger(KEY_Z)) {
				num = TITLE_state;
				sc = 1.0f;
			}
			break;
		}
		present();
	}

}