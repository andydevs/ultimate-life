#include <ultimate_life/macros.h>
#include <ultimate_life/sdl.h>


ul::SDL::SDL() {
    GUARD_SDL_ERROR(
        SDL_Init(SDL_INIT_VIDEO), 
        "SDL could not initialize!");
}

ul::SDL::~SDL() {
    SDL_Quit();
}