
#include "ExternalHeaders.h"
#include "InternalHeaders.h"


// Function Redef

bool init();
void loadMedia();
SDL_Texture* loadTexture(std::string path);
void close();
void refresh();


// Globals

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Background mainBackground;
Knight knight1;


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
	mainBackground.setTex(loadTexture("rec/background.png"));
	knight1.setTex(loadTexture("rec/Knight.png"));
}

SDL_Texture* loadTexture(std::string path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: $s\n", path.c_str(), IMG_GetError());
	}
	else {
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL_Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
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
	knight1.render(gRenderer);
	SDL_RenderPresent(gRenderer);
}

int main(int argc, char* argv[]) {
	if (!init()) {
		printf("Init failed");
	}
	loadMedia();
	knight1.setRect(100, 100);
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