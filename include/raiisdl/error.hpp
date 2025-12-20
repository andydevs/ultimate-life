#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include <SDL2/SDL_error.h>

namespace raiisdl
{
    /**
     * Thrown upon SDL-related errors in the raiisdl code
     */
    class sdl_runtime_error : public std::exception
    {
    public:
        /**
         * Initialize with both custom raiisdl message and SDL error message
         */
        sdl_runtime_error(std::string &raiisdl_err_msg, const char *sdl_err_msg)
        {
            m_raiisdl_err_msg = raiisdl_err_msg + " SDL_ERROR: " + sdl_err_msg;
        }

        /**
         * String containing message
         */
        const char *what() const noexcept override
        {
            return m_raiisdl_err_msg.c_str();
        }

    private:
        // Holds message to display
        std::string m_raiisdl_err_msg;
    };

    /**
     * Assert that SDL call returning integer was successful
     * if failed, throw sdl_runtime_error with given error message
     */
    inline void assert_sdl_call(int sdl_call_result, std::string err_msg)
    {
        if (sdl_call_result < 0)
        {
            throw sdl_runtime_error(err_msg, SDL_GetError());
        }
    }

    /**
     * Assert that SDL resource created is valid. If failed,
     * throw sdl_runtime_error with given error message
     */
    template <typename T>
    inline void assert_sdl_resource(T *sdl_resource, std::string err_msg)
    {
        if (sdl_resource == nullptr)
        {
            throw sdl_runtime_error(err_msg, SDL_GetError());
        }
    }

}