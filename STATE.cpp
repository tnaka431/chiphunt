#include "graphic.h"
#include "window.h"
#include "framework.h"
#include "rand.h"
#include "input.h"
#include "COLOR.h"
#include"CONTAINER.h"
#include"TITLE.h"
#include"RULE.h"
#include"PLAY.h"
#include"NUMBER.h"
#include"PLAYER_CHIP.h"
#include"PLAYER_DICE.h"
#include"PLAYER_CARD.h"
#include"CPU_CHIP.h"
#include"CPU_DICE.h"
#include"CPU_CARD.h"
#include"RESULT.h"
#include"STATE.h"
#include"FLOW.h"
#include"GAME.h"

void STATE::init(CONTAINER* c) {
	for (int i = 0; i < 15; i++) {
		FlowImg[i] = c->flowimg[i];
	}
	FlowPx = c->flowpx;
	FlowPy = c->flowpy;
	ArrowImg = c->arrowimg;
	ArrowPx1 = c->arrow1px;
	ArrowPx2 = c->arrow2px;
	ArrowPy = c->arrowpy;
	//仮
	TitleBgm = c->titlebgm;
	GameBgm = c->gamebgm;
	ResultBgm = c->resultbgm;
	Enter = c->enter;
	winse = c->winse;
	losese = c->losese;
}
void STATE::update(CONTAINER*c,TITLE*title,RULE*rule,PLAY*play,RESULT*result,NUMBER* number, PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice, CPU_CARD* cpu_card, CPU_CHIP* cpu_chip, CPU_DICE* cpu_dice,FLOW*flow,STATE*state,GAME*game) {
	switch (State) {
		//タイトル画面
		case TITLE_STATE:
			title->titledraw(c);
			if (isTrigger(KEY_Z)) {
				playSound(Enter);
				State = RULE_STATE; }
			break;
		//ルール画面
		case RULE_STATE:
			//play内の初期化
			player_dice->player_dicenew();
			player_card->player_cardnew();
			cpu_dice->cpu_dicenew();
			cpu_card->cpu_cardnew();
			flow->GAMESTART;
			//ルール説明
			if (isTrigger(KEY_LEFT)) { 
				playSound(Enter);
				Cnt = 0; 
			}
			if (Cnt == 0) { 
				rule->ruledraw1(c);
				drawImage(ArrowImg, ArrowPx1+1000.0f, ArrowPy+300.0f);
			}
			if (isTrigger(KEY_RIGHT)) {
				playSound(Enter);
				Cnt = 1; 
			}
			if (Cnt == 1) {
				rule->ruledraw2(c);
				drawImage(ArrowImg, ArrowPx1-650.0f, ArrowPy+300.0f,3.14f);
			}
			if (isTrigger(KEY_Z)) {
				State = PLAY_STATE; 
				playSound(Enter);
				stopSound(TitleBgm);
				playLoopSound(GameBgm);
			}
			break;

		//プレイ画面
		case PLAY_STATE:
			play->playdraw(number);
			flow->update(number,player_card,player_chip,player_dice,cpu_card,cpu_chip,cpu_dice,state);
			break;

		//リザルト画面
		case RESULT_STATE:
			result->resultdraw();
			result->playerscore(number);
			result->cpuscore(number);
			result->PlayerScore = player_chip->HaveChip;
			result->CpuScore = cpu_chip->HaveChip;
			Cnt = 0;

			if (result->PlayerScore > result->CpuScore) {
				drawImage(FlowImg[12], FlowPx + 50.0f, FlowPy + 130.0f);
			}
			else if (result->PlayerScore < result->CpuScore) {
				drawImage(FlowImg[13], FlowPx + 70.0f, FlowPy + 200.0f);
			}
			else {
			drawImage(FlowImg[14], FlowPx+50.0f, FlowPy +200.0f);
			}
			if (isTrigger(KEY_Z)) { 
				State = TITLE_STATE;
				playSound(Enter);
				stopSound(ResultBgm);
				playLoopSound(TitleBgm);
				Cnt = 0;
			}
			break;
		}
}