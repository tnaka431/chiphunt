#include<stdio.h>
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
#include"GAME.h"
#include"sound.h"
#include"FLOW.h"
#include"STATE.h"

#include"FADE.h"


GAME::GAME(){
	c = new CONTAINER;
	title = new TITLE;
	rule = new RULE;
	play = new PLAY;
	number = new NUMBER;
	player_chip = new PLAYER_CHIP;
	player_dice = new PLAYER_DICE;
	player_card = new PLAYER_CARD;
	cpu_chip = new CPU_CHIP;
	cpu_dice = new CPU_DICE;
	cpu_card = new CPU_CARD;
	result = new RESULT;
	flow = new FLOW;
	state = new STATE;
	fade = new FADE;
	title->titleinit(c);
	rule->ruleinit(c);
	play->playinit(c);
	number->numberinit(c);
	player_chip->player_chipinit(c);
	player_dice->player_diceinit(c);
	player_card->player_cardinit(c);
	cpu_chip->cpu_chipinit(c);
	cpu_dice->cpu_diceinit(c);
	cpu_card->cpu_cardinit(c);
	result->resultinit(c);
	flow->init(c);
	state->init(c);
	fade->init(c);
}
GAME::~GAME(){
	delete c;
	delete title;
	delete rule;
	delete play;
	delete number;
	delete player_chip ;
	delete player_dice ;
	delete player_card ;
	delete cpu_chip ;
	delete cpu_dice ;
	delete cpu_card ;
	delete result ;
	delete flow;
	delete state;
	delete fade;
 }


void GAME::Proc() {

	playLoopSound(state->TitleBgm);
	setRandSeed();
	while (msgProc()) {
		getInput();
		clearTarget();
		state->update(c, title, rule, play, result, number, player_card, player_chip, player_dice, cpu_card, cpu_chip, cpu_dice, flow, state,game,fade);
		present();
	}
}