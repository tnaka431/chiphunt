#pragma once
class CONTAINER;
class NUMBER;
class CPU_DICE;
class CPU_CARD {
public:
	void cpu_cardinit(CONTAINER* c);
	void cpu_cardupdate(CPU_DICE*dice);
	void cpu_carddraw1();
	void cpu_carddraw2(NUMBER*num,CPU_DICE*dice);
	void cpu_cardnew();
	int Cpu_CardTotal = 0;
	int BurstCnt = 0;
	int S_Card = 0;
private:
	int CpuCardImg = 0;
	float CpuCardPx = 0;
	float CpuCardPy = 0;
	float CpuCardNumber_Px = 0;
	float CpuCardNumber_Py = 0;
	int AllCardImg = 0;
	int TureCpuCardImg[52] = { 0 };
	int Card[13] = { 0 };
	int CardNumber = 0;
	int TrumpNumber = 0;
	int DipCard = 0;
	int CardCnt = 0;
	int Flag = 0;
	int Cnt = 0;
	int AllBurstImg = 0;
	int BurstImg[52] = { 0 };
	int BurstNumber = 0;
	int BurstCard[13] = { 0 };
};
