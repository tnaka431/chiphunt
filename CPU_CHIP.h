#pragma once
class CONTAINER;
class NUMBER;
class CPU_CHIP {
public:
	void cpu_chipinit(CONTAINER* c);
	void cpu_chipdraw(NUMBER*num);
	int HaveChip = 0;
	int GiveChip = 0;
	int score = 0;
private:
	int RedChipImg = 0;
	int BlackChipImg = 0;
	float RedChipPx = 0;
	float RedChipPy = 0;
	float BlackChipPx = 0;
	float BlackChipPy = 0;
	float HaveChipPx = 0;
	float HaveChipPy = 0;
	float GiveChipPx = 0;
	float GiveChipPy = 0;
	int R_HaveChip = 0;
	int B_HaveChip = 0;
	int R_GiveChip = 0;
	int B_GiveChip = 0;
	int S_HaveChip = 0;
	int S_GiveChip = 0;
	const float StringChipPx = 0.0f;
	const float StringHChipPy = 220.0f;
	const float StringGChipPy = 470.0f;
	const float GiveChipImgpy = 280.0f;
	const int Divided = 5;
};
/*
class CPU_CHIP :public CHIP {
	void init(CONTAINER*c);
	void update(CONTAINER*c);
	void draw(NUMBER* num);
};*/