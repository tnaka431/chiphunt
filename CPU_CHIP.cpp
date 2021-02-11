#include"graphic.h"
#include"CONTAINER.h"
#include"CPU_CHIP.h"
#include"NUMBER.h"
void CPU_CHIP::cpu_chipinit(CONTAINER* c) {
	RedChipImg = c->r_chipimg;
	BlackChipImg = c->b_chipimg;
	RedChipPx = c->c_rchipimg_px;
	RedChipPy = c->c_rchipimg_py;
	BlackChipPx = c->c_bchipimg_px;
	BlackChipPy = c->c_bchipimg_py;
	HaveChipPx = c->c_havechip_px;
	HaveChipPy = c->c_havechip_py;
	GiveChipPx = c->c_givechip_px;
	GiveChipPy = c->c_givechip_py;
	S_HaveChip = c->havechip;
	S_GiveChip = c->givechip;
	
}
void CPU_CHIP::cpu_chipdraw(NUMBER*num) {
	drawImage(S_HaveChip,StringChipPx,StringHChipPy);
	drawImage(S_GiveChip,StringChipPx, StringGChipPy);
	//持ちチップの数
	num->NumberPx = HaveChipPx;
	num->NumberPy = HaveChipPy;
	num->Value = HaveChip;
	num->s_numberdraw();
	B_HaveChip = HaveChip / Divided;
	R_HaveChip = HaveChip % Divided;
	for (int i = 0; i < B_HaveChip; i++) {
		drawImage(BlackChipImg, BlackChipPx -( Divided * i), BlackChipPy -( Divided * i));
	}
	if (R_HaveChip != 0) {
		for (int i = 0; i < R_HaveChip; i++) {
			drawImage(RedChipImg, RedChipPx -( Divided * i), RedChipPy - (Divided * i));
		}
	}
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = GiveChipPx;
	num->NumberPy = GiveChipPy;
	num->s_numberdraw();
	B_GiveChip = GiveChip / Divided;
	R_GiveChip = GiveChip % Divided;
	for (int i = 0; i < B_GiveChip; i++) {
		drawImage(BlackChipImg, BlackChipPx - (Divided * i), GiveChipImgpy-( Divided * i));
	}
	if (R_GiveChip != 0) {
		for (int i = 0; i < R_GiveChip; i++) {
			drawImage(RedChipImg, RedChipPx - (Divided * i), GiveChipImgpy - (Divided * i));
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