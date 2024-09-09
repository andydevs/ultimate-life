#include <ultimate_life/sdl.h>
#include <ultimate_life/window.h>
#include <ultimate_life/renderer.h>
#include <ultimate_life/life_loop.h>
#include <ultimate_life/lifeconfig.h>
#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{
    if (argc == 1) {
        std::cout << "Please provide a file!" << std::endl;
        return -1;
    }
    std::string filename = argv[1];

    ul::lc::LifeConfig config = ul::lc::readScript(filename);

    // Grid options
    int width = config.grid_property("width", 640);
    int height = config.grid_property("height", 480);

    ul::SDL sdl;
    ul::Window window(sdl, "Ultimate Life", width, height);
    ul::Renderer renderer(window);
    ul::life_loop(window, renderer, config);
}
