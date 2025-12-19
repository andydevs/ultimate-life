#pragma once
#include <sstream>
#include <stdexcept>
#include <string>

namespace raiisdl
{
    class sdl_runtime_error : public std::exception
    {
    public:
        sdl_runtime_error(std::stringstream &msg_stream, const char *sdl_err_msg)
        {
            m_raiisdl_err_msg = msg_stream.str() + " SDL_ERROR: " + sdl_err_msg;
        }

        const char *what() const noexcept override
        {
            return m_raiisdl_err_msg.c_str();
        }

    private:
        std::string m_raiisdl_err_msg;
    };

} // namespace raiisdl

#define GUARD_SDL_ERROR(sdl_call, msg)                       \
    if (sdl_call < 0)                                        \
    {                                                        \
        std::stringstream s;                                 \
        s << msg;                                            \
        throw raiisdl::sdl_runtime_error(s, SDL_GetError()); \
    }

#define ASSERT_SDL_RESOURCE(sdl_resource, msg)               \
    if (sdl_resource == NULL)                                \
    {                                                        \
        std::stringstream s;                                 \
        s << msg;                                            \
        throw raiisdl::sdl_runtime_error(s, SDL_GetError()); \
    }