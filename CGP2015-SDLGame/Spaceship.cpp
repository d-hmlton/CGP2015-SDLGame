#include "Spaceship.h"

Spaceship::Spaceship(int screenWidth, int screenHeight, int shipWidth, int shipHeight, int xOffset, int yOffset) {
	//Defining parameters
	_shipWidth = shipWidth; _shipHeight = shipHeight;
	_xMovesMax = screenWidth / shipWidth;
	_yMovesMax = screenHeight / shipHeight;

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

	_xMoves = xOffset;
	_yMoves = yOffset;

	if (_yMoves % 2 == 0) {
		_bounce == false;
	}
	else if (_yMoves % 2 == 1) {
		_bounce == true;
	}
}

auto Spaceship::Movement() {
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
	int xPosition;
	if (_bounce == false) { xPosition = _xMoves * _shipWidth; } //Spaceship moving rightwards
	else { xPosition = (_shipWidth * _xMovesMax) - (_xMoves * _shipWidth); } //Spaceship moving leftwards

	int yPosition = _shipHeight * _yMoves;

	_xMoves++;

	//Assembles a struct to return the ship values
	//Based on: [https://stackoverflow.com/questions/321068/returning-multiple-values-from-a-c-function]
	struct movedShip { int xPos; int yPos; int width; int height; };
	return movedShip { xPosition, yPosition, _shipWidth, _shipHeight };
}