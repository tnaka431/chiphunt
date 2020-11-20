#include"graphic.h"
#include"CONTAINER.h"
#include"RESULT.h"

void RESULT::resultinit(CONTAINER* c) {
	ResultImg = c->resultimg;
	Px = c->resultpx;
	Py = c->resultpy;
}
void RESULT::resultdraw() {
	drawImage(ResultImg, Px, Py);
}
