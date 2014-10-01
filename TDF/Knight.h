#include "AllHeaders.h"
#include "GameTextures.h"

#ifndef __KNIGHT_H_INCLUDED__
#define __KNIGHT_H_INCLUDED__

class Knight{
private:
	int sleepTime;
	int animStartTime;
	int animEndTime;
	int derec = 0;
	int frame = 0;
	int size = 63;
	int xLocal;
	int yLocal;
	int heightLocal = 64;
	int widthLocal = 64;
	SDL_Rect knightClip;
	bool isMoving = true;
	bool firstRun = true;
	bool rorl = true;

public:
	
	SDL_Rect rect;
	std::string tag;



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
			if (rorl == true) {
				if (frame < 2) {
					frame++;
				}
				else {
					rorl = false;
				}
			}
			if (rorl == false) {
				if (frame < 0) {
					frame--;
				}
				else {
					rorl = true;
				}
			}

			animStartTime = SDL_GetTicks();
		}
		knightClip.x = frame * size;
		knightClip.y = derec * size;
		knightClip.h = size;
		knightClip.w = size;
	}

	void render(SDL_Renderer* ren) {
		refresh();
		SDL_RenderCopy(ren, G::knight, &knightClip, &returnRect());
	}
};
#endif