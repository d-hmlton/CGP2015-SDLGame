#pragma once

#include <iostream>
#include <vector>
#include <SDL.H> //sdl2
#include <SDL_image.h>

#include "Window.h"
#include "SZ_Timer.h"
#include "Mansion.h"
#include "TimerUI.h"
#include "Battle.h"

#define MAX_KEYS (256)

class SZ_GameWorld {
private:
	//Global values for the game loop
	SZ_Timer _aTimer;
	SZ_Timer _inputTimer;
	const float _DELTA_TIME = 66.67f; //How many milliseconds each frame is allowed
	int _frames;
	bool _done = false;
	bool _pause = false;
	int _battleState = 0; //0 = battle to come, 1 = battle ongoing, 2 = battle over

	Window* _window;
	Mansion* _mansion;
	TimerUI* _timerUI;
	Battle* _battle;
	int _shipListSize; //Asking for the size of shipList constantly is inefficient

public:
	SZ_GameWorld();

	int Init();

	void Loop();

	void Input();
	void Update();
	void Render();

	void End();
};