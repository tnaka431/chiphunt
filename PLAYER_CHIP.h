#pragma once
class CONTAINER;
class NUMBER;
class PLAYER_CHIP {
public:
	void player_chipinit(CONTAINER* c);
	void player_chipdraw(NUMBER*num);
	int HaveChip = 0;
	int GiveChip = 0;
private:
	int ChipImg = 0;
	float Player_ChipPx = 0;
	float Player_ChipPy = 0;
	float Player_HChipPx = 0;
	float Player_HChipPy = 0;
	float Player_FChipPx = 0;
	float Player_FChipPy = 0;
};