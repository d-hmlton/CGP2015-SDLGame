#pragma once

class Spaceship {
private:
	int _shipWidth; int _shipHeight;
	int _xMoves; int _yMoves; //Parameters storing how many moves x or y have been made
	int _xMovesMax; int _yMovesMax; //Parameters storing the max x or y moves
	bool _bounce;

public:
	//Constructor
	Spaceship(int screenWidth, int screenHeight, int shipWidth, int shipHeight, int xOffset, int yOffset);

	int* Movement();
};