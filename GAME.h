#pragma once
class CONTAINER;
class TITLE;
class RULE;
class PLAY;
class NUMBER;
class PLAYER_CHIP;
class PLAYER_DICE;
class PLAYER_CARD;
class CPU_CHIP;
class CPU_DICE;
class CPU_CARD;
class RESULT;

class GAME {
public:
	GAME();
	~GAME();
	void Proc();
private:
	CONTAINER* c;
	TITLE* title;
	RULE* rule;
	PLAY* play;
	NUMBER* number;
	PLAYER_CHIP* player_chip;
	PLAYER_DICE* player_dice;
	PLAYER_CARD* player_card;
	CPU_CHIP* cpu_chip;
	CPU_DICE* cpu_dice;
	CPU_CARD* cpu_card;
	RESULT* result;
};
