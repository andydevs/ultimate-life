#pragma once
#include <lifescript/lifescript.h>
#include <utils/range2d.h>

namespace ul
{

    const int GRID_FRAMES = 2;

    class Grid
    {
    private:
        int m_width;
        int m_height;
        bool ***m_buffer;
        int m_frame;

    public:
        Grid(int width, int height);
        ~Grid();
        int width();
        int height();
        bool cell(int i, int j);
        void aliven(int i, int j);
        int neighbors(int i, int j);
        void update();
        utils::range2d<int> grid_indeces();
    };

    class GridInitialize : public script::CellFunctional
    {
    public:
        GridInitialize(Grid &grid_ref);
        void receive(script::cell cell) override;

    private:
        Grid &m_grid_ref;
    };

};