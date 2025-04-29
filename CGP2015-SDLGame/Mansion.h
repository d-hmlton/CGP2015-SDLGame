#pragma once

#include <string>
#include <vector>
#include <SDL.H>
#include <SDL_image.h>

#include "Window.h"

class Mansion
{
private:
	Window* _window;

	//Sprite vectors - make it easier to delete everything
	std::vector<SDL_Texture*> _textureVector;
	int _screenMult;
	SDL_Rect _srcWorld;
	SDL_Rect _dstWorld;

	//Mansion map matrix
	std::vector<std::vector<int>> _mansionGrid = {
		{ 2, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0 } };

	std::vector<std::vector<int>> _pVision = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 } };
	std::vector<int> _pLoc = { 4, 0 };

public:
	Mansion(Window* window);

	int Init();

	int Print();

	int UpdateVision();
	int RenderVision();

	//int Move();
	//int ChangeDirection();

	int RotateClockwise();
	//int RotateCounterClockwise();
};

