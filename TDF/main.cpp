#include "AllHeaders.h"
#include "Background.h"
#include "GameTextures.h"
#include "Inn.h"
#include "NPC.h"
#include "TextureHelper.h"
#include "Helper.h"


// Function Redef

bool init();
void loadMedia();
void close();
void refresh();


// Globals

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Background mainBackground;
Inn inn1;


// Functions

bool init() {
	gWindow = SDL_CreateWindow("The Discovery Forge", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		printf("Window could not be created!\n SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL) {
			printf("Renderer could not be created!\n SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else {
			SDL_SetRenderDrawColor(gRenderer, 86, 165, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)) {
				printf("SDL_image could not initialize! SDL_image error: %s\n", IMG_GetError());
				return false;
			}
		}
	}
	return true;
}

void loadMedia() {
	Texhelp::setRen(gRenderer);
	Texhelp::loadMedia(Texhelp::ren);
	for (int x = 0; x < 20; x++) {
		inn1.addNPC("Knight" + std::to_string(x), Helper::rand(1, 580), Helper::rand(1, 420));
		std::cout << "Knight" + std::to_string(x) << std::endl;
	}
}

void close() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

void refresh() {
	SDL_RenderClear(gRenderer);
	mainBackground.render(gRenderer);
	inn1.renderKnightVector(gRenderer);
	inn1.setRect(220, 60);
	inn1.render(Texhelp::ren);
	SDL_RenderPresent(gRenderer);
}

int main(int argc, char* argv[]) {
	if (!init()) {
		printf("Init failed");
	}
	loadMedia();
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			};
		}
		refresh();
	}
	return 0;
}