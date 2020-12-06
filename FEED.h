#pragma once
class CONTAINER;
class FEED {
public:
	void init(CONTAINER*c);
	void feedin();
	void feedout();
	float Alpha = 0;
	int FeedCnt = 0;
private:
	int FeedImg = 0;
};