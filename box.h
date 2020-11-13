#pragma once
#pragma once
#include "graphic.h"
#include"framework.h"
#include"COLOR.h"

class box {
public:
	box() {
		initialize("�`�b�v�n���g", screenpx, screenpy, FULLSCREEN);
		titleimg = loadImage("Title screen.png");
		startimg = loadImage("Start button.png");
		ruleimg = loadImage("Rule screen.png");
		gameplayimg = loadImage("Game screen.png");
		chip = loadImage("Red chips.png");
		alltp = loadImage("�g�����v����.png");
	};
	const int screenpx = 1920;
	const int screenpy = 1080;
	const float px = screenpx / 2;
	const float py = screenpy / 2;
	//�^�C�g��
	int titleimg = 0;
	int startimg = 0;
	const float titlepx = px;
	const float titlepy = py;
	//���[��
	int ruleimg = 0;
	const float rulepx = px;
	const float rulepy = py;
	//�Q�[���v���C
	int gameplayimg = 0;
	int chip = 0;
	const float playerpx = 110.0f;
	const float playerpy = 110.0f;
	const float pcpx = 110.0f;
	const float pcpy = 970.0f;
	//�g�����v
	int alltp = 0;
	const float trumppx = 500.0f;
	const float trumppy = 900.0f;
	//���U���g
};