#pragma once

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
