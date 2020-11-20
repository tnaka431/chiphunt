#pragma once
#define gamestart 0 
#define givechip  1
#define round     2
#define paychip   3
#define shakedice 4 
#define disgame_1 5 
#define pullcard  6 
#define addcard   7
#define burst     8
#define addchip   9
#define muchchip  10
#define disgame_2 11
#define fight     12
#define win       13
#define lose      14
#define draw      15

class CONTAINER;
class NUMBER;
class PLAY {
public:
	void playinit(CONTAINER*c);
	//void playflow(CARD* cd, DICE* di);
	void playdraw(NUMBER*num);
private:
	int PlayImg=0;
	float Px=0;
	float Py=0;

	int FlowImg[15] = { 0 };

};
