#include "graphic.h"
#include"Gameplay.h"
#include "box.h"

void GAMEPLAY::gameplayinit(box* b) {
	GamePlayImg = b->gameplayimg;
	Chip = b->chip;
	Px = b->px;
	Py = b->py;
	PlayerPx = b->playerpx;
	PlayerPy = b->playerpy;
	PcPx = b->pcpx;
	PcPy = b->pcpy;
}
void GAMEPLAY::gameplayerdraw(){
	drawImage(GamePlayImg, Px, Py,0.0f);
	drawImage(Chip, PlayerPx, PlayerPy,0.0f);
	drawImage(Chip, PcPx , PcPy , 0.0f);
}