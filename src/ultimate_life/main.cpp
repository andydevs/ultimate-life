#include <ultimate_life/sdl.h>
#include <ultimate_life/window.h>
#include <iostream>


int main(int argc, char const *argv[])
{
    UL::SDL sdl;
    UL::Window window(sdl, "Ultimate Life", 640, 480);
    event_loop(window);
}
