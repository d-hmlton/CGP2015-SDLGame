#pragma once

#include <SDL.H>
#include <SDL_image.h>

#include "Window.h"
#include "SZ_Timer.h"

class Splash
{
private:
	Window* _window;
	SZ_Timer _splashTimer;
	SDL_Texture* _splash;

public:
	Splash(Window* window);
	void Init();

	void SplashLoop();
};

