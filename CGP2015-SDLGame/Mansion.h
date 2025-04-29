#pragma once

#include <string>
#include <vector>
#include <SDL.H>

#include "Window.h"

class Mansion
{
private:
	Window* _window;

	//Mansion map matrix
	std::vector<std::vector<int>> mansionGrid = {
		{ 2, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0 } };

	std::vector<std::vector<int>> pVision = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 } };
	std::vector<int> pLoc = { 4, 0 };
	std::string pDir = "up";

public:
	Mansion(Window* window);

	int Init(Window* window);

	int Print();

	int UpdateVision();
	int RenderVision();

	int Move();
	int ChangeDirection();

	int RotateClockwise();
	int RotateCounterClockwise();
};

