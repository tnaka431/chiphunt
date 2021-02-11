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
	int DiceSe1 = 0;
	int S_Dice = 0;
	const float DiceNumberPx = 1770.0f;
	const float DiceNumberPy = 810.0f;
	const float Interval = 100.0f;
	const float halfInterval = 50.0f;
	const float S_DicePx = 1500.0f;
	const float S_DicePy = 800.0f;
	const int DiceEye = 6;
	const int DiceNumber = 5;//ダイスの個数
	const int DiceUpNumber = 3;//ダイスの上段の数
};