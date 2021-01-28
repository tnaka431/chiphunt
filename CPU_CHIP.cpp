#include"graphic.h"
#include"CONTAINER.h"
#include"CPU_CHIP.h"
#include"NUMBER.h"
void CPU_CHIP::cpu_chipinit(CONTAINER* c) {
	RedChipImg = c->r_chipimg;
	BlackChipImg = c->b_chipimg;
	ChipImgPx = c->c_chipimg_px;
	ChipImgPy = c->c_chipimg_py;
	HaveChipPx = c->c_havechip_px;
	HaveChipPy = c->c_havechip_py;
	GiveChipPx = c->c_givechip_px;
	GiveChipPy = c->c_givechip_py;
	S_HaveChip = c->havechip;
	S_GiveChip = c->givechip;
	
}
void CPU_CHIP::cpu_chipdraw(NUMBER*num) {
	drawImage(S_HaveChip, 0.0f, 220.0f);
	drawImage(S_GiveChip, 0.0f, 470.0f);
	//持ちチップの数
	num->NumberPx = 300.0f;
	num->NumberPy = 230.0f;
	num->Value = HaveChip;
	num->s_numberdraw();
	B_HaveChip = HaveChip / 5;
	R_HaveChip = HaveChip % 5;
	for (int i = 0; i < B_HaveChip; i++) {
		drawImage(BlackChipImg, ChipImgPx - 5 * i, ChipImgPy - 5 * i);
	}
	if (R_HaveChip != 0) {
		for (int i = 0; i < R_HaveChip; i++) {
			drawImage(RedChipImg, ChipImgPx + 200 - 5 * i, ChipImgPy - 5 * i);
		}
	}
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = 270.0f;
	num->NumberPy = 485.0f;
	num->s_numberdraw();
	B_GiveChip = GiveChip / 5;
	R_GiveChip = GiveChip % 5;
	for (int i = 0; i < B_GiveChip; i++) {
		drawImage(BlackChipImg, ChipImgPx - 5 * i, ChipImgPy + 260 - 5 * i);
	}
	if (R_GiveChip != 0) {
		for (int i = 0; i < R_GiveChip; i++) {
			drawImage(RedChipImg, ChipImgPx + 200 - 5 * i, ChipImgPy + 260 - 5 * i);
		}
	}
}
/*void CPU_CHIP::init(CONTAINER* c) {
};
void CPU_CHIP::update(CONTAINER* c) {
	ChipPx = c->cpuchip_px;
	ChipPy = c->cpuchip_py;
	HavePx = c->cpuhavechip_px;
	HavePy = c->cpuhavechip_py;
	GivePx = c->cpufieldchip_px;
	GivePy = c->cpufieldchip_py;
}
void CPU_CHIP::draw(NUMBER* num) {
};*/