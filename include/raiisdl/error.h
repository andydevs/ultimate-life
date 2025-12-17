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

#define ASSERT_SDL_RESOURCE(sdl_resource, msg)        \
    if (sdl_resource == NULL)                         \
    {                                                 \
        std::stringstream s;                          \
        s << msg << " SDL_Error: " << SDL_GetError(); \
        throw std::runtime_error(s.str());            \
    }