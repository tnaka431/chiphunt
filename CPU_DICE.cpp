#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"CPU_DICE.h"
#include"NUMBER.h"


void CPU_DICE::cpu_diceinit(CONTAINER* c) {
	for (int i = 0; i < 6; i++) {
		DiceImg[i] = c->diceimg[i];
	}
	DicePx = c->cpudice_px;
	DicePy = c->cpudice_py;
	S_Dice = c->dice;
}
void CPU_DICE::cpu_diceupdate() {
	switch (cnt){
	case one:
		if (isTrigger(KEY_Z)) {
			DiceSum = Deme[0] + Deme[1] + Deme[2] + Deme[3] + Deme[4] + DiceNumber;
			cnt = four;
		}
		break;
	case two:
		if (isTrigger(KEY_Z)) {
			cnt = three;
		}
		break;
	case three:
		for (int i = 0; i < DiceEye; i++) {
			Dice[i] = getRand() % DiceEye;
			Deme[i] = Dice[i];
			cnt = one;
		}
	case four:
		break;
	}
}

void CPU_DICE::cpu_dicedraw(NUMBER* num) {
	for (int i = 0; i < DiceUpNumber; i++) {
		drawImage(DiceImg[Dice[i]], DicePx + Interval * i, DicePy);

	}
	for (int i = DiceUpNumber; i < DiceNumber; i++) {
		drawImage(DiceImg[Dice[i]], (DicePx + halfInterval) + Interval * (i - 3), (DicePy + Interval));
	}
	//ダイスの数
	num->NumberPx = 1770.0f;//直入力以外だと０になる
	num->NumberPy = DiceNumberPy;
	num->Value = DiceSum;
	num->s_numberdraw();

}
void CPU_DICE::cpu_dicenew() {
	for (int i = 0; i < DiceEye; i++) {
		Dice[i] = 0;
	}
	for (int i = 0; i < DiceNumber; i++) {
		Deme[i] = 0;
	}
	DiceSum = 0;
	cnt = two;
}