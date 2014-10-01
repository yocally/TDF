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


public:
	SDL_Texture* tex = loadTexture("rec/Knight.png", globalRen);
	SDL_Rect rect;
	std::string tag;


	void setTex(SDL_Texture* loadedTex) {
		tex = loadedTex;
	}

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
		knightClip.x = 64;
		knightClip.y = 0;
		knightClip.h = 64;
		knightClip.w = 64;
	}

	void render(SDL_Renderer* ren) {
		refresh();
		SDL_RenderCopy(ren, tex, &knightClip, &returnRect());
	}
};
#endif