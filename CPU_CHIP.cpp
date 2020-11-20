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
	num->NumberPx = Cpu_HChipPx;
	num->NumberPy = Cpu_HChipPy;
	num->Value = HaveChip;
	num->numberdraw();
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = Cpu_FChipPx;
	num->NumberPy = Cpu_FChipPy;
	num->numberdraw();
}