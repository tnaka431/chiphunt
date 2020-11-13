#pragma once
class box;
class TRUMP {
public:
	void tpinit(box*b);
	void tpupdate();
	void tpdraw();
private:
	int Alltp = 0;
	int tp[52];
	int ransu = 0;
	float tpx = 0;
	float tpy = 0;
	int number = 0;

};

struct TRUMP_DATA {
	int alltp;
	float y;
	int tp[52];
	int ransu;
	int cnt;
	int number = 0;
	void tpinit(TRUMP_DATA* t);
	void tpupdate(TRUMP_DATA* t);
	void tpdraw(TRUMP_DATA* num);
	void drawtrump(TRUMP_DATA* t, int number);

};
