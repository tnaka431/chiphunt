#include "graphic.h"
#include "window.h"
#include "framework.h"
#include "input.h"
#include"COLOR.h"
#include<stdio.h>
#include"Title.h"
#include"Rule.h"
#include"box.h"
#include "rand.h"
#include "Gameplay.h"
#define TITLE_state 0
#define RULE_state 1
#define PLAY_state 2
#define RESULT_state 3




void gmain() {
	box b;
	TITLE title;
	RULE rule;
	GAMEPLAY gameplay;

	title.titleinit(&b);
	rule.ruleinit(&b);
	gameplay.gameplayinit(&b);

	int num = TITLE_state;
	int backscreen = loadImage("black.png");
	int exp= loadImage("rule3.png");

	float back = 1.0f;
	int cnt = 0;
	//トランプ
	int tp[52] = { 0 };
	int Img = loadImage("トランプ横列.png");
	int number = 0;
	int p[13] = {0};
	int i = 0;
	int maisu = 0;
	//サイコロ
	int dice1[6] = { loadImage("Dice_1.png"),loadImage("Dice_2.png"),loadImage("Dice_3.png"),loadImage("Dice_4.png"),loadImage("Dice_5.png"),loadImage("Dice_6.png") };
	int a = 0;
	int dai[6] = {0};
	int daicnt = 0;


	setRandSeed();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			tp[j+i*13] = divideImage(Img, 111+140*j, 13+196*i, 121, 180);
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
			drawImage(exp, b.px, b.py, 0.0f);
			drawImage(backscreen, b.px, b.py, 0.0f, COLOR(0.0f, 0.0f, 0.0f, back));
			back -= 0.01f;
			if (isTrigger(KEY_Z)) {
				num = PLAY_state;
				back = 1.0f;
				cnt = 0;
				i = 0;
				maisu = 0;
				daicnt=0;
				//dai[6] = { 0 };
			}
			break;

		case PLAY_state:
			gameplay.gameplayerdraw();

			//トランプ
			if (daicnt == 2) {
				if (isTrigger(KEY_Z)) {
					number = getRand() % 52;
					maisu++;
					p[i] = tp[number];
					i++;
					cnt++;
				}
				for (int i = 0; i < 13; i++) {
					if (maisu > i) { drawImage(p[i], 500.0f + 50.0f * i, 900.0f); }
				}
			}

			
			//サイコロ
			if (daicnt == 1) {
				if (isTrigger(KEY_Z)) {
					daicnt = 2;
				}
			}
			if (daicnt == 0) {
				if (isTrigger(KEY_Z)) {
					daicnt = 1;
				}
			}

			if (daicnt==1) {
					for (int i = 0; i < 6; i++) {
						dai[i] = getRand() % 6;
					}
			}
			for (int i = 0; i < 3; i++) {
				drawImage(dice1[dai[i]], 1550.0f + 100.0f * i, 850.0f);
			}
			for (int i = 0; i < 2; i++) {
				drawImage(dice1[dai[i]], 1600.0f + 100.0f * i, 950.0f);
			}


			if (cnt ==15) {
				if (isTrigger(KEY_Z)) {
					num = TITLE_state;
					back = 1.0f;
				}
			}
			break;

		case RESULT_state:
			drawImage(backscreen, b.px, b.py, 0.0f, COLOR(0.0f, 0.0f, 0.0f, back));
			back -= 0.01f;
			if (isTrigger(KEY_Z)) {
				num = TITLE_state;
				back = 1.0f;
			}
			break;
		}
		present();
	}

}