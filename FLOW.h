#pragma once
class CONTAINER;
class NUMBER;
class PLAYER_CARD;
class PLAYER_CHIP;
class PLAYER_DICE;
class CPU_CARD;
class CPU_CHIP;
class CPU_DICE;
class STATE;
class CHIP;
class FEED;
class FLOW {
public:
	void init(CONTAINER* c);
	void update(NUMBER* number, PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice, CPU_CARD* cpu_card, CPU_CHIP* cpu_chip, CPU_DICE* cpu_dice,STATE*state,FEED*feed);
	enum FLOWSTATE { GAMESTART, GIVECHIP, ROUND, PAYCHIP, SHAKEDICE, PULLCARD, ADDCARD, BURST, ADDCHIP, MUCHCHIP, DISGAME, FIGHT, WIN, LOSE, DRAW, };
	int ResultBgm = 0;
private:
	int FlowImg[15] = { 0 };
	int YesImg = 0;
	int NoImg = 0;
	float FlowPx = 0;
	float FlowPy = 0;
	int ArrowImg = 0;
	float ArrowPx1 = 0;
	float ArrowPx2 = 0;
	float ArrowPy = 0;
	float YesPx = 0;
	float YesPy = 0;
	float NoPx = 0;
	float NoPy = 0;
	int Flow = 0;
	int Cnt = 0;
	int DisCpuCnt = 0;
	int DisPlayerCnt = 0;
	int BurstCnt = 0;
	int AddChipCnt = 0;
	int HaveCnt = 0;
	int Difference = 0;
	int CpuAddChip = 0;
	int CpuAddCnt = 0;
	//‰¼
	int Motichip = 0;
	int Bachip = 0;
	int Cardsu = 0;
	int Dicesu = 0;
	//‰¹
	int Enter = 0;
	int ChipSe1 = 0;
	int ChipSe2 = 0;
	int DiceSe = 0;
	int CardSe = 0;
	int BurstSe = 0;
	int WinSe = 0;
	int LoseSe = 0;
	int DrawSe = 0;
};