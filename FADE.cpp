#include"CONTAINER.h"
#include"FADE.h"
#include"graphic.h"
#include"COLOR.h"
void FADE::init(CONTAINER* c) {
	FadeImg = c->backscreen;

}
void FADE::fadein() {
	drawImage(FadeImg, 960.0f, 540.0f, 0.0f, COLOR(0.0f, 0.0f, 0.0f, Alpha));
	if (Alpha <= 1.0f) {
		Alpha += 0.07f;
	}
}
void FADE::fadeout() {
	drawImage(FadeImg, 960.0f, 540.0f, 0.0f, COLOR(0.0f, 0.0f, 0.0f, Alpha));
	if (Alpha >= 0.0f) {
		Alpha -= 0.07f;
	}
}