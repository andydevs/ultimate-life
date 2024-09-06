#include <ultimate_life/window.h>
#include <iostream>

/**
 * Initialize with window title, window width, and window height
 * 
 * NOTE: We're requesting a reference to an SDL instance 
 *       in order to ensure that SDL has been initialized
 */
UL::Window::Window(const SDL& _sdl, const char* title, int w, int h): m_width(w), m_height(h) {
    m_window_handle = SDL_CreateWindow(title, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        w, h, 0);
}

/**
 * Deinitialize
 */
UL::Window::~Window() {
    SDL_DestroyWindow(m_window_handle);
}


/**
 * Get window width
 */
int UL::Window::width() {
    return m_width;
}

/**
 * Get window height
 */
int UL::Window::height() {
    return m_height;
}

void UL::event_loop(UL::Window& window) {
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