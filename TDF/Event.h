#include "AllHeaders.h"





void hEvents(SDL_Event e){
	if (e.type == SDL_QUIT) {
		quit = true;
	}
}