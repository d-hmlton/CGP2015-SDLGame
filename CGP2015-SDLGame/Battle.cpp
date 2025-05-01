#include "Battle.h"

//Constructor
Battle::Battle(Window* window) {
	_window = window;
	this->Init();
}

void Battle::Init() {
	_health = 60;
	_damageBuffer = -1;

	SDL_Renderer* renderer = _window->getRenderer();
	IMG_Init(IMG_INIT_PNG);

	char* path = SDL_GetBasePath();
	char armourBasePath[200]; strcpy_s(armourBasePath, path); strcat_s(armourBasePath, "content\\armourBase.png");
	char armourA1Path[200]; strcpy_s(armourA1Path, path); strcat_s(armourA1Path, "content\\armourA1.png");
	char armourA2Path[200]; strcpy_s(armourA2Path, path); strcat_s(armourA2Path, "content\\armourA2.png");
	char armourA3Path[200]; strcpy_s(armourA3Path, path); strcat_s(armourA3Path, "content\\armourA3.png");
	char popUpPath[200]; strcpy_s(popUpPath, path); strcat_s(popUpPath, "content\\battlePopUp.png");
	char controlsPath[200]; strcpy_s(controlsPath, path); strcat_s(controlsPath, "content\\battleControls.png");
	char damagePPath[200]; strcpy_s(damagePPath, path); strcat_s(damagePPath, "content\\battleDamageP.png");
	char damageEPath[200]; strcpy_s(damageEPath, path); strcat_s(damageEPath, "content\\battleDamageE.png");
	char youWinPath[200]; strcpy_s(youWinPath, path); strcat_s(youWinPath, "content\\battleyouWin.png");

	_armourBase = IMG_LoadTexture(renderer, armourBasePath);
	SDL_Texture* armourA1 = IMG_LoadTexture(renderer, armourA1Path); _armourAnim.push_back(armourA1);
	SDL_Texture* armourA2 = IMG_LoadTexture(renderer, armourA2Path); _armourAnim.push_back(armourA2);
	SDL_Texture* armourA3 = IMG_LoadTexture(renderer, armourA3Path); _armourAnim.push_back(armourA3);
	_popUp = IMG_LoadTexture(renderer, popUpPath);
	_controls = IMG_LoadTexture(renderer, controlsPath);
	_damageP = IMG_LoadTexture(renderer, damagePPath);
	_damageE = IMG_LoadTexture(renderer, damageEPath);
	_youWin = IMG_LoadTexture(renderer, youWinPath);

	IMG_Quit();
}

void Battle::StartBattle() {
	_battleTimer.resetTicksTimer();
}

int Battle::UpdateBattle() {
	if (_health < 1) { _battleTimer.resetTicksTimer(); return 1; }
	return 0;
}

int Battle::EndBattle() {
	if (_battleTimer.getTicks() > 2000.00f) { return 1; }
	return 0;
}

void Battle::TakeDamage(int damage) {
	_health -= damage;
	if (_damageBuffer == -1) { _damageBuffer = _battleTimer.getTicks(); }
}

void Battle::RenderBattle() {
	if (_health < 1) {
		_window->renderSprite(_youWin);
		return;
	}

	_window->renderSprite(_armourBase);

	int milliseconds = _battleTimer.getTicks(); //Efficiency
	int anim = 0;
	if ((milliseconds % 5000) > 3500) { anim = 1; }
	if ((milliseconds % 5000) > 4000) { anim = 2; }
	_window->renderSprite(_armourAnim[anim]);

	//damage to player
	if (anim == 2) {
		_window->renderSprite(_damageP);
	}

	//damage to enemy
	if (_damageBuffer != -1) {
		if ((_damageBuffer + 1000) > milliseconds) {
			_window->renderSprite(_damageE);
		}
		if ((milliseconds - _damageBuffer) > 1500) {
			_damageBuffer = -1;
		}
	}

	//pop up!
	if (milliseconds < 1000) {
		_window->renderSprite(_popUp);
	}
	//controls
	else {
		_window->renderSprite(_controls);
	}
}