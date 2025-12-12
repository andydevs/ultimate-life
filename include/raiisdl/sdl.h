#pragma once
#include <raiisdl/sdl_macros.h>
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