#pragma once
class CONTAINER;

class RULE {
public:
	void ruleinit(CONTAINER* c);
	void ruledraw1(CONTAINER* c);
	void ruledraw2(CONTAINER* c);
private:
	int RuleImg1 = 0;
	int RuleImg2 = 0;
	float px = 0;
	float py = 0;
	const float StartPx = 760.0f;
	const float StartPy = 1000.0f;
};

