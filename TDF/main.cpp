#include "AllHeaders.h"
#include "Background.h"
#include "GameTextures.h"
#include "Map.h"
#include "Inn.h"
#include "NPC2.h"
#include "TextureHelper.h"
#include "Helper.h"



// Function Redef

bool init();
void loadMedia();
void close();
void refresh();
void printList();


// Globals

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Background mainBackground;


// Functions

bool init() {
	gWindow = SDL_CreateWindow("The Discovery Forge", 20, 20, 1600, 900, SDL_WINDOW_SHOWN);
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
	for (int x = 0; x < 4; x++) {
		NPChelper::addNPC("Knight" + std::to_string(x), Helper::snap(true, 16, Helper::rand(1, 1526)), Helper::snap(true, 16, Helper::rand(1, 826)));
		std::cout << "Knight" + std::to_string(x) + " " << std::endl;
		NPChelper::NPCVector.at(x).speed = 1;
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
	SDL_RenderPresent(gRenderer);
}

void printList() {
	for (int x = 0; x < NPChelper::NPCVector.size(); x++) {
		printf("Tag:        %s\n", map1.NPCVector.at(x).tag);
		printf("xCollide:   %d\n", map1.NPCVector.at(x).xCollide);
		printf("yCollide:   %d\n", map1.NPCVector.at(x).yCollide);
	}
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
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				for (int a = 0; a < map1.NPCVector.size(); a++) {
					map1.NPCVector.at(a).setTarget(Helper::snap(true, 16, x), Helper::snap(true, 16, y));
				}
			}
			if (e.type == SDL_KEYDOWN) {
				printList();
			}
		}
		refresh();
	}
	return 0;
}