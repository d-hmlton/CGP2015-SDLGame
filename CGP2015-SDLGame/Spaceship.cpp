#include "Spaceship.h"

Spaceship::Spaceship(Window* window, int shipWidth, int shipHeight, int xOffset, int yOffset) {
	//Defining parameters
	_shipWidth = shipWidth; _shipHeight = shipHeight;
	_window = window;
	_screenWidth = _window->getWidth() - _shipWidth;
	_screenHeight = _window->getHeight();

	//xOffset Handler
	int xOverUnderFlow = (_screenWidth / _shipWidth) * xOffset;
	if ((xOverUnderFlow > _screenWidth) || (xOverUnderFlow < 0)) {
		//The entered xOffset is invalid
		yOffset++; //Puts the spaceship a row lower

		if (xOverUnderFlow > _screenWidth) { xOffset = (_screenWidth / _shipWidth - 1); } //If xOffset greater than screen width
		else { xOffset = 0; } //If xOffset below zero 
	}

	//yOffset Handler
	int yOverUnderFlow = (_screenHeight / _shipHeight) * yOffset;
	if ((yOverUnderFlow > _screenHeight) || (yOverUnderFlow < 0)) {
		//The entered yOffset is invalid; setting yOffset to 0.
		//(This will also trigger if the xOverUnderFlow check boosted yOffset past the limit)
		yOffset = 0;
	}

	_xPosition = xOffset * _shipWidth;
	_yPosition = yOffset * _shipHeight;

	if (yOffset % 2 == 0) {
		_bounce = false;
	}
	else {
		_bounce = true;
	}
}

void Spaceship::Movement() {
	//Handles when the spaceship bounces off the wall of the screen. Flips _bounce, then lowers y position
	if ((_xPosition + _shipWidth >= _screenWidth && _bounce == false) || (_xPosition <= 0 && _bounce == true)) {
		_bounce = !_bounce;
		_yPosition = _yPosition + _shipHeight;

		if (_yPosition >= _screenHeight) {
			_yPosition = 0;
		}

		return;
	}

	//Position calculation section - this is where _xMoves increases
	if (_bounce == false) { _xPosition = _xPosition + _shipWidth; } //Spaceship moving rightwards
	else { _xPosition = _xPosition - _shipWidth; } //Spaceship moving leftwards
}

void Spaceship::Render() {
	_window->drawRectangle(_xPosition, _yPosition, _shipWidth, _shipHeight, true);
}