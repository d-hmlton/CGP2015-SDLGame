#pragma once
#include "SDL.H" //sdl2

class Window {
private:
    int _width; int _height;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

public:
    //Constructor
    Window(const char* title, int x, int y, int width, int height, Uint32 flags);

    //Method to set the state of SDL's colour
    void setColour(int red, int green, int blue, int alpha);

    //Method to clear the screen in memory
    void clearScreen();

    //Method to present the memory onscreen
    void presentToScreen();

    //Method to draw a line onscreen
    void drawLine(int x1, int y1, int x2, int y2);

    void drawRectangle(int x, int y, int width, int height, bool fill);

    //Method to draw a triangle in memory
    void drawTriangle();

    int getWidth() { return _width; }
    int getHeight() { return _height; }
};