#pragma once
class CONTAINER;
class NUMBER;
class CPU_DICE {
public:
	void cpu_diceinit(CONTAINER* c);
	void cpu_diceupdate();
	void cpu_dicedraw(NUMBER*c);
	void cpu_dicenew();
	int DiceSum = 0;
	int S_Dice = 0;
private:
	int DiceImg[6] = { 0 };
	float DicePx = 0;
	float DicePy = 0;
	int Dice[6] = { 0 };
	int Deme[5] = { 0 };
	const float DiceNumberPx = 1770.0f;
	const float DiceNumberPy = 220.0f;
	const float Interval = 100.0f;
	const float halfInterval = 50.0f;
	const int DiceEye = 6;
	const int DiceNumber = 5;//ダイスの個数
	const int DiceUpNumber = 2;//ダイスの上段の数
	enum Cnt { one, two, three,four };
	Cnt cnt = two;
};