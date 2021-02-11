#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"PLAYER_DICE.h"
#include"NUMBER.h"


void PLAYER_DICE::player_diceinit(CONTAINER* c) {
	for (int i = 0; i < DiceEye; i++) {
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
		for (int i = 0; i < DiceEye; i++) {
			Dice[i] = getRand() % DiceEye;
			Deme[i] = Dice[i];
		}
	}
	
}
void PLAYER_DICE::player_dicedraw(NUMBER*num) {
	for (int i = 0; i < DiceUpNumber; i++) {
		drawImage(DiceImg[Dice[i]], DicePx + Interval * i, DicePy);

	}
	for (int i = DiceUpNumber; i < DiceNumber; i++) {
		drawImage(DiceImg[Dice[i]], (DicePx + halfInterval) + Interval * (i - 3), (DicePy + Interval));
	}
	//ƒ_ƒCƒX‚Ì”
	num->NumberPx = DiceNumberPx;
	num->NumberPy = DiceNumberPy;
	DiceSum = Deme[0] + Deme[1] + Deme[2] + Deme[3] + Deme[4] + DiceNumber;
	num->Value = DiceSum;
	num->s_numberdraw();
	drawImage(S_Dice, S_DicePx, S_DicePy);
}
void PLAYER_DICE::player_dicenew() {
	for (int i = 0; i < DiceEye; i++) {
		Dice[i] = 0;
	}
	for (int i = 0; i < DiceNumber; i++) {
		Deme[i] = 0;
	}
	DiceCnt = 0;
	DiceSum = 0;
}