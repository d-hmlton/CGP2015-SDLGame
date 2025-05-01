#pragma once

#include <vector>
#include <SDL.H>
#include <SDL_image.h>

#include "Window.h"
#include "SZ_Timer.h"

class TimerUI
{
private:
	Window* _window;
	const float* _DELTA_TIME;
	SZ_Timer _gameTimer;
	int _timerLength;

	//Sprites
	SDL_Texture* _timerBase;
	std::vector<SDL_Texture*> _leftNumbers;
	std::vector<SDL_Texture*> _rightNumbers;


public:
	TimerUI(Window* window);

	void Init();

	void BonusTime();

	int UpdateTimer();
	
	void RenderTimer();

	SZ_Timer GetTimer() { return _gameTimer; }
};

