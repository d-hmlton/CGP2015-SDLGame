#include "Mansion.h"
#include <iostream>
#include <algorithm>

//Constructor
Mansion::Mansion(Window* window) {
	_window = window;
	this->Init();
}

int Mansion::Init() {

	SDL_Renderer* renderer = _window->getRenderer();

	//Painfully long surface/texture making section (at least I don't need to make SDL_Surface instances)
	IMG_Init(IMG_INIT_PNG); //SDL_image Initialiser

	//For some reason, IMG_LoadTexture is REALLY unreliable at grabbing from the base path without being handed it directly.
	//To "resolve" this, the program here grabs the base path and then adds the path to file to it.
	//This sucks, but since SDL is pretty buggy as far as files are concerned, it's what needed to be done.
	// 
	//NOTE: If sprites aren't loading on your machine, the path might be too long. SDL breaks with paths over a certain length.
	//I have no idea how you fix this. If you do, please get in touch.
	char* path = SDL_GetBasePath();
	char basePath[100]; strcpy_s(basePath, path); strcat_s(basePath, "content\\worldBase.png");
	char leftL3Path[100]; strcpy_s(leftL3Path, path); strcat_s(leftL3Path, "content\\worldLeftL3.png");
	char centreL3Path[100]; strcpy_s(centreL3Path, path); strcat_s(centreL3Path, "content\\worldCentreL3.png");
	char rightL3Path[100]; strcpy_s(rightL3Path, path); strcat_s(rightL3Path, "content\\worldRightL3.png");
	char leftL2Path[100]; strcpy_s(leftL2Path, path); strcat_s(leftL2Path, "content\\worldLeftL2.png");
	char centreL2Path[100]; strcpy_s(centreL2Path, path); strcat_s(centreL2Path, "content\\worldCentreL2.png");
	char rightL2Path[100]; strcpy_s(rightL2Path, path); strcat_s(rightL2Path, "content\\worldRightL2.png");
	char leftL1Path[100]; strcpy_s(leftL1Path, path); strcat_s(leftL1Path, "content\\worldLeftL1.png");
	char centreL1Path[100]; strcpy_s(centreL1Path, path); strcat_s(centreL1Path, "content\\worldCentreL1.png");
	char rightL1Path[100]; strcpy_s(rightL1Path, path); strcat_s(rightL1Path, "content\\worldRightL1.png");
	char leftL0Path[100]; strcpy_s(leftL0Path, path); strcat_s(leftL0Path, "content\\worldLeftL0.png");
	char errorPath[100]; strcpy_s(errorPath, path); strcat_s(errorPath, "content\\worldError.png");
	char rightL0Path[100]; strcpy_s(rightL0Path, path); strcat_s(rightL0Path, "content\\worldRightL0.png");

	std::cout << basePath << std::endl;
	_worldBase = IMG_LoadTexture(renderer, basePath); _textureVector.push_back(_worldBase);				//index 0
	_worldLeftL3 = IMG_LoadTexture(renderer, leftL3Path); _textureVector.push_back(_worldLeftL3);		//index 1
	_worldCentreL3 = IMG_LoadTexture(renderer, centreL3Path); _textureVector.push_back(_worldCentreL3); //index 2
	_worldRightL3 = IMG_LoadTexture(renderer, rightL3Path); _textureVector.push_back(_worldRightL3);	//index 3
	_worldLeftL2 = IMG_LoadTexture(renderer, leftL2Path); _textureVector.push_back(_worldLeftL2);		//index 4
	_worldCentreL2 = IMG_LoadTexture(renderer, centreL2Path); _textureVector.push_back(_worldCentreL2); //index 5
	_worldRightL2 = IMG_LoadTexture(renderer, rightL2Path); _textureVector.push_back(_worldRightL2);	//index 6
	_worldLeftL1 = IMG_LoadTexture(renderer, leftL1Path); _textureVector.push_back(_worldLeftL1);		//index 7
	_worldCentreL1 = IMG_LoadTexture(renderer, centreL1Path); _textureVector.push_back(_worldCentreL1); //index 8
	_worldRightL1 = IMG_LoadTexture(renderer, rightL1Path); _textureVector.push_back(_worldRightL1);	//index 9
	_worldLeftL0 = IMG_LoadTexture(renderer, leftL0Path); _textureVector.push_back(_worldLeftL0);		//index 10
	_worldError = IMG_LoadTexture(renderer, errorPath); _textureVector.push_back(_worldError);			//index 11
	_worldRightL0 = IMG_LoadTexture(renderer, rightL0Path); _textureVector.push_back(_worldRightL0);	//index 12

	IMG_Quit();

	//Define default render settings
	_screenMult = 2; //Default expects 800x600 screen
	_srcWorld = { 0, 0, 400, 300 };
	_dstWorld = { 0, 0, 800, 600 };

	Print();
	return 0;
}

