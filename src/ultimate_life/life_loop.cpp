#include <ultimate_life/life_loop.h>
#include <ultimate_life/grid.h>
#include <iostream>

/**
 * Run life loop on window and renderer
 */
void ul::life_loop(ul::Window& window, ul::Renderer& renderer) 
{
    // Init grid
    ul::Grid grid(window, 2);

    // RPENTOMINOOOOOOO
    grid.aliven(71, 60);
    grid.aliven(72, 60);
    grid.aliven(71, 61);
    grid.aliven(70, 61);
    grid.aliven(71, 62);

    SDL_Event e;
    while (true) 
    {
        // Render current step
        int s = grid.cell_size();
        renderer.clear();
        for (size_t i = 0; i < grid.width(); i++)
        {
            for (size_t j = 0; j < grid.height(); j++)
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