#include <SDL.h>
#include <stdio.h>
#include <string>

class Knight{
private:
	int xLocal;
	int yLocal;
	int heightLocal = 64;
	int widthLocal = 64;


public:
	SDL_Texture* tex;
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
		re.x = xLocal;
		re.y = yLocal;
		re.h = heightLocal;
		re.w = widthLocal;
		return re;
	}

};