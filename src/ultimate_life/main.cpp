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
    // Load script
    if (argc == 1)
    {
        std::cout << "Please provide a script file!" << std::endl;
        return -1;
    }
    std::string filename = argv[1];
    ul::script::LifeScript script = ul::script::readScript(filename);

    // Grid options
    int width = script.grid_property("width", 640);
    int height = script.grid_property("height", 480);
    int cellsize = script.grid_property("cellsize", 5);

    // Initialize grid
    ul::Grid grid(width / cellsize, height / cellsize);
    ul::GridInitialize init_grid(grid);
    script.foreach_cell(init_grid);

    // Initialize SDL
    raiisdl::SDL sdl;
    raiisdl::Window window(sdl, "Ultimate Life", width, height);
    raiisdl::Renderer renderer(window);

    // Begin lifeloop
    ul::life_loop(grid, cellsize, renderer);

    // Exit
    return 0;
}
