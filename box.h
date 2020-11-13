#pragma once
#pragma once
#include "graphic.h"
#include"framework.h"
#include"COLOR.h"

class box {
public:
	box() {
		initialize("チップハント", screenpx, screenpy, FULLSCREEN);
		titleimg = loadImage("Title screen.png");
		startimg = loadImage("Start button.png");
		ruleimg = loadImage("Rule screen.png");
		gameplayimg = loadImage("Game screen.png");
		clip = loadImage("Red chips.png");
		//alltp = loadImage("トランプ.png");
	};
	const int screenpx = 1920;
	const int screenpy = 1080;
	const float px = screenpx / 2;
	const float py = screenpy / 2;
	//タイトル
	int titleimg = 0;
	int startimg = 0;
	const float titlepx = px;
	const float titlepy = py;
	//ルール
	int ruleimg = 0;
	const float rulepx = px;
	const float rulepy = py;
	//ゲームプレイ
	int gameplayimg = 0;
	int clip = 0;
	const float playerpx = 110.0f;
	const float playerpy = 110.0f;
	const float pcpx = 110.0f;
	const float pcpy = 970.0f;
	/*/
	int alltp = 0;
	const float tp;

	//const 
	/*///リザルト
};