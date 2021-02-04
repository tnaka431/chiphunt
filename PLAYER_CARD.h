#pragma once
class CONTAINER;
class NUMBER;
class PLAYER_DICE;
class PLAYER_CARD {
public:
	void player_cardinit(CONTAINER* c);
	void player_cardupdate();
	void player_carddraw(NUMBER*NUM,PLAYER_DICE*dice);
	void player_cardnew();
	int Player_CardTotal = 0;

private:
	int AllCardImg = 0;
	int CardImg[52] = { 0 };
	int Card[13] = { 0 };
	float PlayerCard_Px = 0;
	float PlayerCard_Py = 0;
	float PlayerCardNumber_Px = 0;
	float PlayerCardNumber_Py = 0;
	int CardCnt = 0;
	int CardNumber = 0;
	int TrumpNumber = 0;
	int DipCard = 0;
	int Flag = 0;
	int Cnt = 0;
	int AllBarstImg = 0;
	int BarstImg[52] = { 0 };
	int BarstNumber = 0;
	int BarstCard[13] = { 0 };
	int S_Card = 0;
	const float Interval = 50.0f;
	const float S_CardPx = 700.0f;
	const float S_CardPy = 800.0f;
};
