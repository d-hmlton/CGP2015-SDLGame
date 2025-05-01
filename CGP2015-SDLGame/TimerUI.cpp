#include "TimerUI.h"

//Constructor
TimerUI::TimerUI(Window* window, const float* DELTA_TIME) {
	_window = window;
	_DELTA_TIME = DELTA_TIME;
	this->Init();
}

void TimerUI::Init() {
	_gameTimer.resetTicksTimer();
	_timerLength = 30000.00f;

	SDL_Renderer* renderer = _window->getRenderer();
	IMG_Init(IMG_INIT_PNG);
	char* path = SDL_GetBasePath();

	char timerBasePath[200]; strcpy_s(timerBasePath, path); strcat_s(timerBasePath, "content\\timerBase.png");
	char timerL0Path[200]; strcpy_s(timerL0Path, path); strcat_s(timerL0Path, "content\\timerL0.png");
	char timerL1Path[200]; strcpy_s(timerL1Path, path); strcat_s(timerL1Path, "content\\timerL1.png");
	char timerL2Path[200]; strcpy_s(timerL2Path, path); strcat_s(timerL2Path, "content\\timerL2.png");
	char timerL3Path[200]; strcpy_s(timerL3Path, path); strcat_s(timerL3Path, "content\\timerL3.png");
	char timerL4Path[200]; strcpy_s(timerL4Path, path); strcat_s(timerL4Path, "content\\timerL4.png");
	char timerL5Path[200]; strcpy_s(timerL5Path, path); strcat_s(timerL5Path, "content\\timerL5.png");
	char timerL6Path[200]; strcpy_s(timerL6Path, path); strcat_s(timerL6Path, "content\\timerL6.png");

	char timerR0Path[200]; strcpy_s(timerR0Path, path); strcat_s(timerR0Path, "content\\timerR0.png");
	char timerR1Path[200]; strcpy_s(timerR1Path, path); strcat_s(timerR1Path, "content\\timerR1.png");
	char timerR2Path[200]; strcpy_s(timerR2Path, path); strcat_s(timerR2Path, "content\\timerR2.png");
	char timerR3Path[200]; strcpy_s(timerR3Path, path); strcat_s(timerR3Path, "content\\timerR3.png");
	char timerR4Path[200]; strcpy_s(timerR4Path, path); strcat_s(timerR4Path, "content\\timerR4.png");
	char timerR5Path[200]; strcpy_s(timerR5Path, path); strcat_s(timerR5Path, "content\\timerR5.png");
	char timerR6Path[200]; strcpy_s(timerR6Path, path); strcat_s(timerR6Path, "content\\timerR6.png");
	char timerR7Path[200]; strcpy_s(timerR7Path, path); strcat_s(timerR7Path, "content\\timerR7.png");
	char timerR8Path[200]; strcpy_s(timerR8Path, path); strcat_s(timerR8Path, "content\\timerR8.png");
	char timerR9Path[200]; strcpy_s(timerR9Path, path); strcat_s(timerR9Path, "content\\timerR9.png");

	_timerBase = IMG_LoadTexture(renderer, timerBasePath);
	SDL_Texture* timerL0 = IMG_LoadTexture(renderer, timerL0Path); _leftNumbers.push_back(timerL0);
	SDL_Texture* timerL1 = IMG_LoadTexture(renderer, timerL1Path); _leftNumbers.push_back(timerL1);
	SDL_Texture* timerL2 = IMG_LoadTexture(renderer, timerL2Path); _leftNumbers.push_back(timerL2);
	SDL_Texture* timerL3 = IMG_LoadTexture(renderer, timerL3Path); _leftNumbers.push_back(timerL3);
	SDL_Texture* timerL4 = IMG_LoadTexture(renderer, timerL4Path); _leftNumbers.push_back(timerL4);
	SDL_Texture* timerL5 = IMG_LoadTexture(renderer, timerL5Path); _leftNumbers.push_back(timerL5);
	SDL_Texture* timerL6 = IMG_LoadTexture(renderer, timerL6Path); _leftNumbers.push_back(timerL6);

	SDL_Texture* timerR0 = IMG_LoadTexture(renderer, timerR0Path); _rightNumbers.push_back(timerR0);
	SDL_Texture* timerR1 = IMG_LoadTexture(renderer, timerR1Path); _rightNumbers.push_back(timerR1);
	SDL_Texture* timerR2 = IMG_LoadTexture(renderer, timerR2Path); _rightNumbers.push_back(timerR2);
	SDL_Texture* timerR3 = IMG_LoadTexture(renderer, timerR3Path); _rightNumbers.push_back(timerR3);
	SDL_Texture* timerR4 = IMG_LoadTexture(renderer, timerR4Path); _rightNumbers.push_back(timerR4);
	SDL_Texture* timerR5 = IMG_LoadTexture(renderer, timerR5Path); _rightNumbers.push_back(timerR5);
	SDL_Texture* timerR6 = IMG_LoadTexture(renderer, timerR6Path); _rightNumbers.push_back(timerR6);
	SDL_Texture* timerR7 = IMG_LoadTexture(renderer, timerR7Path); _rightNumbers.push_back(timerR7);
	SDL_Texture* timerR8 = IMG_LoadTexture(renderer, timerR8Path); _rightNumbers.push_back(timerR8);
	SDL_Texture* timerR9 = IMG_LoadTexture(renderer, timerR9Path); _rightNumbers.push_back(timerR9);

	IMG_Quit();
}

void TimerUI::BonusTime() {
	_timerLength += 30000.00f;
}

int TimerUI::UpdateTimer() {
	if (_gameTimer.getTicks() > _timerLength) {
		//End game!
		return 1;
	}
	return 0;
}

void TimerUI::RenderTimer() {

}