#pragma once
#include "SDL.H" //sdl2
#include <string>

class Window {
private:
    int _width; int _height;
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    int _screenMult;
    SDL_Rect _srcWorld;
    SDL_Rect _dstWorld;

public:
    //Constructor
    Window(const char* title, int x, int y, int width, int height, Uint32 flags);

    //Method to set the state of SDL's colour
    void setColour(int red, int green, int blue, int alpha);

    //Checks if screen multipliers need updating
    void screenCheck();

    //Renders an SDL_Texture presented
    void renderSprite(SDL_Texture* texture);

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
    SDL_Renderer* getRenderer() { return _renderer; }
};