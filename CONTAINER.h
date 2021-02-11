#pragma once
#pragma once
#include "graphic.h"
#include"framework.h"
#include"COLOR.h"
#include"sound.h"
#include"CHIP.h"

class CONTAINER {
public:
	CONTAINER() {
		initialize("チップハント", screenpx, screenpy, FULLSCREEN);
		titleimg = loadImage("Title screen.png");
		startimg = loadImage("Start button.png");
		ruleimg1 = loadImage("Rule explanation screen 1.png");
		ruleimg2 = loadImage("Rule explanation screen 2.png");
		playimg = loadImage("Game screen.png");
		r_chipimg = loadImage("Red chip.png");
		b_chipimg = loadImage("Black chip.png");
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
		m_numberimg[0] = { loadImage("「１」.png") };
		m_numberimg[1] = { loadImage("「２」.png") };
		m_numberimg[2] = { loadImage("「３」.png") };
		m_numberimg[3] = { loadImage("「４」.png") };
		m_numberimg[4] = { loadImage("「５」.png") };
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
		allcardimg = loadImage("トランプ(白).png");
		allburstcardimg = loadImage("トランプ(灰).png");
		cpucardimg = loadImage("card.png");
		resultimg = loadImage("result screen.png");
		kekkaimg = loadImage("PLAYER-CPU.png");
		flowimg[0] = loadImage("「ゲームスタート」.png");
		flowimg[1] = loadImage("「チップを配ります」.png");
		flowimg[2] = loadImage("「回戦目」.png");
		flowimg[3] = loadImage("「チップを支払ってください」.png");
		flowimg[4] = loadImage("「サイコロを振ります」.png");
		flowimg[5] = loadImage("「カードを引きますか？」.png");
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
		yesimg = loadImage("「はい」.png");
		noimg = loadImage("「いいえ」.png");
		havechip = loadImage("持ちチップの数.png");
		givechip = loadImage("場のチップ数.png");
		card = loadImage("カードの合計値.png");
		dice = loadImage("出目の合計数.png");
		backscreen = loadImage("black.png");
		//音
		titlebgm = loadSound("タイトルBGM.wav");
		gamebgm = loadSound("ゲームBGM.wav");
		resultbgm = loadSound("リザルトBGM.wav");
		enter = loadSound("決定ボタンSE.wav");
		dicese1 = loadSound("サイコロSE1.wav");
		dicese2 = loadSound("サイコロSE2.wav");
		dicese3 = loadSound("サイコロSE3.wav");
		chipse1 = loadSound("チップSE1.wav");
		chipse2 = loadSound("チップSE2.wav");
		cardse1 = loadSound("カードSE1.wav");
		cardse2 = loadSound("カードSE2.wav");
		burstse = loadSound("バースト.wav");
		winse = loadSound("勝ち.wav");
		losese = loadSound("負け.wav");
		drawse = loadSound("ドローSE.wav");
	};
	struct container {
		const int img;
		float px;
		float py;
		
	};

	const int screenpx = 1920;
	const int screenpy = 1080;
	const float px = 0.0f;
	const float py = 0.0f;
	const float back = 1.0f;
	//タイトル
	int titleimg = 0;
	int startimg = 0;
	const float titlepx = px;
	const float titlepy = py;
	//ルール
	int ruleimg1 = 0;
	int ruleimg2 = 0;
	const float rulepx = px;
	const float rulepy = py;
	//プレイ
	int playimg = 0;
	int playbgm = 0;
	int havechip = 0;
	int givechip = 0;
	int card = 0;
	int dice = 0;
	//リザルト
	int resultimg = 0;
	int kekkaimg = 0;
	const float resultpx = px;
	const float resultpy = py;
	const float playerscore_px = 525.0f;
	const float playerscore_py = 400.0f;
	const float cpuscore_px = 1200.0f;
	const float cpuscore_py = 400.0f;
	//数字
	int s_numberimg[10] = { 0 };
	int m_numberimg[5] = { 0 };
	int b_numberimg[10] = { 0 };
	const int vol = 0;
	//playerチップ
	int r_chipimg = 0;
	int b_chipimg = 0;
	const float p_rchipimg_px = 250.0f;
	const float p_rchipimg_py = 890.0f;
	const float p_bchipimg_px = 50.0f;
	const float p_bchipimg_py = 890.0f;
	const float p_havechip_px = 300.0f;
	const float p_havechip_py = 830.0f;
	const float p_givechip_px = 270.0f;
	const float p_givechip_py = 540.0f;
	//playerダイス
	int diceimg[6] = { 0 };
	const float playerdice_px = 1550.0f;
	const float playerdice_py = 850.0f;
	//player カード
	int allcardimg = 0;
	int allburstcardimg = 0;
	const float playercard_px = 525.0f;
	const float playercard_py = 900.0f;
	const float playercardnumber_px = 1000.0f;
	const float playercardnumber_py = 810.0f;
	//cpuチップ
	const float c_rchipimg_px = 250.0f;
	const float c_rchipimg_py = 20.0f;
	const float c_bchipimg_px = 50.0f;
	const float c_bchipimg_py = 20.0f;
	const float c_havechip_px = 300.0f;
	const float c_havechip_py = 230.0f;
	const float c_givechip_px = 270.0f;
	const float c_givechip_py =485.0f;
	//cpuダイス
	const float cpudice_px = 1600.0f;
	const float cpudice_py = 0.0f;
	//cpu カード
	int cpucardimg = 0;
	const float cpucard_px = 1125.0f;
	const float cpucard_py = 0.0f;
	const float cpucardnumber_px = 1000.0f;
	const float cpucardnumber_py = 218.0f;
	//ゲーム
	int flowimg[15] = { 0 };
	int arrowimg = 0;
	int yesimg = 0;
	int noimg = 0;
	const float flowpx = 550.0f;
	const float flowpy = 450.0f;
	const float arrow1px = 750.0f;
	const float arrow2px = 1015.0f;
	const float arrowpy = 655.0f;
	const float yespx = 800.0f;
	const float yespy = 650.0f;
	const float nopx = 1080.0f;
	const float nopy = 650.0f;
	int cpudis = 0;
	//BGM
	int titlebgm = 0;
	int gamebgm = 0;
	int resultbgm =0;
	int enter = 0;
	int dicese1 =0;
	int dicese2 =0;
	int dicese3 = 0;
	int chipse1 = 0;
	int chipse2 = 0;
	int cardse1 =0;
	int cardse2 = 0;
	int burstse = 0;
	int winse = 0;
	int losese = 0;
	int drawse = 0;
	//FADE
	int backscreen = 0;
};