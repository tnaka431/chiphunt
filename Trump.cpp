#include "graphic.h"
#include "Trump.h"
#include"input.h"
#include "rand.h"

void TRUMP_DATA::tpinit(TRUMP_DATA*t) {
	t->alltp = loadImage("ƒgƒ‰ƒ“ƒv.png");
	t->y = 13.0f;
	int i = 0;
	t->cnt = 0;
	/*while (i < 12) {
		t->tp[i] = divideImage(t->alltp, 111.0f + 140.0f * i, t->y, 121.0f, 180.0f);
		i++;
	}
	while (i < 25) {
		t->tp[i] = divideImage(t->alltp, 111.0f + 140.0f * (i % 13), t->y + 196.0f, 121.0f, 180.0f);
		i++;
	}
	while (i < 38) {
		t->tp[i] = divideImage(t->alltp, 111.0f + 140.0f * (i % 13), t->y + 196.0f * 2, 121.0f, 180.0f);
		i++;
	}
	while (i < 51) {
		t->tp[i] = divideImage(t->alltp, 111.0f + 140.0f * (i % 13), t->y + 196.0f * 3, 121.0f, 180.0f);
		i++;
	}*/

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			tp[j + i * 13] = divideImage(t->alltp, 111.0f + 140 * j, 13.0f + 196.0f * i, 121.0f, 180.0f);
		}
	}

}

void TRUMP_DATA::tpupdate(TRUMP_DATA* t) {
	if (isTrigger(KEY_Z)) {
		t->ransu = getRand() % 52;
		//t->cnt += 1;

	}
}
/*void tpdraw() {
	t->cnt = 0;
	for (int j = 0; j < 51; j++) {
		if (j == t->ransu) {
			//if (t->cnt==0) {
			drawImage(t->tp[j], 960.0f, 540.0f, 0.0f);
			//t->cnt++;
		//}
		//if (t->cnt==1) {
			//drawImage(t->tp[t->ransu], 960.0f + 200.0f, 540.0f, 0.0f);
		//}
		}
	}
	//drawImage(t->tp[t->ransu], 960.0f + 200.0f, 540.0f, 0.0f);

}*/

void TRUMP_DATA::drawtrump(TRUMP_DATA* t, int number) {
	drawImage(t->tp[number], 960.0f, 540.0f);
}