#include"graphic.h"
#include"Rule.h"
#include"BOX.h"

void RULE::ruleinit(box* b) {
	RuleImg = b->ruleimg;
	px = b->px;
	py = b->py;
}
//void updateRule(RULE_DATA* th) {}
void RULE::ruledraw(box* b) {
	drawImage(RuleImg, px, py, 0.0f);
	drawImage(b->startimg, px, py + 500.0f, 0.0f);
}