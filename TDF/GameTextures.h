
#include "AllHeaders.h"
#include "TextureHelper.h"

#ifndef __GAMETEXTURES_H_INCLUDED__
#define __GAMETEXTURES_H_INCLUDED__

namespace G{
	SDL_Renderer* ren;
	SDL_Texture* background;
	SDL_Texture* knight;
	SDL_Texture* inn;
	
	void setRen(SDL_Renderer* loadedRen) {
		ren = loadedRen;
	}

	void loadMedia(SDL_Renderer* loadedRen) {
		background = loadTexture("rec/background.png", loadedRen);
		knight = loadTexture("rec/Knight.png", loadedRen);
		inn = loadTexture("rec/House.png", loadedRen);
	}

	int rand(int min, int max) {
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(eng);
	}
}
#endif