
#include "AllHeaders.h"
#include "Knight.h"
#include "TextureHelper.h"

#ifndef __INN_H_INCLUDED__
#define __INN_H_INCLUDED__

class Inn{
private:
	int xLocal;
	int yLocal;


public:
	// Variables - Inn Values

	SDL_Texture* tex;
	SDL_Rect rect;
	std::string tag;
	SDL_Renderer* localRenderer;


	// Variables - Spawner Values

	std::vector<Knight> knightVector;


	// Functions - Spawner Functions

	void addKnight(std::string fTag) {
		Knight temp;
		temp.tag = fTag;
		temp.setRect(100, 100);
		knightVector.push_back(temp);
	}
	
	void renderKnightVector(SDL_Renderer* ren) {
		for (int x = 0; x < knightVector.size(); x++) {
			knightVector.at(x).render(ren);
		}
	}
};

#endif