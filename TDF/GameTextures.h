#pragma once
#include "AllHeaders.h"
#include "TextureHelper.h"

#ifndef __GAMETEXTURES_H_INCLUDED__
#define __GAMETEXTURES_H_INCLUDED__

namespace Texhelp{
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
}
#endif