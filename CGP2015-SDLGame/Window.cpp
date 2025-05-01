#include "Window.h"

Window::Window(const char* title, int x, int y, int width, int height, Uint32 flags) {
    //Saves width and height to private properties
    _width = width; _height = height;

    //Window initialiser
    _window = SDL_CreateWindow(title, x, y, _width, _height, flags);

    //Renderer initialiser
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    //Default val
    _srcWorld = { 0, 0, 400, 300 };
    _dstWorld = { 0, 0, 800, 600 };
}

//Method to set the state of SDL's colour
void Window::setColour(int red, int green, int blue, int alpha) {
    SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha);
}

void Window::screenCheck() {
    int presentMult = 1;
    if (_height / 300 <= _width / 400) { presentMult = _height / 300; }
    else { presentMult = _width / 400; }

    if (presentMult <= 0) {
        printf("NOTE: This game only renders properly on screens / in windows larger than 400x300.");
        presentMult = 1;
    }

    //The 0,0 points relative to game screen size
    int relativeZeroX = (_width / 2) - (200 * presentMult); //x at centre, minus half of the ratio width, to reach leftmost point
    int relativeZeroY = (_height / 2) - (150 * presentMult); //x at centre, minus half of the ratio height, to reach topmost point

    _dstWorld = { relativeZeroX, relativeZeroY, 400 * presentMult, 300 * presentMult };
}

void Window::renderSprite(SDL_Texture* texture) {
    SDL_RenderCopy(_renderer, texture, &_srcWorld, &_dstWorld);
}

void Window::fullscreenToggle() {
    if (_fullscreen == false) {
        SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        _fullscreen = true;
    }
    else {
        SDL_SetWindowFullscreen(_window, 0);
        _fullscreen = false;
    }

    _width = SDL_GetWindowSurface(_window)->w;
    _height = SDL_GetWindowSurface(_window)->h;
}

//Method to clear the screen in memory
void Window::clearScreen() {
    SDL_RenderClear(_renderer);
}

//Method to present the memory onscreen
void Window::presentToScreen() {
    SDL_RenderPresent(_renderer);
}

//Method to draw a line onscreen
void Window::drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}

void Window::drawRectangle(int x, int y, int width, int height, bool fill = false) {
    SDL_Rect rectangle;
    rectangle.x = x; rectangle.y = y; //Setting coordinates
    rectangle.w = width; rectangle.h = height; //Setting height
    if (fill == false) {
        SDL_RenderDrawRect(_renderer, &rectangle);
    }
    else {
        SDL_RenderFillRect(_renderer, &rectangle);
    }

}

//Method to draw a triangle in memory
void Window::drawTriangle() {
    //Creates a SDL_Point array with 4 points
    SDL_Point* points = new SDL_Point[4];
    points[0].x = _width / 2 - 50;   points[0].y = _height / 2 + 43;
    points[1].x = _width / 2, points[1].y = _height / 2 - 43;
    points[2].x = _width / 2 + 50;   points[2].y = _height / 2 + 43;
    points[3] = points[0]; //Final point is identical to first point
    //If you're curious about height - the formula for height of an equilateral triangle
    // is (side × sqrt(3) / 2). With a side of 100, that's 86.6! That's why 50 vs 43.3 (43)

    //Draws the triangle in memory
    SDL_RenderDrawLines(_renderer, points, 4);
}