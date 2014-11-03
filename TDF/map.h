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

	}
};
#endif