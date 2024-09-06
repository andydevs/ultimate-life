#include <ultimate_life/sdl.h>


UL::SDL::SDL() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::stringstream s;
        s << "SDL could not initialize! SDL_Error: " << SDL_GetError();
        throw s.str();
    }
}

UL::SDL::~SDL() {
    SDL_Quit();
}