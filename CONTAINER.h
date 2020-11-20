#pragma once
#pragma once
#include "graphic.h"
#include"framework.h"
#include"COLOR.h"

class CONTAINER {
public:
	CONTAINER() {
		initialize("チップハント", screenpx, screenpy, FULLSCREEN);
		titleimg = loadImage("Title screen.png");
		startimg = loadImage("Start button.png");
		ruleimg = loadImage("Rule screen.png");
		expimg = loadImage("rule3.png");
		playimg = loadImage("Game screen.png");
		chipimg = loadImage("Red chips.png");
		numberimg[0] = { loadImage("Number_0_short.png") };
		numberimg[1] = { loadImage("Number_1_short.png") };
		numberimg[2] = { loadImage("Number_2_short.png") };
		numberimg[3] = { loadImage("Number_3_short.png") };
		numberimg[4] = { loadImage("Number_4_short.png") };
		numberimg[5] = { loadImage("Number_5_short.png") };
		numberimg[6] = { loadImage("Number_6_short.png") };
		numberimg[7] = { loadImage("Number_7_short.png") };
		numberimg[8] = { loadImage("Number_8_short.png") };
		numberimg[9] = { loadImage("Number_9_short.png") };
		diceimg[0] = { loadImage("Dice_1.png")};
		diceimg[1] = { loadImage("Dice_2.png")};
		diceimg[2] = { loadImage("Dice_3.png")};
		diceimg[3] = { loadImage("Dice_4.png")};
		diceimg[4] = { loadImage("Dice_5.png")};
		diceimg[5] = { loadImage("Dice_6.png")};
		allcardimg = loadImage("トランプ横列.png");
		cpucardimg = loadImage("card.png");
		resultimg = loadImage("Result(仮).png");
		backscreen = loadImage("black.png");
	};
	const int screenpx = 1920;
	const int screenpy = 1080;
	const float px = 0.0f;
	const float py = 0.0f;
	const float back = 1.0f;
	//タイトル
	int titleimg = 0;
	int startimg = 0;
	int backscreen = 0;
	const float titlepx = px;
	const float titlepy = py;
	//ルール
	int ruleimg = 0;
	int expimg = 0;
	const float rulepx = px;
	const float rulepy = py;
	//プレイ
	int playimg = 0;
	//リザルト
	int resultimg = 0;
	//int startimg = 0;
	//int backscreen = 0;
	const float resultpx = px;
	const float resultpy = py;
	//数字
	int numberimg[10] = { 0 };
	const int kurai = 10;
	const int vol = 0;
	//playerチップ
	int chipimg = 0;
	const float playerchip_px = 0.0f;
	const float playerchip_py = 870.0f;
	const float playerhavechip_px = 10.0f;
	const float playerhavechip_py = 800.0f;
	const float playerfieldchip_px = 10.0f;
	const float playerfieldchip_py = 600.0f;
	//playerダイス
	int diceimg[6] = { 0 };
	const float playerdice_px = 1550.0f;
	const float playerdice_py = 850.0f;
	const float playerdicenumber_px = 1600.0f;
	const float playerdicenumber_py = 800.0f;
	//player カード
	int allcardimg = 0;
	const float playercard_px = 525.0f;
	const float playercard_py = 900.0f;
	const float playercardnumber_px = 500.0f;
	const float playercardnumber_py = 800.0f;
	//cpuチップ
	const float cpuchip_px = 0.0f;
	const float cpuchip_py = 0.0f;
	const float cpuhavechip_px = 10.0f;
	const float cpuhavechip_py = 200.0f;
	const float cpufieldchip_px = 10.0f;
	const float cpufieldchip_py =400.0f;
	//cpuダイス
	const float cpudice_px = 1600.0f;
	const float cpudice_py = 0.0f;
	const float cpudicenumber_px = 1600.0f;
	const float cpudicenumber_py = 200.0f;
	//cpu カード
	int cpucardimg = 0;
	const float cpucard_px = 1125.0f;
	const float cpucard_py = 0.0f;
	const float cpucardnumber_px = 1225.0f;
	const float cpucardnumber_py = 200.0f;
	//ゲーム

};