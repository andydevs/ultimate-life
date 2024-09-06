#include <ultimate_life/sdl.h>
#include <ultimate_life/window.h>
#include <ultimate_life/renderer.h>
#include <ultimate_life/life_loop.h>
#include <iostream>


int main(int argc, char const *argv[])
{
    ul::SDL sdl;
    ul::Window window(sdl, "Ultimate Life", 640, 480);
    ul::Renderer renderer(window);
    ul::life_loop(window, renderer);
}
