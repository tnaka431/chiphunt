#include"CONTAINER.h"
#include"FEED.h"
#include"graphic.h"
#include"COLOR.h"
void FEED::init(CONTAINER* c) {
	FeedImg = c->backscreen;

}
void FEED::feedin() {
	drawImage(FeedImg, 960.0f, 540.0f, 0.0f, COLOR(0.0f, 0.0f, 0.0f, Alpha));
	if (Alpha <= 1.0f) {
		Alpha += 0.07f;
	}
}
void FEED::feedout() {
	drawImage(FeedImg, 960.0f, 540.0f, 0.0f, COLOR(0.0f, 0.0f, 0.0f, Alpha));
	if (Alpha >= 0.0f) {
		Alpha -= 0.07f;
	}
}