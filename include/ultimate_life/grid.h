#pragma once
#include <ultimate_life/window.h>
#include <utils/range2d.h>

namespace ul {
    class Grid {
    private:
        const int FRAMES;
        int m_cell_size;
        Window& m_window;
        char ***m_buffer;
        int m_frame;
    public:
        Grid(Window& window, int cell_size);
        ~Grid();
        int cell_size();
        int width();
        int height();
        int cell(int i, int j);
        void aliven(int i, int j);
        int neighbors(int i, int j);
        void update();
        utils::range2d<int> grid_indeces();
    };
};