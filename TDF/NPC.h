#pragma once
#include "AllHeaders.h"
#include "GameTextures.h"
#include "Helper.h"
#include "map.h"

#ifndef __NPC_H_INCLUDED__
#define __NPC_H_INCLUDED__

class NPC {
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
	int xLocal, yLocal;
	int xTarget, yTarget;
	int heightLocal = 64, widthLocal = 64;
	SDL_Rect knightClip;
	bool isMoving = true;
	bool firstRun = true;
	bool rorl = true;
	

public:

	int xCollide;
	int yCollide;
	int speed;
	SDL_Rect rect;
	std::string tag;
	std::string alignment;

	void test() {
		std::cout << xCollide << " " << yCollide << std::endl;
	}

	void setLocal(int x, int y) {
		xLocal = x;
		yLocal = y;
	}

	void setTarget(int x, int y) {
		xTarget = x;
		yTarget = y;
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
		AI("ground", "knight");
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

	void colltest(){
		for (int x = 0; x < map1.NPCVector.size(); x++) {
			int xCollidel = map1.NPCVector.at(x).xCollide;
			int yCollidel = map1.NPCVector.at(x).yCollide;
			if (derec == 0){
				yLocal += speed;
			}
			if (derec == 1) {
				yLocal -= speed;
			}
			if (derec == 2) {
				xLocal += speed;
			}
			if (derec == 3) {
				xLocal -= speed;
			}
			if (derec == 4) {
				xLocal -= speed;
				yLocal -= speed;
			}
			if (derec == 5) {
				xLocal += speed;
				yLocal -= speed;
			}
			if (derec == 6) {
				xLocal -= speed;
				yLocal += speed;
			}
			if (derec == 7) {
				xLocal += speed;
				yLocal += speed;
			}
		}
	}

	void Path(int xT, int yT){
		if (xT != xLocal || yT != yLocal) {
			if (xT > xLocal && yT > yLocal) {
				derec = 7;
				xCollide += 16;
				xCollide += 16;
			}
			if (xT < xLocal && yT > yLocal) {
				derec = 6;
				xCollide -= 16;
				xCollide += 16;
			}
			if (xT > xLocal && yT < yLocal) {
				derec = 5;
				xCollide += 16;
				xCollide -= 16;
			}
			if (xT < xLocal && yT < yLocal) {
				derec = 4;
				xCollide -= 16;
				xCollide -= 16;
			}
			if (xT < xLocal && yT == yLocal) {
				derec = 3;
				xCollide -= 16;
			}
			if (xT > xLocal && yT == yLocal) {
				derec = 2;
				xCollide += 16;
			}
			if (xT == xLocal && yT < yLocal) {
				derec = 1;
				yCollide -= 16;
			}
			if (xT == xLocal && yT > yLocal) {
				derec = 0;
				yCollide += 16;
			}
		}
		if (xT == xLocal && yT == yLocal) {
			derec = 8;
		}
	}
	

	void moveind(){
		if (derec == 0){
			yLocal += speed;
		}
		if (derec == 1) {
			yLocal -= speed;
		}
		if (derec == 2) {
			xLocal += speed;
		}
		if (derec == 3) {
			xLocal -= speed;
		}
		if (derec == 4) {
			xLocal -= speed;
			yLocal -= speed;
		}
		if (derec == 5) {
			xLocal += speed;
			yLocal -= speed;
		}
		if (derec == 6) {
			xLocal -= speed;
			yLocal += speed;
		}
		if (derec == 7) {
			xLocal += speed;
			yLocal += speed;
		}
	}

	void AI(std::string AItype, std::string NPCtype) {
		thinkEndTime = thinkStartTime + 100;
		if (thinkEndTime <= SDL_GetTicks()) {
			if (thought == 0) /*// Stop and thnink. //*/ {
				thought = 1;
			}
			if (thought == 1) /*// Walk. //*/ {
				if (NPCsteps < 16){
					moveind();
					NPCsteps++;
				}
				else {
					NPCsteps = 0;
					Path(xTarget, yTarget);
				}
				thinkStartTime = SDL_GetTicks();
			}
			if (thought == 2) /*//  //*/ {
				thought = 0;
			}
		}
	}


	void animate() {
		if (isMoving) {
			if (firstRun) {
				firstRun = false;
				animStartTime = SDL_GetTicks();
				thinkStartTime = SDL_GetTicks();
			}

			animEndTime = animStartTime + speed * 200;
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