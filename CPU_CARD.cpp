#include"graphic.h"
#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"CPU_CARD.h"
#include "NUMBER.h"
#include"CPU_DICE.h" 

void CPU_CARD::cpu_cardinit(CONTAINER* c) {
	CpuCardImg = c->cpucardimg;
	CpuCardPx = c->cpucard_px;
	CpuCardPy = c->cpucard_py;
	CpuCardNumber_Px = c->cpucardnumber_px;
	CpuCardNumber_Py = c->cpucardnumber_py;
	AllCardImg = c->allcardimg;
	S_Card = c->card;
	for (int i = 0; i < Handle; i++) {
		for (int j = 0; j < Number; j++) {
			TureCpuCardImg[j + i * 13] = divideImage(AllCardImg, 19 + 140 * j, 13 + 196 * i, 121, 180);
		}
	}
	AllBurstImg = c->allburstcardimg;
	for (int i = 0; i < Handle; i++) {
		for (int j = 0; j < Number; j++) {
			BurstImg[j + i * 13] = divideImage(AllBurstImg, 19 + 140 * j, 13 + 196 * i, 121, 180);
		}
	}
}
void CPU_CARD::cpu_cardupdate(CPU_DICE*dice) {
	while(dice->DiceSum-Cpubrain>Cpu_CardTotal){
			if (CardCnt < Number) {
				while (Cnt < CardCnt + OnePuls) {
					Flag = 0;
					CardNumber = getRand() % allcard;
					Card[TrumpNumber] = TureCpuCardImg[CardNumber];
					BurstCard[BurstNumber] = BurstImg[CardNumber];
					for (int i = 0; i < TrumpNumber; i++) {
						if (Card[TrumpNumber] == Card[i]) {
							Flag = 1;
							break;
						}
					}
					if (Flag == 0) {
						Cnt++;
					}
				}
				DipCard++;
				Cpu_CardTotal += (CardNumber % Number) + OnePuls;
				TrumpNumber++;
				BurstNumber++;
				CardCnt++;
			}
	}
	if (dice->DiceSum < Cpu_CardTotal) {
		BurstCnt = 1;
	}
}
void CPU_CARD::cpu_carddraw1() {
	for (int i = 0; i < Number; i++) {
		if (DipCard > i) { drawImage(CpuCardImg, CpuCardPx -Interval * i, CpuCardPy); }

	}
}
void CPU_CARD::cpu_carddraw2(NUMBER* num,CPU_DICE*dice) {
	if (dice->DiceSum >= Cpu_CardTotal) {
		for (int i = 0; i < Number; i++) {
			if (DipCard > i) { drawImage(Card[i], CpuCardPx - Interval * i, CpuCardPy); }
		}
	}
	else {
		for (int i = 0; i < Number; i++) {
			if (DipCard > i) { drawImage(BurstCard[i], CpuCardPx - Interval * i, CpuCardPy); }
		}
	}
	num->NumberPx = CpuCardNumber_Px;
	num->NumberPy = CpuCardNumber_Py;
	num->Value = Cpu_CardTotal;
	num->s_numberdraw();
}
void CPU_CARD::cpu_cardnew() {
	for (int i = 0; i < Number; i++) {
		Card[i] = 0;
	}
	CardNumber = 0;
	Cpu_CardTotal = 0;
	CardCnt = 0;
	TrumpNumber = 0;
	DipCard = 0;
	Flag = 0;
	Cnt = 0;
	BurstNumber = 0;
	for (int i = 0; i < Number; i++) {
		BurstCard[i] = 0;
	}
}