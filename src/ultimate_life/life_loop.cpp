#include <ultimate_life/life_loop.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <algorithm>


static const int CELL_SIZE = 5;
static const int GRID_X = 128;
static const int GRID_Y = 96;

/**
 * Run life loop on window and renderer
 */
void UL::life_loop(UL::Window& window, UL::Renderer& renderer) {

    // Declare grid on the stack because lobotomy is me has that happened to.
    int cells[2][GRID_X][GRID_Y] = {};
    int f = 0;

    // RPENTOMINO BABY
    cells[f][71][60] = 1;
    cells[f][72][60] = 1;
    cells[f][71][61] = 1;
    cells[f][70][61] = 1;
    cells[f][71][62] = 1;

    SDL_Event e;
    while (true) {

        // Render current step
        renderer.clear();
        for (size_t i = 0; i < GRID_X; i++)
        {
            for (size_t j = 0; j < GRID_Y; j++)
            {
                if (cells[f][i][j]) {
                    renderer.cell(CELL_SIZE * i, CELL_SIZE * j, CELL_SIZE);
                }
            }
        }
        
        // Get next step 
        int c;
        for (int i = 0; i < GRID_X; ++i)
        {
            for (int j = 0; j < GRID_Y; ++j)
            {
                c = 0;
                for (int u = std::max(0, i - 1); u < std::min(GRID_X, i + 2); u++)
                {
                    for (int v = std::max(0, j - 1); v < std::min(GRID_Y, j + 2); v++)
                    {
                        if ((u != i || v != j) && cells[f][u][v]) 
                        {
                            c++;
                        }
                    }
                }
                cells[!f][i][j] = (c == 3) || (c == 2 && cells[f][i][j]);
            }
        }
        f = !f;

        // Render a frame
        renderer.update();

        // Watch for quit command for now
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                std::cout << "Quitting..." << std::endl;
                return;
            }
        }
    }
}