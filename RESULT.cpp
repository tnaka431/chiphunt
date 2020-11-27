#include"graphic.h"
#include"CONTAINER.h"
#include"RESULT.h"
#include"NUMBER.h"

void RESULT::resultinit(CONTAINER* c) {
	ResultImg = c->resultimg;
	Px = c->resultpx;
	Py = c->resultpy;
	PlayerScorePx = c->playerscore_px;
	PlayerScorePy = c->playerscore_py;
	CpuScorePx = c->cpuscore_px;
	CpuScorePy = c->cpuscore_py;
}

void RESULT::resultdraw() {drawImage(ResultImg, Px, Py);}

void RESULT::playerscore(NUMBER* num) {
	num->NumberPx = PlayerScorePx;
	num->NumberPy = PlayerScorePy;
	num->Value = PlayerScore;
	num->b_numberdraw();
}

void RESULT::cpuscore(NUMBER* num) {
	num->NumberPx = CpuScorePx;
	num->NumberPy = CpuScorePy;
	num->Value = CpuScore;
	num->b_numberdraw();
}