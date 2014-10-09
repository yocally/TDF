
#include "AllHeaders.h"
#include "NPC.h"
#include "TextureHelper.h"

#ifndef __INN_H_INCLUDED__
#define __INN_H_INCLUDED__

class Inn{
private:
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


	// Variables - Spawner Values

	std::vector<NPC> NPCVector;


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
	// Functions - Spawner Functions

	void addNPC(std::string fTag, int fX, int fY) {
		NPC temp;
		temp.tag = fTag;
		temp.setLocal(fX, fY);
		temp.setTarget(Helper::snap(true, 16, Helper::rand(1, 1526)), Helper::snap(true, 16, Helper::rand(1, 826)));
		NPCVector.push_back(temp);
	}
	
	void renderNPCVector(SDL_Renderer* ren) {
		for (int x = 0; x < NPCVector.size(); x++) {
			NPCVector.at(x).render(ren);
		}
	}
};

#endif