#include "Mansion.h"

//Constructor
Mansion::Mansion(Window* window) {
	this->Init(window);
}

int Mansion::Init(Window* window) {
	_window = window;
	UpdateVision();
	RenderVision();
	Print();
	return 0;
}

int Mansion::Print() {
	printf("Mansion Grid\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%i ", mansionGrid[i][j]);
		}
		printf("\n");
	}

	printf("\nPlayer Vision\n");
	for (int i = 3; i > -1; i--) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", pVision[i][j]);
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
			result[col][5 - row - 1] = mansionGrid[row][col];
		}
	}
	mansionGrid = result;

	//Player rotation code
	std::vector<int> newLoc = {0, 0};
	newLoc[0] = pLoc[1];
	newLoc[1] = 5 - pLoc[0] - 1;
	pLoc = newLoc;

	UpdateVision();

	Print();

	return 0;
}

int Mansion::UpdateVision() {
	for (int row = 0; row < 4; row++) { //Row loop
		for (int col = -1; col < 2; col++) { //Col loop
			//BORDER CHECKERS
			//If row is beyond the maze borders
			if ((pLoc[0] - row < 0) || (pLoc[0] - row > 4)) {
				pVision[row][col + 1] = 1;
				continue;
			}
			//If col is beyond the maze borders
			if ((pLoc[1] + col < 0) || (pLoc[1] + col > 4)) {
				pVision[row][col + 1] = 1;
				continue;
			}

			//Update vision
			pVision[row][col + 1] = mansionGrid[pLoc[0] - row][pLoc[1] + col];
		}
	}

	RenderVision();
	return 0;
}

int Mansion::RenderVision() {
	return 0;
}