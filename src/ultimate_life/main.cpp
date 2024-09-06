#include <ultimate_life/sdl.h>
#include <ultimate_life/window.h>
#include <ultimate_life/renderer.h>
#include <ultimate_life/life_loop.h>
#include <iostream>
#include <vector>


using cell = std::pair<int, int>;
using cell_set = std::vector<std::pair<int, int>>;


/**
 * RPENTOMINOOOOOOO
 */
void rpentomino(cell_set& cells, int x, int y) {
    cells.push_back( cell(x + 1, y) );
    cells.push_back( cell(x + 2, y) );
    cells.push_back( cell(x + 1, y + 1) );
    cells.push_back( cell(x, y + 1) );
    cells.push_back( cell(x + 1, y + 2) );
}


int main(int argc, char const *argv[])
{
    // Initial cells list
    cell_set initial_cells;

    // RPENTOMINOOOOOO
    rpentomino(initial_cells, 140, 100);

    // Another one why not
    rpentomino(initial_cells, 170, 150);

    ul::SDL sdl;
    ul::Window window(sdl, "Ultimate Life", 640, 480);
    ul::Renderer renderer(window);
    ul::life_loop(window, renderer, initial_cells, 2);
}
