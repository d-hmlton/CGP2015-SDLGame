// CGP2015-SDL2Game : This file contains the 'main' function. Program execution begins and ends there.
//


// ADD SRAND !



#include <iostream>
#include "SDL.H" //sdl2
#include "Window.h"
#include "RNG.h" //Used for Task 5

//Global values for the game loop
#include "SZ_Timer.h"
SZ_Timer aTimer;
const float DELTA_TIME = 16.67f; //How many milliseconds each frame is allowed
bool done = false;

#define MAX_KEYS (256)
bool gKeys[MAX_KEYS];

//Global values for the program
int frames = 0;
int width = 50; int height = 50;
int windowWidth; int windowHeight; //Defined in main

//Globally creates objects so they can be used throughout
Window* window;
RNG rng; //Creates an RNG (random number generation) object
SDL_Event _event;

using namespace std;

void Input()
{
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            done = true;
        }

        if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL) {
            switch (_event.key.keysym.sym) {
            case SDLK_ESCAPE:
                done = true;
                break;
            case SDLK_w:
                printf("W has been pressed \n");
                gKeys[SDLK_w] = true;
                break;
            }
        }
    }
}

void Update()
{
    //Drawing a square for every frame 
    window->setColour(0, 0, 0, 255); window->clearScreen();
    window->setColour(0, 0, 255, 255);
    window->drawRectangle(frames * width % windowWidth,             //x pos
        (frames / (windowWidth / width)) * height % windowHeight,   //y pos
        width, height, true);
    frames++; //Increments the frame counter
    printf("Frames: %d / Time: %.2f \n", frames, (frames * DELTA_TIME) / 1000);
}

void Render()
{
    //Display window
    window->presentToScreen();
}

void CleanUp()
{
    SDL_Quit();
    delete &window;
    delete &rng;
    delete &_event;
}

int main(int argc, char *argv[])
{
    //Initialiser
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    //Create a window
    window = new Window(
        "Dylan [27599488]",         // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        800, 600,                   // width, height
        SDL_WINDOW_RESIZABLE);      // flags

    windowWidth = window->getWidth(); 
    windowHeight = window->getHeight();

    while (done == false)
    {
        //use home made timer provided by Olivier
        aTimer.resetTicksTimer(); // resets a frame timer to zero

        Input();
        Update();
        Render();

        // if less time has passed than allocated block, wait difference
        if (aTimer.getTicks() < DELTA_TIME)
        {
            SDL_Delay(DELTA_TIME - aTimer.getTicks());
        }
    }

    CleanUp();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
