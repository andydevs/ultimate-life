#pragma once
#include <SDL2/SDL.h>
#include <ultimate_life/sdl.h>

namespace UL {

    /**
     * RAII managed SDL window
     */
    class Window {
    private:
        int m_width;
        int m_height;
        SDL_Window* m_window_handle;
    public:
        /**
         * Initialize with window title, 
         *  window width, and window height
         * 
         * NOTE: We're requesting a reference 
         *       to an SDL instance in order 
         *       to ensure that SDL has been 
         *       initialized
         */
        Window(const SDL& _sdl, const char* title, int w, int h);

        /**
         * Deinitialize
         */
        ~Window();

        /**
         * Get window width
         */
        int width();

        /**
         * Get window height
         */
        int height();

        /**
         * Get window handle
         * 
         * WARN: UNSAFE, should only be used by 
         *       specific instances. Obtaining
         *       other properties should be done
         *       by object methods
         */
        SDL_Window* __UNSAFE_get_window_handle();
    };
}