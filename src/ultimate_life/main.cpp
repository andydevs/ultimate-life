#include <iostream>
#include <sstream>
#include <exception>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace UL {
    class App {
    public:
        App() {
            if(SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                std::stringstream s;
                s << "SDL could not initialize! SDL_Error: " << SDL_GetError();
                throw s.str();
            }
        }
        ~App() {
            SDL_Quit();
        }
    };

    class Window {
    private:
        SDL_Window* m_window_handle;
    public:
        Window(const char* title, int w, int h) {
            m_window_handle = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
        }
        ~Window() {
            SDL_DestroyWindow(m_window_handle);
        }
    };
};


int main(int argc, char const *argv[])
{
    UL::App app;
    UL::Window window("Ultimate Life", SCREEN_WIDTH, SCREEN_HEIGHT);

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
}
