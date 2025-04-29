#pragma once
#include <ultimate_life/grid.h>
#include <ultimate_life/renderer.h>
#include <lifescript/lifescript.h>
#include <vector>

namespace ul
{
    /**
     * Run life loop with initial config on window and renderer
     */
    void life_loop(Grid& grid, int cell_size, Renderer& renderer);
}
