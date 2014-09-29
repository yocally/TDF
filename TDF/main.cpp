#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

// Function Redef

bool init();
void loadMedia();
SDL_Texture* loadTexture(std::string path);
void close();
void refresh();


// Globals

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gBackground = NULL;
SDL_Texture* gChar = NULL;


// Classes

class Knight{
	int xLocal;
	int yLocal;

public:
	SDL_Texture* tex = gChar;


	void setTex(SDL_Texture* loadedTex) {
		tex = loadedTex;
	}

	void setRect(int x, int y) {
		xLocal = x;
		yLocal = y;
	}

	SDL_Rect getRect() {
		SDL_Rect re;
		re.x = xLocal;
		re.y = yLocal;
		return re;
	}

};


// Class Global Def

Knight knight;


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
	gBackground = loadTexture("rec/background.png");
	gChar = loadTexture("rec/char.png");
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
	SDL_DestroyTexture(gBackground);
	gBackground = NULL;
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

void refresh() {
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gBackground, NULL, NULL);
	SDL_RenderCopy(gRenderer, knight.tex, NULL, &knight.getRect());
	SDL_RenderPresent(gRenderer);
}

int main(int argc, char* argv[]) {
	if (!init()) {
		printf("Init failed");
	}
	loadMedia();
	knight.setTex(gChar);
	knight.setRect(100, 100);
	bool quit = false;
	SDL_Event e;S
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