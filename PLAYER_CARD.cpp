#include"graphic.h"
#include "input.h"
#include"rand.h"
#include"CONTAINER.h"
#include"PLAYER_CARD.h"
#include "NUMBER.h"
#include"PLAYER_DICE.h"

void PLAYER_CARD::player_cardinit(CONTAINER* c) {
	AllCardImg = c->allcardimg;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			CardImg[j + i * 13] = divideImage(AllCardImg, 19 + 140 * j, 13 + 196 * i, 121, 180);
		}
	}
	PlayerCard_Px = c->playercard_px;
	PlayerCard_Py = c->playercard_py;
	PlayerCardNumber_Px = c->playercardnumber_px;
	PlayerCardNumber_Py = c->playercardnumber_py;
	S_Card = c->card;

	AllBarstImg = c->allburstcardimg;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			BarstImg[j + i * 13] = divideImage(AllBarstImg, 19 + 140 * j, 13 + 196 * i, 121, 180);
		}
	}
}
void PLAYER_CARD::player_cardupdate() {
	if (isTrigger(KEY_Z)) {
		if (CardCnt < 13) {
			while (Cnt < CardCnt+1) {
				Flag = 0;
				CardNumber = getRand() % 52;
				Card[TrumpNumber] = CardImg[CardNumber];
				BarstCard[BarstNumber]=BarstImg[CardNumber];
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
		Player_CardTotal += (CardNumber % 13) + 1;
		TrumpNumber++;
		BarstNumber++;
		CardCnt++;
		}
	}
}
void PLAYER_CARD::player_carddraw(NUMBER*num,PLAYER_DICE*dice) {
	if (dice->DiceSum >= Player_CardTotal) {
		for (int i = 0; i < 13; i++) {
			if (DipCard > i) { drawImage(Card[i], PlayerCard_Px + Interval * i, PlayerCard_Py); }

		}
	}
	else {
		for (int i = 0; i < 13; i++) {
			if (DipCard > i) { drawImage(BarstCard[i], PlayerCard_Px + Interval * i, PlayerCard_Py); }
		}
	}
	num->NumberPx = PlayerCardNumber_Px;
	num->NumberPy = PlayerCardNumber_Py;
	num->Value = Player_CardTotal;
	num->s_numberdraw();
	drawImage(S_Card, S_CardPx, S_CardPy);

}
void PLAYER_CARD::player_cardnew() {
	for (int i = 0; i < 13; i++) {
		Card[i] = 0;
	}
	CardNumber = 0;
	Player_CardTotal = 0;
	CardCnt = 0;
	TrumpNumber = 0;
	DipCard = 0;
	Flag = 0;
	Cnt = 0;
	BarstNumber = 0;
	for (int i = 0; i < 13; i++) {
		BarstCard[i] = 0;
	}

}