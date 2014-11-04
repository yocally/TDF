#pragma once
#include "AllHeaders.h"
#include "GameTextures.h"
#include "Helper.h"

#ifndef __NPC_H_INCLUDED__
#define __NPC_H_INCLUDED__

class NPC;
// NPChelper Declarations
namespace NPChelper{
	std::vector<NPC> NPCVector;

	void addNPC(std::string ftag, int fX, int fY);

	void renderNPCVector(SDL_Renderer* ren);
}


// NPC Declarations
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
	bool collderec0 = true, collderec1 = true, collderec2 = true, collderec3 = true, collderec4 = true, collderec5 = true, collderec6 = true, collderec7 = true;



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

		void colltest() {
			for (int x = 0; x < NPChelper::NPCVector.size(); x++) {
				int xCollidel = NPChelper::NPCVector.at(x).xCollide;
				int yCollidel = NPChelper::NPCVector.at(x).yCollide;
				if (xCollidel == xCollide + 32){// == 0
					collderec0 = true;
					printf("0");
				}
				else {
					collderec0 = false;
				}
				if (yCollidel == yCollide - 32) {//derec == 1
					collderec1 = true;
					printf("1");
				}
				else {
					collderec1 = false;
				}
				if (yCollidel == yCollide + 32) {//derec == 2
					collderec2 = true;
					printf("2");
				}
				else {
					collderec2 = false;
				}
				if (xCollidel == xCollide - 32) {//derec == 3
					collderec3 = true;
					printf("3");
				}
				else {
					collderec3 = false;
				}
				if (xCollidel == xCollide - 32 && yCollidel == yCollide - 32) {//derec == 4
					collderec4 = true;
					printf("4");
				}
				else {
					collderec4 = false;
				}
				if (xCollidel == xCollide + 32 && yCollidel == yCollide - 32) {//derec == 5
					collderec5 = true;
					printf("5");
				}
				else {
					collderec5 = false;
				}
				if (xCollidel == xCollide - 32 && yCollidel == yCollide + 32) {//derec == 6
					collderec6 = true;
					printf("6");
				}
				else {
					collderec6 = false;
				}
				if (xCollidel == xCollide + 32 && yCollidel == yCollide + 32) {//derec == 7
					collderec7 = true;
					printf("7");
				}
				else {
					collderec7 = false;
				}
			}
		}

		void collreact() {
			int derp = Helper::rand(0,1);
			if (derec == 0){
				if (collderec0 == true) {
					if (derp == 0) {
						derec = 6;
						xCollide -= 32;
						yCollide += 32;
					}
					if (derp == 1) {
						derec = 7;
						xCollide += 32;
						yCollide += 32;
					}
				}
			}
			if (derec == 1) {
				if (collderec1 == true) {
					if (derp == 0) {
						derec = 4;
						xCollide -= 32;
						yCollide -= 32;
					}
					if (derp == 1) {
						derec = 5;
						xCollide += 32;
						yCollide -= 32;
					}
				}
			}
			if (derec == 2) {
				if (collderec2 == true) {
					if (derp == 0) {
						derec = 5;
						xCollide += 32;
						yCollide -= 32;
					}
					if (derp == 1) {
						derec = 7;
						xCollide += 32;
						yCollide += 32;
					}
				}
			}
			if (derec == 3) {
				if (collderec3 == true) {
					if (derp == 0) {
						derec = 4;
						xCollide -= 32;
						yCollide -= 32;
					}
					if (derp == 1) {
						derec = 6;
						xCollide -= 32;
						yCollide += 32;
					}
				}
			}
			if (derec == 4) {
				if (collderec4 == true) {
					if (derp == 0) {
						derec = 3;
						xCollide -= 32;
					}
					if (derp == 1) {
						derec = 1;
						yCollide -= 32;
					}
				}
			}
			if (derec == 5) {
				if (collderec5 == true) {
					if (derp == 0) {
						derec = 1;
						yCollide -= 32;
					}
					if (derp == 1) {
						derec = 2;
						xCollide += 32;
					}
				}
			}
			if (derec == 6) {
				if (collderec6 == true) {
					if (derp == 0) {
						derec = 0;
						yCollide += 32;
					}
					if (derp == 1) {
						derec = 3;
						xCollide -= 32;
					}
				}
			}
			if (derec == 7) {
				if (collderec7 == true) {
					if (derp == 0) {
						derec = 2;
						xCollide += 32;
					}
					if (derp == 1) {
						derec = 0;
						yCollide += 32;
					}
				}
			}
		}

	void Path(int xT, int yT){
		if (xT != xLocal || yT != yLocal) {
			if (xT > xLocal && yT > yLocal) {
				derec = 7;
				xCollide += 32;
				yCollide += 32;
			}
			if (xT < xLocal && yT > yLocal) {
				derec = 6;
				xCollide -= 32;
				yCollide += 32;
			}
			if (xT > xLocal && yT < yLocal) {
				derec = 5;
				xCollide += 32;
				yCollide -= 32;
			}
			if (xT < xLocal && yT < yLocal) {
				derec = 4;
				xCollide -= 32;
				yCollide -= 32;
			}
			if (xT < xLocal && yT == yLocal) {
				derec = 3;
				xCollide -= 32;
			}
			if (xT > xLocal && yT == yLocal) {
				derec = 2;
				xCollide += 32;
			}
			if (xT == xLocal && yT < yLocal) {
				derec = 1;
				yCollide -= 32;
			}
			if (xT == xLocal && yT > yLocal) {
				derec = 0;
				yCollide += 32;
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
				if (NPCsteps < 32){
					moveind();
					NPCsteps++;
				}
				else {
					colltest();
					Path(xTarget, yTarget);
					collreact();
					NPCsteps = 0;
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


// NPChelper Definitions
void NPChelper::addNPC(std::string ftag, int fX, int fY) {
	NPC temp;
	temp.tag;
	temp.setLocal(fX, fY);
	temp.xCollide = fX;
	temp.yCollide = fX;
	temp.setTarget(Helper::snap(true, 32, Helper::rand(1, 1526)), Helper::snap(true, 32, Helper::rand(1, 826)));
	NPCVector.push_back(temp);
}
void NPChelper::renderNPCVector(SDL_Renderer* ren) {
	for (int x = 0; x < NPCVector.size(); x++) {
		NPCVector.at(x).render(ren);
	}
}

#endif