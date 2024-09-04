#include <iostream>
#include <sstream>
#include <exception>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char const *argv[])
{
    // Init SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
                              "Ultimate Life", 
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                              SCREEN_WIDTH, SCREEN_HEIGHT, 
                              0);

    // Event loop
    SDL_Event e;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&e)) {
            switch (e.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            default:
                break;
            }
        }
    }
    
    // Destroy window and quit
    SDL_DestroyWindow(window);
    SDL_Quit();
}
