#include "graphic.h"
#include"NUMBER.h"
#include"CONTAINER.h"

void NUMBER::numberinit(CONTAINER* c) {
	for (int i = 0; i < 10; i++) {
		 NumberImg[i]= c->numberimg[i];
	}
	Kurai = c->kurai;
}
void NUMBER::numberdraw() {
	Kurai = 10;
	for (int i = 0; i < 2; i++) {
		Vol = Value / Kurai;
		drawImage(NumberImg[Vol], NumberPx + 20.0f * i, NumberPy);
		Value %= Kurai;
		Kurai /= 10;
	}
}