#include <raiisdl/sdl.h>
#include <raiisdl/window.h>
#include <raiisdl/renderer.h>
#include <ultimate_life/grid.h>
#include <ultimate_life/life_loop.h>
#include <lifescript/readscript.h>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    // Load config
    if (argc == 1)
    {
        std::cout << "Please provide a file!" << std::endl;
        return -1;
    }
    std::string filename = argv[1];
    ul::script::LifeScript config = ul::script::readScript(filename);

    // Grid options
    int width = config.grid_property("width", 640);
    int height = config.grid_property("height", 480);
    int cellsize = config.grid_property("cellsize", 5);

    // Initialize grid
    ul::Grid grid(width / cellsize, height / cellsize);
    ul::GridInitialize init_grid(grid);
    config.foreach_cell(init_grid);

    // Initialize SDL
    raiisdl::SDL sdl;
    raiisdl::Window window(sdl, "Ultimate Life", width, height);
    raiisdl::Renderer renderer(window);

    // Begin lifeloop
    ul::life_loop(grid, cellsize, renderer);

    // Exit
    return 0;
}
