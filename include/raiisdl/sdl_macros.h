#include <sstream>
#include <SDL2/SDL.h>

// Apparently SDL redefined the
// main function without my consent.
// I'm calling the police
#undef main

#define GUARD_SDL_ERROR(sdl_call, msg)                \
    if (sdl_call < 0)                                 \
    {                                                 \
        std::stringstream s;                          \
        s << msg << " SDL_Error: " << SDL_GetError(); \
        throw s.str();                                \
    }