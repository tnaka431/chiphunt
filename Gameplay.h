#pragma once
class box;
class GAMEPLAY {
public:
	void gameplayinit(box*b);
	void gameplayerdraw();
private:
	int GamePlayImg=0;
	int Chip = 0;
	float Px=0;
	float Py=0;
	float PlayerPx = 0;
	float PlayerPy = 0;
	float PcPx = 0;
	float PcPy = 0;

};
