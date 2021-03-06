#pragma once
class CONTAINER;
class TITLE;
class RULE;
class PLAY;
class RESULT;
class NUMBER;
class PLAYER_CARD;
class PLAYER_CHIP;
class PLAYER_DICE;
class CPU_CARD;
class CPU_CHIP;
class CPU_DICE;
class FLOW;
class GAME;
class CHIP;

class FADE;
class STATE {
public:
	void init(CONTAINER* c);
	void update(CONTAINER* c, TITLE* title, RULE* rule, PLAY* play, RESULT* result,NUMBER* number,
		PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice, 
		CPU_CARD* cpu_card,CPU_CHIP* cpu_chip,CPU_DICE* cpu_dice,FLOW*flow,STATE*state,GAME*game,FADE*fade);
	enum GAMESTATE { TITLE_STATE,RULE_STATE, PLAY_STATE,RESULT_STATE };
	GAMESTATE GameState = TITLE_STATE;
	int RoundCnt = 0;
	int TitleBgm = 0;
	int GameBgm = 0;
	int ResultBgm = 0;
private:
	int FlowImg[15] = { 0 };
	float FlowPx = 0;
	float FlowPy = 0;
	int ArrowImg = 0;
	float ArrowPx1 = 0;
	float ArrowPx2 = 0;
	float ArrowPy = 0;
	int Cnt = 0;
	int Enter = 0;
	int winse = 0;
	int losese = 0;
	const float ArrowRightPx = 1750.0f;
	const float ArrowRightPy = 955.0f;
	const float ArrowLeftPx = 100.0f;
	const float ArrowLeftPy = 955.0f;
	const float ArrowRad = 3.14f;
	const float FlowPx12 = 600.0f;
	const float FlowPy12 = 580.0f;
	const float FlowPx13 = 620.0f;
	const float FlowPy13 = 650.0f;
	const float FlowPx14 = 600.0f;
	const float FlowPy14 = 650.0f;
	const int FlowNumber = 15;
	const float MaxAlpha = 1.0f;
};