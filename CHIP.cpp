#include "CONTAINER.h"
#include"NUMBER.h"
#include"CHIP.h"
#include "graphic.h"

void CHIP::init(CONTAINER* c) {
	ChipImg = c->chipimg;
}
void CHIP::update() {
}
void CHIP::draw(NUMBER*num) {
	drawImage(ChipImg, ChipPx,ChipPy);
	//持ちチップの数
	num->NumberPx = HavePx;
	num->NumberPy = HavePy;
	num->Value = HaveChip;
	num->s_numberdraw();
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = GivePx;
	num->NumberPy = GivePy;
	num->s_numberdraw();
}
int CHIP::havechip() { return HaveChip; };
int CHIP::givechip() { return GiveChip; };
float CHIP::chippx() { return ChipPx; };
float CHIP::chippy() { return ChipPy; };
float CHIP::havepx() { return HavePx; }; 
float CHIP::havepy() { return HavePy; };
float CHIP::givepx() { return GivePx; };
float CHIP::givepy() { return GivePy; };

