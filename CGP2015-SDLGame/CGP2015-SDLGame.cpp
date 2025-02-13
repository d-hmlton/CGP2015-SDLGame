// CGP2015-SDL2Game : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SDL.H" //sdl2
#include "MyWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Initialiser
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    //Create a window
    MyWindow window(
        "Dylan [27599488]",         // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        800,                        // width
        600,                        // height
        SDL_WINDOW_RESIZABLE);      // flags

    /*
    //Task 1 - Making the screen blue
    window.setColour(0, 0, 255, 255); //Sets SDL's colour as blue - RGB as first three, then alpha
    window.clearScreen(); //Creates the idea of a blue screen in memory
    window.presentToScreen(); //Presents that idea on the computer screen
    */

    /*
    //Task 2 - Draw white rectangle
    window.setColour(0, 0, 0, 255); window.clearScreen(); //Black screen (no need to present yet!)
    window.setColour(255, 255, 255, 255); //Sets SDL's colour to white
    window.drawTriangle(); //Calls the draw triangle method
    window.presentToScreen(); //Presents the triangle (& black screen behind it) onscreen
    */

    /*
    //Task 3 - Draw purple line
    window.setColour(255, 255, 255, 255); window.clearScreen(); //White screen
    window.setColour(128, 0, 128, 255); //Sets SDL's colour to purple
    window.drawLine(0, 0, window.getWidth(), window.getHeight());
    window.presentToScreen();
    */

    //Task 4 - Draw blue 10x10 grid at center


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
