#pragma once
class CONTAINER;
class NUMBER;
class RESULT {
public:
	void resultinit(CONTAINER* c);
	void resultdraw();
	void playerscore(NUMBER* num);
	void cpuscore(NUMBER* num);
	int PlayerScore = 0;
	int CpuScore = 0;
private:
	int ResultImg = 0;
	int KekkaImg = 0;
	const float KekkaPx = 390.0f;
	const float KekkaPy = 250.0f;
	float Px=0;
	float Py=0;
	float PlayerScorePx = 0;
	float PlayerScorePy = 0;
	float CpuScorePx = 0;
	float CpuScorePy = 0;
};
