#include <iostream>
#include <sstream>
#include <exception>
#include <SDL2/SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SDLInstance {
public:
    SDLInstance() {
        if(SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::ostringstream s;
            s << "SDL could not initialize! SDL_Error: " << SDL_GetError();
            throw s.str();
        }
        m_window = SDL_CreateWindow("Ultimate Life", 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SCREEN_WIDTH, SCREEN_HEIGHT, 
                                    0);
        if (!m_window)
        {
            std::ostringstream s;
            s << "SDL could not create a window! SDL_Error: " << SDL_GetError();
            throw s.str();
        }
        m_surface = SDL_GetWindowSurface(m_window);
        if (!m_surface)
        {
            std::ostringstream s;
            s << "SDL could not get window surface! SDL_Error: " << SDL_GetError();
            throw s.str();
        }
        SDL_UpdateWindowSurface(m_window);
    }
    ~SDLInstance() throw() {
        if (m_window) {
            SDL_DestroyWindow(m_window);
        }
    }
private:
    SDL_Surface* m_surface;
    SDL_Window* m_window;
};

int main(int argc, char const *argv[])
{
    try {
        SDLInstance sdl;
        SDL_Delay(5000);
    }
    catch (char* s) {
        std::cout << s << std::endl;
    }
    return 0;
}
