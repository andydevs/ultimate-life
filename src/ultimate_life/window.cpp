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

/**
 * Get window handle
 * 
 * WARN: UNSAFE, should only be used by 
 *       specific instances. Obtaining
 *       other properties should be done
 *       by object methods
 */
SDL_Window* UL::Window::__UNSAFE_get_window_handle() {
    return m_window_handle;
}