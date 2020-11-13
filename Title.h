#pragma once

class box;
class TITLE {
public:
	//TITLE();
	void titleinit(box* b);
	void titledraw(box* b);
private:
	int TitleImg;
	int StartImg;
	float px;
	float py;
};