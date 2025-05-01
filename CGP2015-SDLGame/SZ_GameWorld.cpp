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
        "Mansion Quest - Dylan Hamilton [27599488] - Game Programming", // title
        SDL_WINDOWPOS_CENTERED,                                         // x position
        SDL_WINDOWPOS_CENTERED,                                         // y position
        screenWidth, screenHeight,                                      // width, height
        SDL_WINDOW_SHOWN);                                              // flags

    _window->setColour(0, 0, 0, 255); _window->clearScreen();
    _window->presentToScreen();
    _frames = 0;

    //Splash screen
    _splash = new Splash(_window);
    _splash->SplashLoop();

    //Create a mansion
    _mansion = new Mansion(_window);

    //Create a game timer to show up on screen
    _timerUI = new TimerUI(_window);

    _battle = new Battle(_window);

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

            case SDLK_s:
                _gKeys[SDLK_s] = true; break;
            case SDLK_DOWN:
                _gKeys[SDLK_s] = true; break;

            case SDLK_SPACE:
                _gKeys[SDLK_SPACE] = true; break;

            case SDLK_BACKSPACE:
                _gKeys[SDLK_BACKSPACE] = true; break;
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

            case SDLK_s:
                _gKeys[SDLK_s] = false; break;
            case SDLK_DOWN:
                _gKeys[SDLK_s] = false; break;

            case SDLK_d:
                _gKeys[SDLK_d] = false; break;
            case SDLK_RIGHT:
                _gKeys[SDLK_d] = false; break;

            case SDLK_SPACE:
                _gKeys[SDLK_SPACE] = false; break;
            case SDLK_BACKSPACE:
                _gKeys[SDLK_BACKSPACE] = false; break;
            }
        }
    }

    //Fullscreen
    if (_gKeys[SDLK_BACKSPACE]) {
        if (_inputTimer.getTicks() > 100.00f) {
            _inputTimer.resetTicksTimer();
            _window->fullscreenToggle();
        }
    }

    //Movement & Rotation controls
    if ((_battleState != 1) && (_battleState != 2)) {
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

    //Battle controls
    if (_battleState == 1) {
        if (_gKeys[SDLK_SPACE]) {
            if (_inputTimer.getTicks() > 200.00f) {
                _inputTimer.resetTicksTimer();
                _battle->TakeDamage(1);
            }
        }
        if (_gKeys[SDLK_w]) {
            if (_inputTimer.getTicks() > 100.00f) {
                _inputTimer.resetTicksTimer();
                _battle->TakeDamage(1);
            }
        }
        if (_gKeys[SDLK_a]) {
            if (_inputTimer.getTicks() > 100.00f) {
                _inputTimer.resetTicksTimer();
                _battle->TakeDamage(1);
            }
        }
        if (_gKeys[SDLK_s]) {
            if (_inputTimer.getTicks() > 100.00f) {
                _inputTimer.resetTicksTimer();
                _battle->TakeDamage(1);
            }
        }
        if (_gKeys[SDLK_d]) {
            if (_inputTimer.getTicks() > 100.00f) {
                _inputTimer.resetTicksTimer();
                _battle->TakeDamage(1);
            }
        }
    }
}

void SZ_GameWorld::Update() {
    //Battle!
    if ((_timerUI->GetTimer().getTicks() > 10000.00f) && (_battleState == 0)) {
        _battleState = 1;
        _battle->StartBattle();
    }
    int endBattle = 0;
    if (_battleState == 1) { endBattle = _battle->UpdateBattle(); }
    if (endBattle == 1) { _battleState = 2; _timerUI->BonusTime(); }

    endBattle = 0;
    if (_battleState == 2) { endBattle = _battle->EndBattle(); }
    if (endBattle == 1) { _battleState = 3; }

    _mansion->UpdateVision();
    int endGame = _timerUI->UpdateTimer();
    if (endGame == 1) { _done = true; }
}

void SZ_GameWorld::Render() {
    //Drawing a square for every frame 
    _window->setColour(0, 0, 0, 255); _window->clearScreen();

    //Checks current screen size and sets render params accordingly - necessary for everything after
    _window->screenCheck();

    _mansion->RenderVision();
    if ((_battleState == 1) || (_battleState == 2)) { _battle->RenderBattle(); }
    _timerUI->RenderTimer();

    //Display window
    _window->presentToScreen();
    _frames++; //Increments the frame counter
    printf("Frames: %d / Time: %.2f \n", _frames, (_frames * _DELTA_TIME) / 1000);
}

void SZ_GameWorld::End() {
    SDL_Quit();
    delete _window;
    delete _splash;
    delete _mansion;
    delete _timerUI;
    delete _battle;
}