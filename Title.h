#pragma once

class CONTAINER;
class TITLE {
public:
	void titleinit(CONTAINER* c);
	void titledraw(CONTAINER* c);
private:
	int TitleImg = 0;
	int StartImg=0;
	float px=0;
	float py=0;
};