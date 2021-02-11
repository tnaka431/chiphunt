#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"COLOR.h"
void FADE::init(CONTAINER* c) {
	FadeImg = c->backscreen;
}
void FADE::fadein() {
	drawImage(FadeImg,x, y,z, COLOR(r, g, b, Alpha));
	if (Alpha <= MaxAlpha) {
		Alpha += DAlpha;
	}
}
void FADE::fadeout() {
	drawImage(FadeImg,x, y, z, COLOR(r, g, b, Alpha));
	if (Alpha >= MinAlpha) {
		Alpha -= DAlpha;
	}
}