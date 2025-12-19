#include <raiisdl/error.h>

raiisdl::sdl_runtime_error::sdl_runtime_error(std::string &raiisdl_err_msg, const char *sdl_err_msg)
{
    m_raiisdl_err_msg = raiisdl_err_msg + " SDL_ERROR: " + sdl_err_msg;
}

const char *raiisdl::sdl_runtime_error::what() const noexcept
{
    return m_raiisdl_err_msg.c_str();
}