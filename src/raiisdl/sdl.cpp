#include <raiisdl/sdl.h>
#include <raiisdl/error.h>

raiisdl::SDL::SDL()
{
    SDL_SetMainReady();
    GUARD_SDL_ERROR(
        SDL_Init(SDL_INIT_VIDEO),
        "SDL could not initialize!");
}

raiisdl::SDL::~SDL()
{
    SDL_Quit();
}