#include "Mansion.h"

//Constructor
Mansion::Mansion() {
	this->Init();
}

int Mansion::Init() {
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
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", pVision[i][j]);
		}
		printf("\n");
	}
}

int Mansion::RotateClockwise() {
	//Based on code from 'GeeksforGeeks' - see references in report
	//Matrix rotation code
	Print();

	std::vector<std::vector<int>> result(5, std::vector<int>(5));
	for (int row = 0; row < 5; row++) {
		for (int col = row + 1; j < 5; j++) {
			result[col][5 - row - 1] = mansionGrid[row][col];
		}
	}
	mansionGrid = result;

	//Player rotation code
	std::vector<int> newLoc = {0, 0};
	newLoc[0] = pLoc[1];
	newLoc[1] = 5 - pLoc[0] - 1;
	pLoc = newLoc;

	Print();
}

int Mansion::UpdateVision() {
	for (int i = 3; i > -1; i--) { //Row loop
		for (int j = 0; j < 3; j++) { //Col loop
			if (pDir == "left") { pVision[i][j] =  }
		}
	}
}

int Mansion::RenderVision() {

}