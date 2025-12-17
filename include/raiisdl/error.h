#pragma once
#include <sstream>
#include <stdexcept>

#define GUARD_SDL_ERROR(sdl_call, msg)                \
    if (sdl_call < 0)                                 \
    {                                                 \
        std::stringstream s;                          \
        s << msg << " SDL_Error: " << SDL_GetError(); \
        throw std::runtime_error(s.str());            \
    }