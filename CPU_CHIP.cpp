#include"graphic.h"
#include"CONTAINER.h"
#include"CPU_CHIP.h"
#include"NUMBER.h"
void CPU_CHIP::cpu_chipinit(CONTAINER* c) {
	ChipImg = c->chipimg;
	Cpu_ChipPx = c->cpuchip_px;
	Cpu_ChipPy = c->cpuchip_py;
	Cpu_HChipPx = c->cpuhavechip_px;
	Cpu_HChipPy = c->cpuhavechip_py;
	Cpu_FChipPx = c->cpufieldchip_px;
	Cpu_FChipPy = c->cpufieldchip_py;
	
}
void CPU_CHIP::cpu_chipdraw(NUMBER*num) {
	drawImage(ChipImg, Cpu_ChipPx, Cpu_ChipPy);
	//持ちチップの数
	num->NumberPx = 300.0f;
	num->NumberPy = 220.0f;
	num->Value = HaveChip;
	num->s_numberdraw();
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = 260.0f;
	num->NumberPy = 410.0f;
	num->s_numberdraw();
};
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