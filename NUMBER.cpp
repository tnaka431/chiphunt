#include "graphic.h"
#include"NUMBER.h"
#include"CONTAINER.h"

void NUMBER::numberinit(CONTAINER* c) {
	for (int i = 0; i < 10; i++) { S_NumberImg[i] = c->s_numberimg[i]; }
	for (int j = 0; j < 10; j++) { B_NumberImg[j] = c->b_numberimg[j]; }
	Kurai = c->kurai;
}
void NUMBER::s_numberdraw() {
	Kurai = 10;
	for (int i = 0; i < 2; i++) {
		Vol = Value / Kurai;
		drawImage(S_NumberImg[Vol], NumberPx + 20.0f * i, NumberPy);
		Value %= Kurai;
		Kurai /= 10;
	}
}
void NUMBER::b_numberdraw() {
	Kurai = 10;
	for (int i = 0; i < 2; i++) {
		Vol = Value / Kurai;
		drawImage(B_NumberImg[Vol], NumberPx + 80.0f * i, NumberPy);
		Value %= Kurai;
		Kurai /= 10;
	}
}
//’†‚­‚ç‚¢‚ÌˆêŒ…”Žš