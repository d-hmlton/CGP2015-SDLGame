#include "Spaceship.h"

Spaceship::Spaceship(Window* window, int width, int height, int xOffset, int yOffset, int r, int g, int b) {
	//Defining parameters
	_width = width; _height = height;
	_window = window;
	_screenWidth = _window->getWidth();
	_screenHeight = _window->getHeight();
	_r = r; _g = g; _b = b;

	//xOffset Handler
	int xOverUnderFlow = (_screenWidth / _width) * xOffset;
	if ((xOverUnderFlow > _screenWidth) || (xOverUnderFlow < 0)) {
		//The entered xOffset is invalid
		yOffset++; //Puts the spaceship a row lower

		if (xOverUnderFlow > _screenWidth) { xOffset = (_screenWidth / _width); } //If xOffset greater than screen width
		else { xOffset = 0; } //If xOffset below zero 
	}

	//yOffset Handler
	int yOverUnderFlow = (_screenHeight / _height) * yOffset;
	if ((yOverUnderFlow > _screenHeight) || (yOverUnderFlow < 0)) {
		//The entered yOffset is invalid; setting yOffset to 0.
		//(This will also trigger if the xOverUnderFlow check boosted yOffset past the limit)
		yOffset = 0;
	}

	_x = xOffset * _width;
	_y = yOffset * _height;

	if (yOffset % 2 == 0) {
		_bounce = false;
	}
	else {
		_bounce = true;
	}
}

void Spaceship::Movement() {
	//Handles when the spaceship bounces off the wall of the screen. Flips _bounce, then lowers y position
	if ((_x + _width >= _screenWidth && _bounce == false) || (_x <= 0 && _bounce == true)) {
		_bounce = !_bounce;
		_y = _y + _height;

		if (_y >= _screenHeight) {
			_y = 0;
		}

		return;
	}

	//Position calculation section - this is where _xMoves increases
	if (_bounce == false) { _x = _x + _width; } //Spaceship moving rightwards
	else { _x = _x - _width; } //Spaceship moving leftwards
}

void Spaceship::Render() {
	_window->setColour(_r, _g, _b, 255);
	_window->drawRectangle(_x, _y, _width, _height, true);
}