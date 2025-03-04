#pragma once
#include "Window.h"

class Spaceship {
private:
	Window* _window; //Pointer to (the pointer for, haha) GameWorld's Window object. Passed on instantiation
	int _screenWidth, _screenHeight; //Though these can be grabbed from _window, it's inefficient to grab repeatedly

	int _x, _y; //The x and y position onscreen of the spaceship's top-left corner
	int _width, _height; //The spaceship's width and height in pixels
	int _r, _g, _b; //The colour of the ship

	bool _bounce; //Tells Movement() whether to move the ship left or right. If false, right. If true, false.

public:
	//Constructor
	Spaceship(Window* window, int width, int height, int xOffset, int yOffset, int r, int g, int b);

	void Movement();

	bool BounceCheck();

	void Bounce();

	void Render();
};