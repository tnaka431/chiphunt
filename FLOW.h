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
class FADE;
class FLOW {
public:
	void init(CONTAINER* c);
	void update(NUMBER* number, PLAYER_CARD* player_card, PLAYER_CHIP* player_chip, PLAYER_DICE* player_dice,
		CPU_CARD* cpu_card, CPU_CHIP* cpu_chip, CPU_DICE* cpu_dice,STATE*state,FADE*fade);
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
	const float S_CardPx = 700.0f;
	const float S_CardPy = 210.0f;
	const float S_DicePx = 1500.0f;
	const float S_DicePy = 210.0f;
	const float CountNumberPx = 700.0f;
	const float CountNumberPy = 460.0f;
	const float addNumberPx = 800.0f;
	const float addNumberPy = 550.0f;
	const float FlowImgPx2 = 750.0f;
	const float FlowImgPx3 = 450.0f;
	const float FlowImgPx11 = 480.0f;
	const float FlowImgPy11 = 410.0f;
	const float FlowImgPy12 = 350.0f;
	const float FlowImgPx13 = 570.0f;
	const float FlowImgPy13 = 410.0f;
	const float FlowImgPy14 = 425.0f;
	const float ArrowRightPx = 985.0f;
	const float ArrowRightPy = 595.0f;
	const float ArrowLeftPx = 750.0f;
	const float ArrowLeftPy = 610.0f;
	const float ArrowRad = 3.14f;

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