
#include "AllHeaders.h"
#include "Background.h"
#include "GameTextures.h"
#include "Inn.h"
#include "Knight.h"
#include "TextureHelper.h"


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
	setGlobalRen(gRenderer);
	mainBackground.setTex(loadTexture("rec/background.png", gRenderer));
	inn1.addKnight("knight1");
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
			}
		}
		refresh();
	}
	return 0;
}