int Mansion::Print() {
	printf("Mansion Grid\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%i ", _mansionGrid[i][j]);
		}
		printf("\n");
	}

	printf("\nPlayer Vision\n");
	for (int i = 3; i > -1; i--) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", _pVision[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int Mansion::RotateClockwise() {
	//Based on code from 'GeeksforGeeks' - see references in report
	//Matrix rotation code
	Print();

	std::vector<std::vector<int>> result(5, std::vector<int>(5));
	for (int row = 0; row < 5; row++) {
		for (int col = row + 1; col < 5; col++) {
			result[col][5 - row - 1] = _mansionGrid[row][col];
		}
	}
	_mansionGrid = result;

	//Player rotation code
	std::vector<int> newLoc = {0, 0};
	newLoc[0] = _pLoc[1];
	newLoc[1] = 5 - _pLoc[0] - 1;
	_pLoc = newLoc;

	UpdateVision();

	Print();

	return 0;
}

int Mansion::UpdateVision() {
	for (int row = 0; row < 4; row++) { //Row loop
		for (int col = -1; col < 2; col++) { //Col loop
			//BORDER CHECKERS
			//If row is beyond the maze borders
			if ((_pLoc[0] - row < 0) || (_pLoc[0] - row > 4)) {
				_pVision[row][col + 1] = 1;
				continue;
			}
			//If col is beyond the maze borders
			if ((_pLoc[1] + col < 0) || (_pLoc[1] + col > 4)) {
				_pVision[row][col + 1] = 1;
				continue;
			}

			//Update vision
			_pVision[row][col + 1] = _mansionGrid[_pLoc[0] - row][_pLoc[1] + col];
		}
	}

	return 0;
}

int Mansion::RenderVision() {
	int presentHeight = _window->getHeight();
	int presentWidth = _window->getWidth();

	int presentMult = 1;
	if (presentHeight / 300 <= presentWidth / 400) { presentMult = presentHeight / 300; }
	else { presentMult = presentWidth / 400; }

	if (presentMult <= 0) {
		printf("NOTE: This game only renders properly on screens / in windows larger than 400x300.");
		presentMult = 1;
	}

	//The 0,0 points relative to game screen size
	int relativeZeroX = (presentWidth / 2) - (200 * presentMult); //x at centre, minus half of the ratio width, to reach leftmost point
	int relativeZeroY = (presentHeight / 2) - (150 * presentMult); //x at centre, minus half of the ratio height, to reach topmost point

	_dstWorld = { relativeZeroX, relativeZeroY, 400 * presentMult, 300 * presentMult };

	_window->renderSprite(_textureVector[0], _srcWorld, _dstWorld); //Render base sprite

	//Vision render - loops through the 12 wall sprites, indexed to allow this to work
	int sprite = 1; int row = 3;
	while (row > -1) {
		int col = 0;
		while (col < 3) {
			if (_pVision[row][col] == 1) {
				_window->renderSprite(_textureVector[sprite], _srcWorld, _dstWorld);
			}
			sprite++; col++; //Goes to next sprite, and to next col along
		}
		row--; //Reached end of cols for that row; advances row
	}

	Print();

	return 0;
}