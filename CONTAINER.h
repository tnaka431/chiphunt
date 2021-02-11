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
		initialize("�`�b�v�n���g", screenpx, screenpy, FULLSCREEN);
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
		m_numberimg[0] = { loadImage("�u�P�v.png") };
		m_numberimg[1] = { loadImage("�u�Q�v.png") };
		m_numberimg[2] = { loadImage("�u�R�v.png") };
		m_numberimg[3] = { loadImage("�u�S�v.png") };
		m_numberimg[4] = { loadImage("�u�T�v.png") };
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
		allcardimg = loadImage("�g�����v(��).png");
		allburstcardimg = loadImage("�g�����v(�D).png");
		cpucardimg = loadImage("card.png");
		resultimg = loadImage("result screen.png");
		kekkaimg = loadImage("PLAYER-CPU.png");
		flowimg[0] = loadImage("�u�Q�[���X�^�[�g�v.png");
		flowimg[1] = loadImage("�u�`�b�v��z��܂��v.png");
		flowimg[2] = loadImage("�u���ځv.png");
		flowimg[3] = loadImage("�u�`�b�v���x�����Ă��������v.png");
		flowimg[4] = loadImage("�u�T�C�R����U��܂��v.png");
		flowimg[5] = loadImage("�u�J�[�h�������܂����H�v.png");
		flowimg[6] = loadImage("�u�J�[�h�������܂��v.png");
		flowimg[7] = loadImage("�u�o�[�X�g���܂����v.png");
		flowimg[8] = loadImage("�u��悹���܂����H�v.png");
		flowimg[9] = loadImage("�u�ǂ̂��炢���܂����H�v.png");
		flowimg[10] = loadImage("�u��������~��܂����H�v.png");
		flowimg[11] = loadImage("FIGHT.png");
		flowimg[12] = loadImage("WIN.png");
		flowimg[13] = loadImage("LOSE.png");
		flowimg[14] = loadImage("DRAW.png");
		arrowimg = loadImage("���1.png");
		yesimg = loadImage("�u�͂��v.png");
		noimg = loadImage("�u�������v.png");
		havechip = loadImage("�����`�b�v�̐�.png");
		givechip = loadImage("��̃`�b�v��.png");
		card = loadImage("�J�[�h�̍��v�l.png");
		dice = loadImage("�o�ڂ̍��v��.png");
		backscreen = loadImage("black.png");
		//��
		titlebgm = loadSound("�^�C�g��BGM.wav");
		gamebgm = loadSound("�Q�[��BGM.wav");
		resultbgm = loadSound("���U���gBGM.wav");
		enter = loadSound("����{�^��SE.wav");
		dicese1 = loadSound("�T�C�R��SE1.wav");
		dicese2 = loadSound("�T�C�R��SE2.wav");
		dicese3 = loadSound("�T�C�R��SE3.wav");
		chipse1 = loadSound("�`�b�vSE1.wav");
		chipse2 = loadSound("�`�b�vSE2.wav");
		cardse1 = loadSound("�J�[�hSE1.wav");
		cardse2 = loadSound("�J�[�hSE2.wav");
		burstse = loadSound("�o�[�X�g.wav");
		winse = loadSound("����.wav");
		losese = loadSound("����.wav");
		drawse = loadSound("�h���[SE.wav");
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
	//�^�C�g��
	int titleimg = 0;
	int startimg = 0;
	const float titlepx = px;
	const float titlepy = py;
	//���[��
	int ruleimg1 = 0;
	int ruleimg2 = 0;
	const float rulepx = px;
	const float rulepy = py;
	//�v���C
	int playimg = 0;
	int playbgm = 0;
	int havechip = 0;
	int givechip = 0;
	int card = 0;
	int dice = 0;
	//���U���g
	int resultimg = 0;
	int kekkaimg = 0;
	const float resultpx = px;
	const float resultpy = py;
	const float playerscore_px = 525.0f;
	const float playerscore_py = 400.0f;
	const float cpuscore_px = 1200.0f;
	const float cpuscore_py = 400.0f;
	//����
	int s_numberimg[10] = { 0 };
	int m_numberimg[5] = { 0 };
	int b_numberimg[10] = { 0 };
	const int vol = 0;
	//player�`�b�v
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
	//player�_�C�X
	int diceimg[6] = { 0 };
	const float playerdice_px = 1550.0f;
	const float playerdice_py = 850.0f;
	//player �J�[�h
	int allcardimg = 0;
	int allburstcardimg = 0;
	const float playercard_px = 525.0f;
	const float playercard_py = 900.0f;
	const float playercardnumber_px = 1000.0f;
	const float playercardnumber_py = 810.0f;
	//cpu�`�b�v
	const float c_rchipimg_px = 250.0f;
	const float c_rchipimg_py = 20.0f;
	const float c_bchipimg_px = 50.0f;
	const float c_bchipimg_py = 20.0f;
	const float c_havechip_px = 300.0f;
	const float c_havechip_py = 230.0f;
	const float c_givechip_px = 270.0f;
	const float c_givechip_py =485.0f;
	//cpu�_�C�X
	const float cpudice_px = 1600.0f;
	const float cpudice_py = 0.0f;
	//cpu �J�[�h
	int cpucardimg = 0;
	const float cpucard_px = 1125.0f;
	const float cpucard_py = 0.0f;
	const float cpucardnumber_px = 1000.0f;
	const float cpucardnumber_py = 218.0f;
	//�Q�[��
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