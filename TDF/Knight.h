#include "AllHeaders.h"
#include "GameTextures.h"

#ifndef __KNIGHT_H_INCLUDED__
#define __KNIGHT_H_INCLUDED__

class Knight{
private:
	int xLocal;
	int yLocal;
	int heightLocal = 64;
	int widthLocal = 64;
	SDL_Rect knightClip;
	bool isMoving = true;
	bool firstRun = true;
	int sleepTime;
	int animStartTime;
	int animEndTime;


public:
	
	SDL_Rect rect;
	std::string tag;
	int derec;
	int frame;


	void setRect(int x, int y) {
		xLocal = x;
		yLocal = y;
	}

	SDL_Rect returnRect() {
		SDL_Rect re;
		re.y = yLocal;
		re.x = xLocal;
		re.h = heightLocal;
		re.w = widthLocal;
		return re;
	}

	void refresh() {
		if (firstRun) {
			firstRun = false;
			animStartTime = SDL_GetTicks();
		}
		animEndTime = animStartTime + 200;
		if (animEndTime <= SDL_GetTicks()) {
			if (frame < 2) {
				frame++;
			}
			else {
				frame = 0;
			}
			animStartTime = SDL_GetTicks();
		}
		knightClip.x = frame * 63;
		knightClip.y = derec * 63;
		knightClip.h = 64;
		knightClip.w = 64;
	}

	void render(SDL_Renderer* ren) {
		refresh();
		SDL_RenderCopy(ren, G::knight, &knightClip, &returnRect());
	}
};
#endif