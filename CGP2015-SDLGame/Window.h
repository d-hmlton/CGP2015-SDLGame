#pragma once
#include "SDL.H" //sdl2

class Window {
private:
    int _width; int _height;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

public:
    //Constructor
    Window(const char* title, int x, int y, int width, int height, Uint32 flags) {
        //Saves width and height to private properties
        _width = width; _height = height;

        //Window initialiser
        _window = SDL_CreateWindow(title, x, y, _width, _height, flags);

        //Renderer initialiser
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    }

    //Method to set the state of SDL's colour
    void setColour(int red, int green, int blue, int alpha) {
        SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha);
    }

    //Method to clear the screen in memory
    void clearScreen() {
        SDL_RenderClear(_renderer);
    }

    //Method to present the memory onscreen
    void presentToScreen() {
        SDL_RenderPresent(_renderer);
    }

    //Method to draw a line onscreen
    void drawLine(int x1, int y1, int x2, int y2) {
        SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
    }

    void drawRectangle(int x, int y, int width, int height, bool fill = false) {
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
    void drawTriangle() {
        //Creates a SDL_Point array with 4 points
        SDL_Point *points = new SDL_Point[4];
        points[0].x = _width / 2 - 50;   points[0].y = _height / 2 + 43.3;
        points[1].x = _width / 2,        points[1].y = _height / 2 - 43.3;
        points[2].x = _width / 2 + 50;   points[2].y = _height / 2 + 43.3;
        points[3] = points[0]; //Final point is identical to first point
        //If you're curious about height - the formula for height of an equilateral triangle
        // is (side × sqrt(3) / 2). With a side of 100, that's 86.6! That's why 50 vs 43.3

        //Draws the triangle in memory
        SDL_RenderDrawLines(_renderer, points, 4);
    }

    int getWidth() { return _width; }
    int getHeight() { return _height; }
};