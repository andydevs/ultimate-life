#include <ultimate_life/macros.h>
#include <ultimate_life/sdl.h>


UL::SDL::SDL() {
    GUARD_SDL_ERROR(
        SDL_Init(SDL_INIT_VIDEO), 
        "SDL could not initialize!");
}

UL::SDL::~SDL() {
    SDL_Quit();
}