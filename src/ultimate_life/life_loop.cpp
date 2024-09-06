#include <ultimate_life/life_loop.h>
#include <ultimate_life/grid.h>
#include <ultimate_life/range.h>
#include <iostream>

/**
 * Run life loop on window and renderer
 */
void ul::life_loop(ul::Window& window, ul::Renderer& renderer, std::vector<std::pair<int, int>>& initial_cells, int cell_size) 
{
    // Init grid
    ul::Grid grid(window, cell_size);
    for (std::pair<int, int> cell : initial_cells)
    {
        grid.aliven(cell.first, cell.second);
    }

    SDL_Event e;
    while (true) 
    {
        // Render current step
        int s = grid.cell_size();
        renderer.clear();
        for (size_t i : ul::range<size_t>(grid.width()))
        {
            for (size_t j : ul::range<size_t>(grid.height()))
            {
                if (grid.cell(i, j))
                {
                    renderer.cell(i*s, j*s, s);
                }
            }
        }
        renderer.update();
        
        // Get next step 
        grid.update();

        // Watch for quit command for now
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT) 
            {
                std::cout << "Quitting..." << std::endl;
                return;
            }
        }
    }
}