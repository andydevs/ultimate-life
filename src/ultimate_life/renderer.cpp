#include <ultimate_life/macros.h>
#include <ultimate_life/renderer.h>

/**
 * Initialize with window
 */
UL::Renderer::Renderer(Window& window) : m_window_ref(window) {
    SDL_Window* win_h = m_window_ref.__UNSAFE_get_window_handle();
    m_renderer_handle = SDL_CreateRenderer(win_h, -1, 
        SDL_RENDERER_PRESENTVSYNC 
        | SDL_RENDERER_ACCELERATED);
}

/**
 * Deinitialize
 */
UL::Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer_handle);
}

/**
 * Waits for and initializes next frame
 */
void UL::Renderer::clear() {
    SDL_SetRenderDrawColor(m_renderer_handle, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer_handle);
}

/**
 * Waits for and initializes next frame
 */
void UL::Renderer::update() {
    SDL_RenderPresent(m_renderer_handle);
}

/**
 * Draws a cell
 */
void UL::Renderer::cell(int x, int y, int s) {
    GUARD_SDL_ERROR(
        SDL_SetRenderDrawColor(m_renderer_handle, 255, 255, 255, SDL_ALPHA_OPAQUE),
        "SDL Could not set color for cell at " << x << ", " << y << "!"
    );
    SDL_Rect rect = { .x=x, .y=y, .w=s, .h=s };
    GUARD_SDL_ERROR(
        SDL_RenderFillRect(m_renderer_handle, &rect),
        "SDL Could not draw cell at " << x << ", " << y << "!"
    );
}