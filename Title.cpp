#include "Title.h"
#include"graphic.h"
#include"box.h"

/*TITLE::TITLE() {
	TitleImg=0;
	StartImg=0;
	px=0;
	py = 0;
}*/
void TITLE::titleinit(box* b) {
	TitleImg = b->titleimg;
	StartImg = b->startimg;
	px = b->titlepx;
	py = b->titlepy;
}
void TITLE::titledraw(box* b) {
	drawImage(TitleImg, px, py, 0.0f);
	drawImage(StartImg, px, py + 200.0f, 0.0f);
}