#pragma once

#include <string>
#include <SDL.H>

class Mansion
{
private:
	//Mansion map matrix
	int mansionGrid[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0 } };
	int endLoc[2] = { 0, 0 };

	int pVision[4][3] = {
		{ 1, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 } };
	int pLoc[2] = { 4, 0 };
	std::string pDir = "up";

public:
	Mansion();

	int Init();

	int ChangeDirection();
	int Move();

	int Update();
	int Render();
};

