#include"graphic.h"
#include"CONTAINER.h"
#include"PLAYER_CHIP.h"
#include "NUMBER.h"
void PLAYER_CHIP::player_chipinit(CONTAINER*c) {
	ChipImg = c->chipimg;
	Player_ChipPx = c->playerchip_px;
	Player_ChipPy = c->playerchip_py;
	Player_HChipPx = c->playerhavechip_px;
	Player_HChipPy = c->playerhavechip_py;
	Player_FChipPx = c->playerfieldchip_px;
	Player_FChipPy = c->playerfieldchip_py;
}
void PLAYER_CHIP::player_chipdraw(NUMBER*num) {
	drawImage(ChipImg, Player_ChipPx, Player_ChipPy);
	//持ちチップの数
	num->NumberPx = Player_HChipPx;
	num->NumberPy = Player_HChipPy;
	num->Value = HaveChip;
	num->s_numberdraw();
	//場のチップの数
	num->Value = GiveChip;
	num->NumberPx = Player_FChipPx;
	num->NumberPy = Player_FChipPy;
	num->s_numberdraw();
}