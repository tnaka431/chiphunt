#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"PLAYER_DICE.h"
#include"NUMBER.h"


void PLAYER_DICE::player_diceinit(CONTAINER* c) {
	for (int i = 0; i < 6; i++) {
		DiceImg[i] = c->diceimg[i];
	}
	DicePx = c->playerdice_px;
	DicePy = c->playerdice_py;
	DiceSe1 = c->dicese1;
	S_Dice = c->dice;
}
void PLAYER_DICE::player_diceupdate() {
		//playSound(DiceSe1);
	if(DiceCnt == 1) {
		if (isTrigger(KEY_Z)) {
			DiceCnt = 2;
		}
	}
	if (DiceCnt == 0) {
		if (isTrigger(KEY_Z)) {
			DiceCnt = 1;
		}
	}

	if (DiceCnt == 1) {
		for (int i = 0; i < 6; i++) {
			Dice[i] = getRand() % 6;
			Deme[i] = Dice[i];
		}
	}
	
}
void PLAYER_DICE::player_dicedraw(NUMBER*num) {
	for (int i = 0; i < 3; i++) {
		drawImage(DiceImg[Dice[i]], DicePx + Interval * i, DicePy);

	}
	for (int i = 3; i < 5; i++) {
		drawImage(DiceImg[Dice[i]], (DicePx + halfInterval) + Interval * (i - 3), (DicePy + Interval));
	}
	//ダイスの数
	num->NumberPx = DiceNumberPx;
	num->NumberPy = DiceNumberPy;
	DiceSum = Deme[0] + Deme[1] + Deme[2] + Deme[3] + Deme[4] + 5;
	num->Value = DiceSum;
	num->s_numberdraw();
	drawImage(S_Dice, 1500.0f, 800.0f);
}
void PLAYER_DICE::player_dicenew() {
	for (int i = 0; i < 6; i++) {
		Dice[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		Deme[i] = 0;
	}
	DiceCnt = 0;
	DiceSum = 0;
}