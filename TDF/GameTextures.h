
#include "AllHeaders.h"
#include "TextureHelper.h"

#ifndef __GAMETEXTURES_H_INCLUDED__
#define __GAMETEXTURES_H_INCLUDED__

SDL_Renderer* globalRen;

void setGlobalRen(SDL_Renderer* ren) {
	globalRen = ren;
}
#endif