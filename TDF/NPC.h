#include "AllHeaders.h"
#include "GameTextures.h"
#include "Helper.h"

#ifndef __NPC_H_INCLUDED__
#define __NPC_H_INCLUDED__

class NPC{
private:
	int thinkStartTime;
	int thinkEndTime;
	int animStartTime;
	int animEndTime;
	int NPCsteps = 0;
	int thought = 0;
	int derec = Helper::rand(0, 7);
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
	std::string alignment;

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
		AI("grownd", "knight");
		animate();
		knightClip.x = frame * size;
		knightClip.y = derec * size;
		knightClip.h = size;
		knightClip.w = size;
	}

	void render(SDL_Renderer* ren) {
		refresh();
		SDL_RenderCopy(ren, Texhelp::knight, &knightClip, &returnRect());
	}

	void moveind(){
		if (derec == 0){
			yLocal = yLocal + 2;
		}
		if (derec == 1){
			yLocal = yLocal - 2;
		}
		if (derec == 2){
			xLocal = xLocal + 2;
		}
		if (derec == 3){
			xLocal = xLocal - 2;
		}
		if (derec == 4){
			xLocal = xLocal - 2;
			yLocal = yLocal - 2;
		}
		if (derec == 5){
			xLocal = xLocal + 2;
			yLocal = yLocal - 2;
		}
		if (derec == 6){
			xLocal = xLocal - 2;
			yLocal = yLocal + 2;
		}
		if (derec == 7){
			xLocal = xLocal + 2;
			yLocal = yLocal + 2;
		}
	}

	void AI(std::string AItype, std::string NPCtype){
		thinkEndTime = thinkStartTime + 200;
		if (thinkEndTime <= SDL_GetTicks()) {
			if (thought == 0){
				thought = 1;
			}
			if (thought == 1){

				if (NPCsteps < 10){
					moveind();
					NPCsteps++;
				}
				else {
					NPCsteps = 0;
					derec = Helper::rand(0, 7);
				}
			}
			thinkStartTime = SDL_GetTicks();
		}
	}


	void animate() {
		if (isMoving) {
			if (firstRun) {
				firstRun = false;
				animStartTime = SDL_GetTicks();
				thinkStartTime = SDL_GetTicks();
			}

			animEndTime = animStartTime + 200;
			if (animEndTime <= SDL_GetTicks()) {
				if (isMoving == true) {
					if (rorl == true) {
						if (frame < 2) {
							frame++;
						}
						else {
							rorl = false;
						}
					}
					if (rorl == false) {
						if (frame > 0) {
							frame--;
						}
						else {
							frame++;
							rorl = true;
						}
					}
				}
				else {
					frame = 1;
				}
				animStartTime = SDL_GetTicks();
			}
		}
	}
};
#endif