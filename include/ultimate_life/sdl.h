#pragma once
#include <SDL2/SDL.h>
#include <sstream>


namespace UL {
    /**
     * RAII managed SDL instance
     */
    class SDL {
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