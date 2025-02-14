// CGP2015-SDL2Game : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.H" //sdl2
#include "Window.h"
#include "RNG.h" //Used for Task 5

using namespace std;

int main(int argc, char *argv[])
{
    //Initialiser
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    //Create a window
    Window window(
        "Dylan [27599488]",         // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        800, 600,                   // width, height
        SDL_WINDOW_RESIZABLE);      // flags

    //Task 5 - Generate 1000 random lines
    RNG rng; //Creates an RNG (random number generation) object
    int windowWidth = window.getWidth(); int windowHeight = window.getHeight(); //Fetches window props

    for (int i = 0; i < 1000; i++) {
        //Randomises colour and "thickness" (alpha) state
        window.setColour(rng.numberRNG(0, 255), rng.numberRNG(0, 255),  //red, green
            rng.numberRNG(0, 255), rng.numberRNG(0, 255));              //blue, alpha

        //Draws line at random coordinates
        window.drawLine(rng.numberRNG(0, windowWidth), rng.numberRNG(0, windowHeight),  //x1 and y1
            rng.numberRNG(0, windowWidth), rng.numberRNG(0, windowHeight) );            //x2 and y2
    }

    //Displays lines
    window.presentToScreen();

    //Waits 4.2 seconds
    SDL_Delay(4200);

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
