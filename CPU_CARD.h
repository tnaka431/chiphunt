#pragma once
class CONTAINER;
class NUMBER;
class CPU_CARD {
public:
	void cpu_cardinit(CONTAINER* c);
	void cpu_cardupdate();
	void cpu_carddraw1();
	void cpu_carddraw2(NUMBER*num);
	int Cpu_CardTotal = 0;
private:
	int CpuCardImg = 0;
	float CpuCardPx = 0;
	float CpuCardPy = 0;
	float CpuCardNumber_Px = 0;
	float CpuCardNumber_Py = 0;
	int AllCardImg = 0;
	int TureCpuCardImg[52] = { 0 };
	int CardNumber = 0;
	int Card[13] = { 0 };
	int TrumpNumber = 0;
	int DipCard = 0;
	int CardCnt = 0;
	int Flag = 0;
	int Cnt = 0;
};
