#pragma once

#include <string>
#include <vector>
#include <SDL.H>
#include <SDL_image.h>

#include "Window.h"
#include "SZ_Timer.h"

class Battle
{
private:
	Window* _window;
	SZ_Timer _battleTimer;
	int _health;
	int _damageBuffer;

public:
	Battle(Window* window);

	//Sprites
	SDL_Texture* _armourBase;
	std::vector<SDL_Texture*> _armourAnim;

	SDL_Texture* _popUp;
	SDL_Texture* _controls;
	SDL_Texture* _damageP;
	SDL_Texture* _damageE;
	SDL_Texture* _youWin;

	void Init();

	void StartBattle();
	int UpdateBattle();
	int EndBattle();

	void TakeDamage(int damage);

	void RenderBattle();
};

