#pragma once
#include <SDL2/SDL.h>
#include <raiisdl/window.h>

namespace ul {

    /**
     * RAII managed SDL Renderer
     */
    class Renderer {
    private:
        Window &m_window_ref;
        SDL_Renderer* m_renderer_handle;
    public:
        /**
         * Initialize with window
         */
        Renderer(Window& window);

        /**
         * Deinitialize
         */
        ~Renderer();

        /**
         * Clear renderer
         */
        void clear();

        /**
         * Waits for next frame
         */
        void update();

        /**
         * Draws a cell
         */
        void cell(int x, int y, int s);
    };

}