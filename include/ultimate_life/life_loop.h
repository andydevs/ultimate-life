#pragma once
#include <ultimate_life/window.h>
#include <ultimate_life/renderer.h>


namespace UL
{
    /**
     * Run life loop on window and renderer
     */
    void life_loop(Window& window, Renderer& renderer);
}
