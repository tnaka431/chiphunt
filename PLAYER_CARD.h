#pragma once
class CONTAINER;
class NUMBER;
class PLAYER_CARD {
public:
	void player_cardinit(CONTAINER* c);
	void player_cardupdate();
	void player_carddraw(NUMBER*NUM);
	int Player_CardTotal = 0;
	int CardCnt = 0;
private:
	int AllCardImg = 0;
	int CardImg[52] = { 0 };
	float PlayerCard_Px = 0;
	float PlayerCard_Py = 0;
	float PlayerCardNumber_Px = 0;
	float PlayerCardNumber_Py = 0;
	int CardNumber = 0;
	int Card[13] = { 0 };
	int TrumpNumber = 0;
	int DipCard = 0;
	int Flag = 0;
	int Cnt = 0;
};