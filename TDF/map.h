#pragma once
#include "AllHeaders.h"
#include "Helper.h"
#include "NPC.h"
#include "TextureHelper.h"


#ifndef __WORLD_H_INCLUDED__
#define __WORLD_H_INCLUDED__

class Map {
private:

public:
	std::string tag;
	std::vector<NPC> NPCVector;

	// Refreshes all objects within the map object
	void refresh() {
		renderNPCVector(Texhelp::ren);

	}
	// Functions - Spawner Functions

	void addNPC(std::string fTag, int fX, int fY) {
		NPC temp;
		temp.tag = fTag;
		temp.setLocal(fX, fY);
		temp.xCollide = fX;
		temp.xCollide = fY;
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