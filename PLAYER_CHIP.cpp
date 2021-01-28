#include"graphic.h"
#include"CONTAINER.h"
#include"PLAYER_CHIP.h"
#include "NUMBER.h"
void PLAYER_CHIP::player_chipinit(CONTAINER*c) {
	RedChipImg = c->r_chipimg;
	BlackChipImg = c->b_chipimg;
	ChipImgPx = c->p_chipimg_px;
	ChipImgPy = c->p_chipimg_py;
	HaveChipPx = c->p_havechip_px;
	HaveChipPy = c->p_havechip_py;
	GiveChipPx = c->p_givechip_px;
	GiveChipPy = c->p_givechip_py;
	S_HaveChip = c->havechip;
	S_GiveChip = c->givechip;
}
void PLAYER_CHIP::player_chipdraw(NUMBER*num) {
	drawImage(S_HaveChip, 0.0f, 820.0f);
	drawImage(S_GiveChip, 0.0f, 530.0f);
	//持ちチップの数
	num->NumberPx = HaveChipPx;
	num->NumberPy = HaveChipPy;
	num->Value = HaveChip;
	num->s_numberdraw();
	B_HaveChip = HaveChip / 5;
	R_HaveChip = HaveChip % 5;
	for (int i = 0; i < B_HaveChip; i++) {
		drawImage(BlackChipImg,ChipImgPx - 5*i,ChipImgPy-5*i);
	}
	if (R_HaveChip != 0) {
		for (int i = 0; i < R_HaveChip; i++) {
			drawImage(RedChipImg, ChipImgPx + 200 - 5 * i, ChipImgPy - 5 * i);
		}
	}
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = GiveChipPx;
	num->NumberPy = GiveChipPy;
	num->s_numberdraw();
	B_GiveChip = GiveChip / 5;
	R_GiveChip = GiveChip % 5;
	for (int i = 0; i < B_GiveChip; i++) {
		drawImage(BlackChipImg, ChipImgPx - 5 * i, ChipImgPy-270 - 5 * i);
	}
	if (R_GiveChip != 0) {
		for (int i = 0; i < R_GiveChip; i++) {
			drawImage(RedChipImg, ChipImgPx + 200 - 5 * i, ChipImgPy-270 - 5 * i);
		}
	}
}
/*void PLAYER_CHIP::init(CONTAINER* c) {
};
void PLAYER_CHIP::update(CONTAINER* c) {
	ChipPx = c->cpuchip_px;
	ChipPy = c->cpuchip_py;
	HavePx = c->cpuhavechip_px;
	HavePy = c->cpuhavechip_py;
	GivePx = c->cpufieldchip_px;
	GivePy = c->cpufieldchip_py;
	HaveChip=0;
	GiveChip=0;
}
void PLAYER_CHIP::draw(NUMBER* num) {
};*/