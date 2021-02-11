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
	int FadeImg=0;
	const float x = 960.0f;
	const float y = 540.0f;
	const float z = 0.0f;
	const float r = 0.0f;
	const float g = 0.0f;
	const float b = 0.0f;
	const float DAlpha = 0.07f;
	const float MaxAlpha = 1.0f;
	const float MinAlpha = 0.0f;
};