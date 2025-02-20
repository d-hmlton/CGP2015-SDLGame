// CGP2015-SDL2Game : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.H" //sdl2
#include "Window.h"
#include "RNG.h" //Used for Task 5

//Global values for the game loop
#include "SZ_Timer.h"
SZ_Timer aTimer;
const float DELTA_TIME = 33.33f; //How many milliseconds each frame is allowed
bool done = false;

//Globally creates objects so they can be used throughout
Window* window;
RNG rng; //Creates an RNG (random number generation) object

using namespace std;

void Input() {}

void Update()
{
    //Task 5 - Generate 1000 random lines
    window->setColour(0, 0, 0, 255); window->clearScreen(); //Black screen
    RNG rng; 
    int windowWidth = window->getWidth(); int windowHeight = window->getHeight(); //Fetches window props

    for (int i = 0; i < 1000; i++) {
        //Randomises colour and "thickness" (alpha) state
        window->setColour(rng.numberRNG(0, 255), rng.numberRNG(0, 255),  //red, green
            rng.numberRNG(0, 255), rng.numberRNG(0, 255));              //blue, alpha

        //Draws line at random coordinates
        window->drawLine(rng.numberRNG(0, windowWidth), rng.numberRNG(0, windowHeight),  //x1 and y1
            rng.numberRNG(0, windowWidth), rng.numberRNG(0, windowHeight));            //x2 and y2
    }
}

void Render()
{
    //Displays lines
    window->presentToScreen();
}

void CleanUp()
{
    delete &window;
    delete &rng;
    SDL_Quit();
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
            //SDL_Delay(DELTA_TIME - aTimer.getTicks());
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
