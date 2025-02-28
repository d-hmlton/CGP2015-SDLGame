#pragma once
#include "Window.h"

class Spaceship {
private:
	Window* _window;
	int _screenWidth; int _screenHeight; //Though these can be grabbed from _window, it's inefficient to grab repeatedly

	int _xPosition; int _yPosition; //The x and y position onscreen of the spaceship's top-left corner
	int _shipWidth; int _shipHeight; //The spaceship's width and height in pixels
	bool _bounce; //Tells Movement() whether to move the ship left or right. If false, right. If true, false.

public:
	//Constructor
	Spaceship(Window* window, int shipWidth, int shipHeight, int xOffset, int yOffset);

	void Movement();

	void Render();
};