#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <sstream>

namespace raiisdl
{
    /**
     * RAII managed SDL instance
     */
    class SDL
    {
    public:
        /**
         * Initialize
         */
        SDL();

        /**
         * Deinitialize
         */
        ~SDL();
    };
};