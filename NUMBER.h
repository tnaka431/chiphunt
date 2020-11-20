#pragma once
class CONTAINER;
class NUMBER {
public:
	void numberinit(CONTAINER* c);
	void numberdraw();
	int Value = 0;
	float NumberPx = 0;
	float NumberPy = 0;
private:
	int NumberImg[10] = { 0 };
	int Kurai = 0;
	int Vol=0;
};
