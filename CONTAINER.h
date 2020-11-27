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
		ruleimg1 = loadImage("Rule explanation screen 1.png");
		ruleimg2 = loadImage("Rule explanation screen 2.png");
		playimg = loadImage("Game screen.png");
		chipimg = loadImage("Red chips.png");
		s_numberimg[0] = { loadImage("Number_0_short.png") };
		s_numberimg[1] = { loadImage("Number_1_short.png") };
		s_numberimg[2] = { loadImage("Number_2_short.png") };
		s_numberimg[3] = { loadImage("Number_3_short.png") };
		s_numberimg[4] = { loadImage("Number_4_short.png") };
		s_numberimg[5] = { loadImage("Number_5_short.png") };
		s_numberimg[6] = { loadImage("Number_6_short.png") };
		s_numberimg[7] = { loadImage("Number_7_short.png") };
		s_numberimg[8] = { loadImage("Number_8_short.png") };
		s_numberimg[9] = { loadImage("Number_9_short.png") };
		b_numberimg[0] = { loadImage("Number_0.png") };
		b_numberimg[1] = { loadImage("Number_1.png") };
		b_numberimg[2] = { loadImage("Number_2.png") };
		b_numberimg[3] = { loadImage("Number_3.png") };
		b_numberimg[4] = { loadImage("Number_4.png") };
		b_numberimg[5] = { loadImage("Number_5.png") };
		b_numberimg[6] = { loadImage("Number_6.png") };
		b_numberimg[7] = { loadImage("Number_7.png") };
		b_numberimg[8] = { loadImage("Number_8.png") };
		b_numberimg[9] = { loadImage("Number_9.png") };
		diceimg[0] = { loadImage("Dice_1.png")};
		diceimg[1] = { loadImage("Dice_2.png")};
		diceimg[2] = { loadImage("Dice_3.png")};
		diceimg[3] = { loadImage("Dice_4.png")};
		diceimg[4] = { loadImage("Dice_5.png")};
		diceimg[5] = { loadImage("Dice_6.png")};
		allcardimg = loadImage("トランプ横列.png");
		allburstcardimg = loadImage("トランプ横列(灰).png");
		cpucardimg = loadImage("card.png");
		resultimg = loadImage("Result(仮).png");
		backscreen = loadImage("black.png");
		flowimg[0] = loadImage("「ゲームスタート」.png");
		flowimg[1] = loadImage("「チップを配ります」.png");
		flowimg[2] = loadImage("1_0round.png");
		flowimg[3] = loadImage("「チップを支払ってください」.png");
		flowimg[4] = loadImage("「サイコロを振ります」.png");
		flowimg[5] = loadImage("「カードを引きますか？」2.png");
		flowimg[6] = loadImage("「カードを加えます」.png");
		flowimg[7] = loadImage("「バーストしました」.png");
		flowimg[8] = loadImage("「上乗せしますか？」.png");
		flowimg[9] = loadImage("「どのくらいしますか？」.png");
		flowimg[10] = loadImage("「勝負から降りますか？」.png");
		flowimg[11] = loadImage("FIGHT.png");
		flowimg[12] = loadImage("WIN.png");
		flowimg[13] = loadImage("LOSE.png");
		flowimg[14] = loadImage("DRAW.png");
		arrowimg = loadImage("矢印1.png");
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
	int ruleimg1 = 0;
	int ruleimg2 = 0;

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
	const float playerscore_px = 500.0f;
	const float playerscore_py = 400.0f;
	const float cpuscore_px = 1150.0f;
	const float cpuscore_py = 400.0f;
	//数字
	int s_numberimg[10] = { 0 };
	int b_numberimg[10] = { 0 };
	const int kurai = 10;
	const int vol = 0;
	//playerチップ
	int chipimg = 0;
	const float playerchip_px = 0.0f;
	const float playerchip_py = 870.0f;
	const float playerhavechip_px = 300.0f;
	const float playerhavechip_py = 810.0f;
	const float playerfieldchip_px = 260.0f;
	const float playerfieldchip_py = 610.0f;
	//playerダイス
	int diceimg[6] = { 0 };
	const float playerdice_px = 1550.0f;
	const float playerdice_py = 850.0f;
	const float playerdicenumber_px = 1770.0f;
	const float playerdicenumber_py = 810.0f;
	//player カード
	int allcardimg = 0;
	int allburstcardimg = 0;
	const float playercard_px = 525.0f;
	const float playercard_py = 900.0f;
	const float playercardnumber_px = 1000.0f;
	const float playercardnumber_py = 810.0f;
	//cpuチップ
	const float cpuchip_px = 0.0f;
	const float cpuchip_py = 0.0f;
	const float cpuhavechip_px = 300.0f;
	const float cpuhavechip_py = 220.0f;
	const float cpufieldchip_px = 260.0f;
	const float cpufieldchip_py =410.0f;
	//cpuダイス
	const float cpudice_px = 1600.0f;
	const float cpudice_py = 0.0f;
	const float cpudicenumber_px = 1770.0f;
	const float cpudicenumber_py = 220.0f;
	//cpu カード
	int cpucardimg = 0;
	const float cpucard_px = 1125.0f;
	const float cpucard_py = 0.0f;
	const float cpucardnumber_px = 1000.0f;
	const float cpucardnumber_py = 218.0f;
	//ゲーム
	int flowimg[15] = { 0 };
	int arrowimg = 0;
	const float flowpx = 550.0f;
	const float flowpy = 450.0f;
	const float arrow1px = 750.0f;
	const float arrow2px = 1015.0f;
	const float arrowpy = 670.0f;
	int cpudis = 0;
};