#include"graphic.h"
#include"RULE.h"
#include "COLOR.h"
#include"CONTAINER.h"

void RULE::ruleinit(CONTAINER* c) {
	RuleImg = c->ruleimg;
	ExpImg = c->expimg;
	px = c->px;
	py = c->py;
}
//void updateRule(RULE_DATA* th) {}
void RULE::ruledraw(CONTAINER* c) {
	drawImage(RuleImg, px, py);
	drawImage(ExpImg, px, py);
	drawImage(c->startimg, px+760.0f, py + 980.0f);
	//drawImage(c->backscreen, px, py,0.0f,COLOR(0.0f,0.0f,0.0f,c->back));
}