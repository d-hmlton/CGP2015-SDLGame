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
        "Mansion Quest - Dylan Hamilton [27599488] - Games Computing",         // title
        SDL_WINDOWPOS_CENTERED,     // x position
        SDL_WINDOWPOS_CENTERED,     // y position
        screenWidth, screenHeight,  // width, height
        SDL_WINDOW_SHOWN);      // flags

    _window->setColour(0, 0, 0, 255); _window->clearScreen();
    _window->presentToScreen();
    _frames = 0;

    //Create a mansion
    _mansion = new Mansion(_window);

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
            //Quitting is the highest order of precedence
            case SDLK_ESCAPE: 
                _done = true; break;

            //Movement is second-highest
            case SDLK_w:
                _gKeys[SDLK_w] = true; break;
            case SDLK_UP:
                _gKeys[SDLK_w] = true; break; //Arrows aren't in _gKeys - part of a special keyboard

            //Rotation is third-highest - though, left first, right second
            case SDLK_a:
                _gKeys[SDLK_a] = true; break;
            case SDLK_LEFT:
                _gKeys[SDLK_a] = true; break;
            //(Right second)
            case SDLK_d:
                _gKeys[SDLK_d] = true; break;
            case SDLK_RIGHT:
                _gKeys[SDLK_d] = true; break;
            }
        }

        if (_event.type == SDL_KEYUP && _event.key.repeat == NULL) {
            switch (_event.key.keysym.sym) {
            case SDLK_w:
                _gKeys[SDLK_w] = false; break;
            case SDLK_UP:
                _gKeys[SDLK_w] = false; break;

            case SDLK_a:
                _gKeys[SDLK_a] = false; break;
            case SDLK_LEFT:
                _gKeys[SDLK_a] = false; break;

            case SDLK_d:
                _gKeys[SDLK_d] = false; break;
            case SDLK_RIGHT:
                _gKeys[SDLK_d] = false; break;
            }
        }
    }

    if (_gKeys[SDLK_a]) {
        if (_inputTimer.getTicks() > 200.00f) {
            _inputTimer.resetTicksTimer();
            _mansion->TurnLeft();
        }
    }
    if (_gKeys[SDLK_d]) {
        if (_inputTimer.getTicks() > 200.00f) {
            _inputTimer.resetTicksTimer();
            _mansion->TurnRight();
        }
    }
    if (_gKeys[SDLK_w]) {
        if (_inputTimer.getTicks() > 100.00f) {
            _inputTimer.resetTicksTimer();
            _mansion->MoveForward();
        }
    }
}

void SZ_GameWorld::Update() {
    _mansion->UpdateVision();
}

void SZ_GameWorld::Render() {
    //Drawing a square for every frame 
    _window->setColour(0, 0, 0, 255); _window->clearScreen();

    _mansion->RenderVision();

    //Display window
    _window->presentToScreen();
    _frames++; //Increments the frame counter
    printf("Frames: %d / Time: %.2f \n", _frames, (_frames * _DELTA_TIME) / 1000);
}

void SZ_GameWorld::End() {
    SDL_Quit();
    delete _window;
}