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
#include"FADE.h"
#include<stdio.h>


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
	//音
	TitleBgm = c->titlebgm;
	GameBgm = c->gamebgm;
	ResultBgm = c->resultbgm;
	Enter = c->enter;
	winse = c->winse;
	losese = c->losese;

}
void STATE::update(CONTAINER* c, TITLE* title, RULE* rule, PLAY* play, RESULT* result, NUMBER* number,
	PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice, CPU_CARD* cpu_card,
	CPU_CHIP* cpu_chip, CPU_DICE* cpu_dice, FLOW* flow, STATE* state, GAME* game, FADE* fade) {
	switch (State) {
		//タイトル画面
	case TITLE_STATE:
		title->titledraw(c);
		if (fade->FadeCnt == 1) { fade->fadein(); }
		if (fade->Alpha >= 1.0f) {
			fade->FadeCnt = 0;
			State = RULE_STATE;
		}
		if (isTrigger(KEY_Z)) {
			playSound(Enter);
			fade->FadeCnt = 1;
		}
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
		if (isTrigger(KEY_Z)) {
			fade->FadeCnt = 1;
			playSound(Enter);
			stopSound(TitleBgm);
			playLoopSound(GameBgm);
		}
		if (isTrigger(KEY_LEFT)) {
			playSound(Enter);
			Cnt = 0;
		}
		if (Cnt == 0) {
			rule->ruledraw1(c);
			drawImage(ArrowImg, ArrowRightPx, ArrowRightPy);
			if (fade->FadeCnt == 0) { fade->fadeout(); }
		}
		if (isTrigger(KEY_RIGHT)) {
			playSound(Enter);
			Cnt = 1;
		}
		if (Cnt == 1) {
			rule->ruledraw2(c);
			drawImage(ArrowImg, ArrowLeftPx, ArrowLeftPy, ArrowRad);
			if (fade->FadeCnt == 0) { fade->fadeout(); }
		}
		if (fade->FadeCnt == 1) {
			fade->fadein();
			if (fade->Alpha >= 1.0f) {
				fade->FadeCnt = 0;
				State = PLAY_STATE;
			}
		}

		break;

		//プレイ画面
	case PLAY_STATE:
		play->playdraw(number);
		if (fade->FadeCnt == 0) { fade->fadeout(); }
		flow->update(number, player_card, player_chip, player_dice, cpu_card, cpu_chip, cpu_dice, state, fade);
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
			drawImage(FlowImg[12], FlowPx12, FlowPy12);

		}
		else if (result->PlayerScore < result->CpuScore) {
			drawImage(FlowImg[13], FlowPx13, FlowPy13);
		}
		else {
			drawImage(FlowImg[14], FlowPx14, FlowPy14);

			}
			if (isTrigger(KEY_Z)) {
				playSound(Enter);
				stopSound(ResultBgm);
				playLoopSound(TitleBgm);
				State = TITLE_STATE;
			}
			break;
		}
	
}