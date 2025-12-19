#pragma once
#include <sstream>
#include <stdexcept>
#include <string>
#include <SDL2/SDL_error.h>

namespace raiisdl
{
    class sdl_runtime_error : public std::exception
    {
    public:
        sdl_runtime_error(std::string &raiisdl_err_msg, const char *sdl_err_msg);
        const char *what() const noexcept override;

    private:
        std::string m_raiisdl_err_msg;
    };

    inline void assert_sdl_call(int sdl_call_result, std::string err_msg)
    {
        if (sdl_call_result < 0)
        {
            throw sdl_runtime_error(err_msg, SDL_GetError());
        }
    }

    template <typename T>
    inline void assert_sdl_resource(T *sdl_resource, std::string err_msg)
    {
        if (sdl_resource == nullptr)
        {
            throw sdl_runtime_error(err_msg, SDL_GetError());
        }
    }

} // namespace raiisdl