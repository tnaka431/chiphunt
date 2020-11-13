#include "graphic.h"
#include"Gameplay.h"
#include "box.h"

void GAMEPLAY::gameplayinit(box* b) {
	GamePlayImg = b->gameplayimg;
	Clip = b->clip;
	Px = b->px;
	Py = b->py;
	PlayerPx = b->playerpx;
	PlayerPy = b->playerpy;
	PcPx = b->pcpx;
	PcPy = b->pcpy;
}
void GAMEPLAY::gameplayerdraw(){
	drawImage(GamePlayImg, Px, Py,0.0f);
	drawImage(Clip, PlayerPx, PlayerPy,0.0f);
	drawImage(Clip, PcPx , PcPy , 0.0f);
}