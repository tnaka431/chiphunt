#pragma once
class CONTAINER;
class NUMBER;
class CHIP {
public:
	virtual void init(CONTAINER* c);
	virtual void update();
	virtual void draw(NUMBER*num);

	virtual int havechip();
	virtual int givechip();
	virtual float chippx();
	virtual float chippy();
	virtual float havepx();
	virtual float havepy();
	virtual float givepx();
	virtual float givepy();
	int HaveChip = 0;
	int GiveChip = 0;

protected:
	int ChipImg = 0;
	float ChipPx = 0;
	float ChipPy = 0;
	float HavePx = 0;
	float HavePy = 0;
	float GivePx = 0;
	float GivePy = 0;
};