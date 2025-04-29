#pragma once

#include <string>
#include <vector>
#include <SDL.H>

class Mansion
{
private:
	//Mansion map matrix
	std::vector<std::vector<int>> mansionGrid = {
		{ 2, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0 } };

	std::vector<std::vector<int>> pVision = {
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 } };
	std::vector<int> pLoc = { 4, 0 };
	std::string pDir = "up";

public:
	Mansion();

	int Init();

	int Print();

	int UpdateVision();
	int RenderVision();

	int Move();
	int ChangeDirection();

	int RotateClockwise();
	int RotateCounterClockwise(s);
};

