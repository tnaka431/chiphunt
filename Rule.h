#pragma once
class box;

class RULE {
public:
	void ruleinit(box* b);
	//void ruleupdate();
	void ruledraw(box* b);
private:
	int RuleImg;
	float px;
	float py;
};

