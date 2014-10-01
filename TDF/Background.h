
#include "ExternalHeaders.h"

class Background {
private:
	SDL_Texture* tex;
	int screenHight;
	int screenWidth;


public:
	void setTex(SDL_Texture* loadedTex) {
		tex = loadedTex;
	}

	SDL_Texture* getTex() {
		return tex;
	}

	void setScreenSize(int x, int y) {
		screenHight = y;
		screenWidth = x;
	}

	void render(SDL_Renderer* ren) {
		SDL_RenderCopy(ren, tex, NULL, NULL);
	}
};