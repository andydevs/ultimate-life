#include <ultimate_life/life_loop.h>
#include <ultimate_life/grid.h>
#include <iostream>

/**
 * Run life loop on window and renderer
 */
void ul::life_loop(ul::Window& window, ul::Renderer& renderer, ul::lc::LifeConfig& cfg) 
{
    int cellsize = cfg.grid_property("cellsize", 5);

    // Init grid
    ul::Grid grid(window, cellsize);
    cfg.instantiate(grid);

    SDL_Event e;
    while (true) 
    {
        // Render current step
        renderer.clear();
        for (auto [i, j] : grid.grid_indeces())
            if (grid.cell(i, j))
                renderer.cell(i*cellsize, j*cellsize, cellsize);
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