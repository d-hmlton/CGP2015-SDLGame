#include "Battle.h"

//Constructor
Battle::Battle(Window* window) {
	_window = window;
	this->Init();
}

void Battle::Init() {
	SDL_Renderer* renderer = _window->getRenderer();
	IMG_Init(IMG_INIT_PNG);

	char* path = SDL_GetBasePath();
	char armourBasePath[200]; strcpy_s(armourBasePath, path); strcat_s(armourBasePath, "content\\armourBase.png");
	char armourA1Path[200]; strcpy_s(armourA1Path, path); strcat_s(armourBasePath, "content\\armourA1.png");
	char armourA2Path[200]; strcpy_s(armourA2Path, path); strcat_s(armourBasePath, "content\\armourA2.png");
	char armourA3Path[200]; strcpy_s(armourA3Path, path); strcat_s(armourBasePath, "content\\armourA3.png");

	_armourBase = IMG_LoadTexture(renderer, armourBasePath);
	_armourA1 = IMG_LoadTexture(renderer, armourA1Path);
	_armourA2 = IMG_LoadTexture(renderer, armourA2Path);
	_armourA3 = IMG_LoadTexture(renderer, armourA3Path);

	IMG_Quit();
}