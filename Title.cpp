#include"graphic.h"
#include "TITLE.h"
#include"CONTAINER.h"


void TITLE::titleinit(CONTAINER* c) {
	TitleImg = c->titleimg;
	StartImg = c->startimg;
	px = c->titlepx;
	py = c->titlepy;
}
void TITLE::titledraw(CONTAINER* c) {
	drawImage(TitleImg, px, py);
	drawImage(StartImg, StartPx, StartPy);
}