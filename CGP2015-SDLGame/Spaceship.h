#pragma once
#include "Window.h"

class Spaceship {
private:
	Window* _window;
	int _xPosition; int _yPosition;
	int _shipWidth; int _shipHeight;
	int _xMoves; int _yMoves; //Parameters storing how many moves x or y have been made
	int _xMovesMax; int _yMovesMax; //Parameters storing the max x or y moves
	bool _bounce;

public:
	//Constructor
	Spaceship(Window* window, int shipWidth, int shipHeight, int xOffset, int yOffset);

	void Movement();

	void Render();
};