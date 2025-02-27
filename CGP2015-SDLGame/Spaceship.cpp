#include "Spaceship.h"

Spaceship::Spaceship(Window* window, int shipWidth, int shipHeight, int xOffset, int yOffset) {
	//Defining parameters
	_window = window;
	int screenWidth = _window->getWidth();
	int screenHeight = _window->getHeight();

	_shipWidth = shipWidth; _shipHeight = shipHeight;
	_xMovesMax = (screenWidth / shipWidth) - 1;
	_yMovesMax = (screenHeight / shipHeight) - 1;

	int xOverUnderFlow = (screenWidth / shipWidth) * xOffset;
	if ((xOverUnderFlow > screenWidth) || (xOverUnderFlow < 0)) {
		//The entered xOffset is invalid
		yOffset++; //Puts the spaceship a row lower

		if (xOverUnderFlow > screenWidth) { xOffset = _xMovesMax; } //If x offset greater than screen width
		else { xOffset = 0; } //If x offset below zero 
	}

	int yOverUnderFlow = (screenHeight / shipHeight) * yOffset;
	if ((yOverUnderFlow > screenHeight) || (yOverUnderFlow < 0)) {
		//The entered yOffset is invalid; setting yOffset to 0.
		//(This will also trigger if the xOverUnderFlow check boosted yOffset past the limit)
		yOffset = 0;
	}

	_xMoves = xOffset; _xPosition = _xMoves * _shipWidth;
	_yMoves = yOffset; _yPosition = _yMoves * _shipHeight;

	if (_yMoves % 2 == 0) {
		_bounce = false;
	}
	else {
		_bounce = true;
	}
}

void Spaceship::Movement() {
	//Bounce section - this is where _yMoves increases
	if (_xMoves > _xMovesMax) {
		_xMoves = 0;
		_yMoves++;
		_bounce = !_bounce;

		if (_yMoves > _yMovesMax) {
			_yMoves = 0;
			_bounce = false;
		}
	}

	//Position calculation section - this is where _xMoves increases
	if (_bounce == false) { _xPosition = _xMoves * _shipWidth; } //Spaceship moving rightwards
	else { _xPosition = (_shipWidth * _xMovesMax) - (_xMoves * _shipWidth); } //Spaceship moving leftwards
	_yPosition = _shipHeight * _yMoves;

	_xMoves++; //Increments x moves for next time
}

void Spaceship::Render() {
	_window->drawRectangle(_xPosition, _yPosition, _shipWidth, _shipHeight, true);
}