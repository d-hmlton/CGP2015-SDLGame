#pragma once

#include <iostream>
#include "SDL.h"
#include "SZ_Vector2D.h"
#include "Window.h"

class SZ_GameItem {
public:
	SZ_GameItem();
	~SZ_GameItem();

	void Init(int x, int y, int w, int h);

	void Input(int whichKey, bool isPressed);
	void Update();
	void Render(Window* window);
	void SetColour(int eR, int eG, int eB);

	int x, y, height, width, R, G, B;
	bool MOVE_LEFT, MOVE_RIGHT;

private:
	SDL_Rect _rect;
	SZ_Vector2D _velocity;
};