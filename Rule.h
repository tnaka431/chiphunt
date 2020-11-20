#pragma once
class CONTAINER;

class RULE {
public:
	void ruleinit(CONTAINER* c);
	//void ruleupdate();
	void ruledraw(CONTAINER* c);
private:
	int RuleImg = 0;
	int ExpImg = 0;
	float px = 0;
	float py = 0;
};

