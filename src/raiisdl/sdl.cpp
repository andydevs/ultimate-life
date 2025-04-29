#include <raiisdl/macros.h>
#include <raiisdl/sdl.h>


raiisdl::SDL::SDL() {
    GUARD_SDL_ERROR(
        SDL_Init(SDL_INIT_VIDEO), 
        "SDL could not initialize!");
}

raiisdl::SDL::~SDL() {
    SDL_Quit();
}