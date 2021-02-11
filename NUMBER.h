#pragma once
class CONTAINER;
class NUMBER {
public:
	void numberinit(CONTAINER* c);
	void s_numberdraw();
	void b_numberdraw();
	void m_numberdraw();
	int Value = 0;
	float NumberPx = 0;
	float NumberPy = 0;
private:
	int Kurai = 10;
	int S_NumberImg[10] = { 0 };
	int B_NumberImg[10] = { 0 };
	int M_NumberImg[5] = { 0 };
	int Vol=0;
	const float S_NumberInterval = 20.0f;
	const float B_NumberInterval = 80.0f;
	const int Zyu = 10;
	const int Number = 10;
	const int sNumber = 5;
	const int keta = 2;
};
