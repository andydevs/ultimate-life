#include <iostream>
#include <sstream>
#include <exception>
#include <SDL2/SDL.h>

namespace UL {
    class SDL {
    public:
        SDL() {
            if(SDL_Init(SDL_INIT_VIDEO) < 0)
            {
                std::stringstream s;
                s << "SDL could not initialize! SDL_Error: " << SDL_GetError();
                throw s.str();
            }
        }
        ~SDL() {
            SDL_Quit();
        }
    };

    class Window {
    private:
        int m_width;
        int m_height;
        SDL_Window* m_window_handle;
    public:
        /**
         * NOTE: We're requesting a reference to an SDL instance 
         *       in order to ensure that SDL has been initialized
         */
        Window(const SDL& _sdl, const char* title, int w, int h): m_width(w), m_height(h) {
            m_window_handle = SDL_CreateWindow(title, 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
                w, h, 0);
        }
        ~Window() {
            SDL_DestroyWindow(m_window_handle);
        }

        int width() {
            return m_width;
        }

        int height() {
            return m_height;
        }
    };
};


void event_loop(UL::Window& window) {
    SDL_Event e;
    while (true) {
        while (SDL_PollEvent(&e)) {
            switch (e.type)
            {

            // QUIT command
            case SDL_QUIT:
                std::cout << "Quitting..." << std::endl;
                return;


            default:
                break;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    UL::SDL sdl;
    UL::Window window(sdl, "Ultimate Life", 640, 480);
    event_loop(window);
}
