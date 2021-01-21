#pragma once
class CONTAINER;
class FADE {
public:
	void init(CONTAINER*c);
	void fadein();
	void fadeout();
	float Alpha = 0;
	int FadeCnt = 0;
private:
	int FadeImg = 0;
};