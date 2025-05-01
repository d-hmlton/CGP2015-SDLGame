#include "Splash.h"

//Constructor
Splash::Splash(Window* window) {
	_window = window;
	this->Init();
}

void Splash::Init() {
	SDL_Renderer* renderer = _window->getRenderer();
	IMG_Init(IMG_INIT_PNG);

	char* path = SDL_GetBasePath();
	char splashPath[200]; strcpy_s(splashPath, path); strcat_s(splashPath, "content\\splash.png");
	_splash = IMG_LoadTexture(renderer, splashPath);

	IMG_Quit();

	_splashTimer.resetTicksTimer();
}

void Splash::SplashLoop() {
	while (_splashTimer.getTicks() < 5000) {
		//Drawing a square for every frame 
		_window->setColour(0, 0, 0, 255); _window->clearScreen();

		//Checks current screen size and sets render params accordingly - necessary for everything after
		_window->screenCheck();

		_window->renderSprite(_splash);

		_window->presentToScreen();
	}

	return;
}