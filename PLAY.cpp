#include "graphic.h"
#include"input.h"
#include"PLAY.h"
#include "CONTAINER.h"
#include"NUMBER.h"


void PLAY::playinit(CONTAINER* c) {
	PlayImg = c->playimg;
	Px = c->px;
	Py = c->py;
}

void PLAY::playdraw(NUMBER*num){
	drawImage(PlayImg, Px, Py);
}