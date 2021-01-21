#pragma once
class CONTAINER;
class TITLE;
class RULE;
class PLAY;
class NUMBER;
class PLAYER_CHIP;
class PLAYER_DICE;
class PLAYER_CARD;
class CPU_CHIP;
class CPU_DICE;
class CPU_CARD;
class RESULT;
class FLOW;
class STATE;
class CHIP;

class FADE;
class GAME {
public:
	GAME();
	~GAME();
	void Proc();
private:
	CONTAINER* c;
	TITLE* title;
	RULE* rule;
	PLAY* play;
	NUMBER* number;
	PLAYER_CHIP* player_chip;
	PLAYER_DICE* player_dice;
	PLAYER_CARD* player_card;
	CPU_CHIP* cpu_chip;
	CPU_DICE* cpu_dice;
	CPU_CARD* cpu_card;
	RESULT* result;
	FLOW* flow;
	STATE* state;
	GAME* game;
	CHIP* chip = 0;
	FADE* fade;
	/*enum FLOWSTATE {GAMESTART, GIVECHIP, ROUND ,PAYCHIP,  SHAKEDICE ,PULLCARD,  ADDCARD, BURST,  ADDCHIP,  MUCHCHIP, DISGAME, FIGHT,  WIN,  LOSE,  DRAW,};
	enum GAMESTATE {TITLE_STATE,RULE_STATE,PLAY_STATE,RESULT_STATE};
	int FlowImg[15] = { 0 };
	float FlowPx = 0;
	float FlowPy = 0;
	int ArrowImg = 0;
	float ArrowPx1 = 0;
	float ArrowPx2= 0;
	float ArrowPy = 0;
	int State = 0;
	int Flow = 0;
	int RoundCnt = 0;
	int Cnt = 0;
	int DisCpuCnt = 0;
	int DisPlayerCnt = 0;
	int BurstCnt = 0;
	int AddChipCnt = 0;
	int HaveCnt = 0;
	int Difference = 0;
	int CpuAddChip = 0;
	int CpuAddCnt = 0;*/
};
