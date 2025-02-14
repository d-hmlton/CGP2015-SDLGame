// Week3Tasks : This file contains code written to execute tasks from the Week 3 Workshop.
//  See Blackboard for more information on these tasks.

/*
//Task 1 - Making the screen blue
window.setColour(0, 0, 255, 255); //Sets SDL's colour as blue - RGB as first three, then alpha
window.clearScreen(); //Creates the idea of a blue screen in memory
window.presentToScreen(); //Presents that idea on the computer screen
*/


/*
//Task 2 - Draw white triangle
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


/*
//Task 4 - Draw blue 10x10 grid at center
//Defining variables
int squareWidth = 50; int squareHeight = 50; //Setting the grid square size
int centreX = window.getWidth() / 2;   //Defining these two here for efficiency; repeatedly
int centreY = window.getHeight() / 2; // asking for this value would waste a lot of resources

//Preparing SDL state for grid drawing
window.setColour(0, 0, 0, 255); window.clearScreen(); //Black screen
window.setColour(0, 0, 255, 255); //Set SDL colour to blue

//Grid drawing loop
for (int yOffset = 0; yOffset < 10; yOffset++) {
    for (int xOffset = 0; xOffset < 10; xOffset++) {
        window.drawSquare(
            centreX - (squareWidth * 5) + (squareWidth * xOffset),      // x position
            centreY - (squareHeight * 5) + (squareHeight * yOffset),    // y position
            squareWidth, squareHeight);                                 // width, height
    }
}

//Presenting grid
window.presentToScreen();
*/


/*
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
*/