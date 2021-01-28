#pragma once
class CONTAINER;
class NUMBER;
class PLAYER_DICE {
public:
	void player_diceinit(CONTAINER* c);
	void player_diceupdate();
	void player_dicedraw(NUMBER*num);
	void player_dicenew();
	int DiceCnt = 0;
	int DiceSum = 0; 

private:
	int DiceImg[6] = { 0 };
	float  DicePx = 0;
	float DicePy = 0;
	int Dice[6] = { 0 };
	int Deme[5] = { 0 };
	float DiceNumberPx = 0;
	float DiceNumberPy = 0;
	int DiceSe1 = 0;
	int S_Dice = 0;
};