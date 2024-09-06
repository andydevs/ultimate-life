#pragma once
#include <ultimate_life/window.h>
#include <ultimate_life/renderer.h>
#include <vector>

namespace ul
{
    /**
     * Run life loop with initial config on window and renderer
     */
    void life_loop(
        Window& window, 
        Renderer& renderer, 
        std::vector<std::pair<int, int>>& initial_cells,
        int cell_size);
}
