#include "Mansion.h"

//Constructor
Mansion::Mansion(Window* window) {
	_window = window;
	this->Init();
}

int Mansion::Init() {

	SDL_Renderer* renderer = _window->getRenderer();

	//Painfully long surface/texture making section (at least I don't need to make SDL_Surface instances lol)
	IMG_Init(SDL_INIT_EVERYTHING); //SDL_image Initialiser

	SDL_Texture* worldBase = IMG_LoadTexture(renderer, "content/worldBase.png");
	_textureVector.push_back(worldBase); //index 0

	SDL_Texture* worldLeftL3 = IMG_LoadTexture(renderer, "content/worldLeftL3.png");
	_textureVector.push_back(worldLeftL3); //index 1
	SDL_Texture* worldCentreL3 = IMG_LoadTexture(renderer, "content/worldCentreL3.png");
	_textureVector.push_back(worldCentreL3); //index 2
	SDL_Texture* worldRightL3 = IMG_LoadTexture(renderer, "content/worldRightL3.png");
	_textureVector.push_back(worldRightL3); //index 3

	SDL_Texture* worldLeftL2 = IMG_LoadTexture(renderer, "content/worldLeftL2.png");
	_textureVector.push_back(worldLeftL2); //index 4
	SDL_Texture* worldCentreL2 = IMG_LoadTexture(renderer, "content/worldCentreL2.png");
	_textureVector.push_back(worldCentreL2); //index 5
	SDL_Texture* worldRightL2 = IMG_LoadTexture(renderer, "content/worldRightL2.png");
	_textureVector.push_back(worldRightL2); //index 6

	SDL_Texture* worldLeftL1 = IMG_LoadTexture(renderer, "content/worldLeftL1.png");
	_textureVector.push_back(worldLeftL1); //index 7
	SDL_Texture* worldCentreL1 = IMG_LoadTexture(renderer, "content/worldCentreL1.png");
	_textureVector.push_back(worldCentreL1); //index 8
	SDL_Texture* worldRightL1 = IMG_LoadTexture(renderer, "content/worldRightL1.png");
	_textureVector.push_back(worldRightL1); //index 9

	SDL_Texture* worldLeftL0 = IMG_LoadTexture(renderer, "content/worldLeftL0.png");
	_textureVector.push_back(worldLeftL0); //index 10
	SDL_Texture* worldError = IMG_LoadTexture(renderer, "content/worldError.png");
	_textureVector.push_back(worldError); //index 11
	SDL_Texture* worldRightL0 = IMG_LoadTexture(renderer, "content/worldRightL0.png");
	_textureVector.push_back(worldRightL0); //index 12
	

	IMG_Quit();

	//Define default render settings
	_screenMult = 2; //Default expects 800x600 screen
	_srcWorld = { 0, 0, 400, 300 };
	_dstWorld = { 0, 0, 800, 600 };

	UpdateVision();
	RenderVision();
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
	if (presentHeight % 300 <= presentWidth % 400) { presentMult = presentHeight % 300; }
	else { presentMult = presentWidth % 400; }

	if (presentMult >= 0) {
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

	_window->presentToScreen();

	return 0;
}