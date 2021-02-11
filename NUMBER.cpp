#include "graphic.h"
#include"NUMBER.h"
#include"CONTAINER.h"

void NUMBER::numberinit(CONTAINER* c) {
	for (int i = 0; i < Number; i++) { S_NumberImg[i] = c->s_numberimg[i]; }
	for (int j = 0; j < Number; j++) { B_NumberImg[j] = c->b_numberimg[j]; }
	for (int i = 0; i < sNumber; i++) { M_NumberImg[i] = c->m_numberimg[i]; }
	//Kurai = c->kurai;
}
void NUMBER::s_numberdraw() {
	Kurai = Zyu;
	for (int i = 0; i < keta; i++) {
		Vol = Value / Kurai;
		drawImage(S_NumberImg[Vol], NumberPx + S_NumberInterval * i, NumberPy);
		Value %= Kurai;
		Kurai /= Zyu;
	}
}
void NUMBER::b_numberdraw() {
	Kurai = Zyu;
	for (int i = 0; i < keta; i++) {
		Vol = Value / Kurai;
		drawImage(B_NumberImg[Vol], NumberPx + B_NumberInterval * i, NumberPy);
		Value %= Kurai;
		Kurai /= Zyu;
	}
}
//’†‚­‚ç‚¢‚ÌˆêŒ…”Žš
void NUMBER::m_numberdraw() {
	Vol = Value;
	drawImage(M_NumberImg[Vol], NumberPx, NumberPy);
}