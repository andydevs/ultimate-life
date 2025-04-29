#include <raiisdl/macros.h>
#include <raiisdl/sdl.h>


ul::SDL::SDL() {
    GUARD_SDL_ERROR(
        SDL_Init(SDL_INIT_VIDEO), 
        "SDL could not initialize!");
}

ul::SDL::~SDL() {
    SDL_Quit();
}