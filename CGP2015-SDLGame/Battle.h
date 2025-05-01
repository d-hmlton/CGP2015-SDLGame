#pragma once

#include <string>
#include <SDL.H>
#include <SDL_image.h>

#include "Window.h"
#include "SZ_Timer.h"

class Battle
{
private:
	Window* _window;
	SZ_Timer _battleTimer;

public:
	Battle(Window* window);

	//Sprites
	SDL_Texture* _armourBase;
	SDL_Texture* _armourA1;
	SDL_Texture* _armourA2;
	SDL_Texture* _armourA3;

	SDL_Texture* _popUp;
	SDL_Texture* _controls;
	SDL_Texture* _damageP;
	SDL_Texture* _damageE;
	SDL_Texture* _youWin;

	void Init();

	void BattleStart();

	void BattleUpdate();

};

