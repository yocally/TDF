
#include "AllHeaders.h"
#include "GameTextures.h"

#ifndef __BACKGROUND_H_INCLUDED__
#define __BACKGROUND_H_INCLUDED__

class Background {
private:
	int screenHight;
	int screenWidth;


public:

	void setScreenSize(int x, int y) {
		screenHight = y;
		screenWidth = x;
	}

	void render(SDL_Renderer* ren) {
		SDL_RenderCopy(ren, G::background, NULL, NULL);
	}
};

#endif