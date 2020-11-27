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
	DiceNumberPx = c->playerdicenumber_px;
	DiceNumberPy = c->playerdicenumber_py;
}
void PLAYER_DICE::player_diceupdate() {
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
		drawImage(DiceImg[Dice[i]], DicePx + 100.0f * i, DicePy);

	}
	for (int i = 3; i < 5; i++) {
		drawImage(DiceImg[Dice[i]], (DicePx + 50.0f) + 100.0f * (i - 3), (DicePy + 100.0f));
	}
	//ƒ_ƒCƒX‚Ì”
	num->NumberPx = 1550.0f;
	num->NumberPy = DiceNumberPy;
	DiceSum = Deme[0] + Deme[1] + Deme[2] + Deme[3] + Deme[4] + 5;
	num->Value = DiceSum;
	num->s_numberdraw();
	
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