#pragma once
class CONTAINER;
class NUMBER;
class CPU_CHIP {
public:
	void cpu_chipinit(CONTAINER* c);
	void cpu_chipdraw(NUMBER*num);
	int HaveChip = 0;
	int GiveChip = 0;
private:
	int ChipImg = 0;
	float Cpu_ChipPx = 0;
	float Cpu_ChipPy = 0;
	float Cpu_HChipPx = 0;
	float Cpu_HChipPy = 0;
	float Cpu_FChipPx = 0;
	float Cpu_FChipPy = 0;
};