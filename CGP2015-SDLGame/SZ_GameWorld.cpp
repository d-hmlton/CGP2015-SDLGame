#include "SZ_GameWorld.h"

bool _gKeys[MAX_KEYS];
SDL_Event _event;

//Constructor
SZ_GameWorld::SZ_GameWorld() {
    this->Init();
}

int SZ_GameWorld::Init() {
    //SDL Initialiser
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return 1;

    int screenWidth = 800;
    int screenHeight = 600;

    //Create a window
    _window = new Window(
        "Dylan [27599488]",         // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        screenWidth, screenHeight,  // width, height
        SDL_WINDOW_SHOWN);      // flags

    //CODE TO REMOVE
    /*
    int width = 40;
    int height = 40;
    int shipMax = 20;
    int maxSpace = screenWidth / 2; //The maximum space that ships are allowed to occupy

    for (int ships = 0; ships < shipMax; ships++) {
        int xOffset = ((maxSpace / 2) / width) + (ships * 2) % (maxSpace / width);
        int yOffset = ((ships * 2) / (maxSpace / width)) * 2;

        _shipList.push_back(new Spaceship(_window, width, height,
            xOffset, yOffset,
            0, 0, 255));
    }

    _shipListSize = _shipList.size(); */

    _window->setColour(0, 0, 0, 255); _window->clearScreen();
    _window->presentToScreen();
    _frames = 0;

    return 0;
}

void SZ_GameWorld::Loop() {
    while (_done == false)
    {
        //use home made timer provided by Olivier
        _aTimer.resetTicksTimer(); // resets a frame timer to zero

        this->Input();
        this->Update();
        this->Render();

        // if less time has passed than allocated block, wait difference
        if (_aTimer.getTicks() < _DELTA_TIME)
        {
            SDL_Delay(_DELTA_TIME - _aTimer.getTicks());
        }
    }
}

void SZ_GameWorld::Input() {
    while (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_QUIT) {
            _done = true;
        }

        if (_event.type == SDL_KEYDOWN && _event.key.repeat == NULL) {
            switch (_event.key.keysym.sym) {
            case SDLK_ESCAPE:
                _done = true;
                break;
            case SDLK_w:
                printf("W has been pressed \n");
                _gKeys[SDLK_w] = true;
                break;
            case SDLK_LEFT:
                printf("Left Arrow has been pressed \n");
                _gKeys[SDLK_LEFT] = true;
                break;
            case SDLK_RIGHT:
                printf("Right Arrow has been pressed \n");
                _gKeys[SDLK_RIGHT] = true;
                break;
            }
        }

        if (_event.type == SDL_KEYUP && _event.key.repeat == NULL) {
            switch (_event.key.keysym.sym) {
            case SDLK_w:
                printf("W has been released \n");
                _gKeys[SDLK_w] = false;
                break;
            case SDLK_LEFT:
                printf("Left Arrow has been released \n");
                _gKeys[SDLK_LEFT] = false;
                break;
            case SDLK_RIGHT:
                printf("Right Arrow has been released \n");
                _gKeys[SDLK_RIGHT] = false;
                break;
            }
        }
    }

    if (_gKeys[SDLK_w]) {
        _pause = true;
    }
    else {
        _pause = false;
    }
}

void SZ_GameWorld::Update() {
    if (_pause == true) {
        return;
    }

    //REMOVE
    /*
    bool isBounceTime = false;
    for (int ship = 0; ship < _shipListSize; ship++) {
        //Bounce phase
        isBounceTime = _shipList[ship]->BounceCheck(); //Checks if next movement would take the ship beyond screen limits
        //This MUST be done before movement, or it will cause ships to desync!

        if (isBounceTime == true) {
            //Runs a new for loop to start from zero in the list and work way up
            for (int flipShip = 0; flipShip < _shipListSize; flipShip++) {
                _shipList[flipShip]->Bounce();
            }

            ship = _shipListSize + 1; //Ensures the 'for' loop ends; prevents a bounce loop
        }
    }

    for (int ship = 0; ship < _shipListSize; ship++) {
        _shipList[ship]->Movement();
    }
    */ 
}

void SZ_GameWorld::Render() {
    //Drawing a square for every frame 
    _window->setColour(0, 0, 0, 255); _window->clearScreen();

    //REMOVE
    /*
    for (int ship = 0; ship < _shipListSize; ship++) {
        _shipList[ship]->Render();
    }
    */

    //Display window
    _window->presentToScreen();
    _frames++; //Increments the frame counter
    printf("Frames: %d / Time: %.2f \n", _frames, (_frames * _DELTA_TIME) / 1000);
}

void SZ_GameWorld::End() {
    SDL_Quit();
    delete _window;

    //REMOVE
    /*
    for (int ship = 0; ship < _shipListSize; ship++) {
        delete _shipList[ship];
    }
    */
}