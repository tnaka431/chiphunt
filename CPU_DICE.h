#pragma once
class CONTAINER;
class NUMBER;
class CPU_DICE {
public:
	void cpu_diceinit(CONTAINER* c);
	void cpu_diceupdate();
	void cpu_dicedraw(NUMBER*c);
	int CpuCnt = 0;
	int DiceCnt = 0;
private:
	int DiceImg[6] = { 0 };
	float DicePx = 0;
	float DicePy = 0;
	int Dice[6] = { 0 };
	int Deme[5] = { 0 };
	float DiceNumberPx = 0;
	float DiceNumberPy = 0;
	int DemeGoukei = 0;
};