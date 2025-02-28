#pragma once

#include <iostream>
#include <SDL.H> //sdl2
#include "Window.h"
#include "SZ_Timer.h"
#include "Spaceship.h"

#define MAX_KEYS (256)

class SZ_GameWorld {
private:
	//Global values for the game loop
	SZ_Timer _aTimer;
	const float _DELTA_TIME = 66.67f; //How many milliseconds each frame is allowed
	int _frames;
	bool _done = false;
	bool _pause = false;

	Window* _window;
	Spaceship* _firstShip;

public:
	SZ_GameWorld();

	int Init();

	void Loop();

	void Input();
	void Update();
	void Render();

	void End();
};