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
	DiceNumberPx = c->cpudicenumber_px;
	DiceNumberPy = c->cpudicenumber_py;
}
void CPU_DICE::cpu_diceupdate() {
	if (CpuCnt == 1) {

		if (isTrigger(KEY_Z)) {
			DiceSum = Deme[0] + Deme[1] + Deme[2] + Deme[3] + Deme[4] + 5;
			CpuCnt = 2;
		}
	}
	if (CpuCnt == 0) {
		if (isTrigger(KEY_Z)) {
			CpuCnt = 1;
		}
	}

	if (CpuCnt == 1) {
		for (int i = 0; i < 6; i++) {
			Dice[i] = getRand() % 6;
			Deme[i] = Dice[i];
		}
	}
}

void CPU_DICE::cpu_dicedraw(NUMBER* num) {
	for (int i = 0; i < 2; i++) {
		drawImage(DiceImg[Dice[i]], DicePx + 100.0f * i, DicePy);

	}
	for (int i = 2; i < 5; i++) {
		drawImage(DiceImg[Dice[i]], (DicePx + 50.0f) + 100.0f * (i - 3), (DicePy + 100.0f));
	}
	//ƒ_ƒCƒX‚Ì”
	num->NumberPx = 1800.0f;
	num->NumberPy = DiceNumberPy;
	num->Value = DiceSum;
	num->s_numberdraw();

}
void CPU_DICE::cpu_dicenew() {
	for (int i = 0; i < 6; i++) {
		Dice[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		Deme[i] = 0;
	}
	CpuCnt = 0;
	DiceSum = 0;
}