
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

// Function Redef

bool init();
void loadMedia();
SDL_Surface* loadSurface(std::string path);
void refresh();

// Classes

class Knight {
	int xLocal;
	int yLocal;

public:
	SDL_Surface* surf = loadSurface("rec/char.png");
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


// Globals

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gBackground = NULL;
bool quit = false;
SDL_Event e;
Knight mainKnight;

// Functions

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize!\nSDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else {
		gWindow = SDL_CreateWindow("The Discovery Forge", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Failed to create window\nSDL_Error: %s\n", SDL_GetError());
			return false;
		}
		else {
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)) {
				printf("SDL_image could not initialize!\nSDL_image error: %s\n", IMG_GetError());
				return false;
			}
			else {
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return true;
}

void loadMedia() {
	gBackground = loadSurface("rec/background.png");
}

SDL_Surface* loadSurface(std::string path) {
	// WARNING! Potential errors
	SDL_Surface* optimizedSurface = NULL;
	SDL_RWops* loadedSurface_rwops = SDL_RWFromFile(path.c_str(), "rb");
	SDL_Surface* loadedSurface = IMG_LoadPNG_RW(loadedSurface_rwops);
	if (loadedSurface == NULL) {
		printf("Unable to load image %s\nSDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else {
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s\nSDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	
	return optimizedSurface;
}

void refresh() {
	SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL);
	mainKnight.setRect(100, 100);
	SDL_BlitSurface(mainKnight.surf, NULL, gScreenSurface, &mainKnight.getRect());
	SDL_UpdateWindowSurface(gWindow);
}

int main(int argc, char* args[]) {
	if (!init()) {
		printf("Init failed");
	}
	mainKnight.setRect(100, 100);
	loadMedia();
	refresh();
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	return 0;
}