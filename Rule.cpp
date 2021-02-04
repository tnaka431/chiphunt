#include"graphic.h"
#include"RULE.h"
#include "COLOR.h"
#include"CONTAINER.h"

void RULE::ruleinit(CONTAINER* c) {
	RuleImg1 = c->ruleimg1;
	RuleImg2 = c->ruleimg2;
	px = c->px;
	py = c->py;
}
void RULE::ruledraw1(CONTAINER* c) {
	drawImage(RuleImg1, px, py);
	drawImage(c->startimg, StartPx,StartPy);
}
void RULE::ruledraw2(CONTAINER* c) {
	drawImage(RuleImg2, px, py);
	drawImage(c->startimg, StartPx,StartPy);
}