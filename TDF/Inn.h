#pragma once
#include "AllHeaders.h"
#include "NPC.h"
#include "TextureHelper.h"

#ifndef __INN_H_INCLUDED__
#define __INN_H_INCLUDED__

class Inn{
private:
	int npcnumber = 0;
	int xLocal;
	int yLocal;
	int heightLocal = 128;
	int widthLocal = 192;


public:
	// Variables - Inn Values

	SDL_Texture* tex;
	SDL_Rect rect;
	std::string tag;
	SDL_Renderer* localRenderer;

	// Functions - Inn Functions

	void render(SDL_Renderer* loadedRen) {
		refresh();
		//SDL_RenderCopy(loadedRen, Texhelp::inn, NULL, &rect);
	}

	void setRect(int x, int y) {
		xLocal = x;
		yLocal = y;
	}

	void refresh() {
		rect.x = xLocal;
		rect.y = yLocal;
		rect.h = heightLocal;
		rect.w = widthLocal;

	}
};

#endif