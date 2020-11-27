#pragma once
class CONTAINER;
class NUMBER {
public:
	void numberinit(CONTAINER* c);
	void s_numberdraw();
	void b_numberdraw();
	int Value = 0;
	float NumberPx = 0;
	float NumberPy = 0;
private:
	int Kurai = 0;
	int S_NumberImg[10] = { 0 };
	int B_NumberImg[10] = { 0 };
	int Vol=0;
};
