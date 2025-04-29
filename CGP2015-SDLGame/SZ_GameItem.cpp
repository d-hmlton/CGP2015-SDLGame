#include "SZ_GameItem.h"

//Constructor
SZ_GameItem::SZ_GameItem() {
	//add constructor later
}

//Destructor
SZ_GameItem::~SZ_GameItem() {
	//add destructor later
}

void SZ_GameItem::Init(int x, int y, int w, int h) {
	_rect.x = x;	_rect.y = y;
	_rect.w = w;	_rect.h = h;

	this->x = x;		this->y = y;
	this->width = w;	this->height = h;
	MOVE_LEFT = false;	MOVE_RIGHT = false;

	R = 255; G = 128; B = 80;

	_velocity.x = 0;	_velocity.y = 0;
}

void SZ_GameItem::Input(int whichKey, bool isPressed) {
	//add input later
}

void SZ_GameItem::Update() {
	_rect.x = x;
	_rect.y - y;
	_rect.h = height;
	_rect.w = width;

	x = x + _velocity.x;
	y = y + _velocity.y;
}

void SZ_GameItem::Render(Window* window) {
	//add render later
}

void SZ_GameItem::SetColour(int eR, int eG, int eB) {
	//add setcolour later
}