#include"framework.h"
#include"window.h"
#include"GAME.h"

void gmain() {
	GAME* game = new GAME;
	while (msgProc()) {
		game->Proc();
	}
	delete game;
}