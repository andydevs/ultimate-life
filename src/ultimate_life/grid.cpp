#include <ultimate_life/grid.h>
#include <utils/range2d.h>
#include <utils/range.h>

#define INDEX(width, height, f, i, j) (f * width * height) + (i * height) + j

ul::Grid::Grid(int width, int height) : m_width(width),
                                        m_height(height),
                                        m_frame(0),
                                        m_buffer(2 * width * height, false) {}

ul::Grid::~Grid() {}

int ul::Grid::width()
{
    return m_width;
}

int ul::Grid::height()
{
    return m_height;
}

bool ul::Grid::cell(int i, int j)
{
    return m_buffer[INDEX(m_width, m_height, m_frame, i, j)];
}

void ul::Grid::aliven(int i, int j)
{
    m_buffer[INDEX(m_width, m_height, m_frame, i, j)] = true;
}

int ul::Grid::neighbors(int i, int j)
{
    int c = 0;
    utils::range<int> rx(std::max(i - 1, 0), std::min(i + 2, width()));
    utils::range<int> ry(std::max(j - 1, 0), std::min(j + 2, height()));
    for (auto [u, v] : utils::range2d<int>(rx, ry))
    {
        if ((u != i || v != j) && m_buffer[INDEX(m_width, m_height, m_frame, u, v)])
        {
            c++;
        }
    }
    return c;
}

void ul::Grid::update()
{
    for (auto [i, j] : grid_indeces())
    {
        int c = neighbors(i, j);
        m_buffer[INDEX(m_width, m_height, !m_frame, i, j)] = (c == 3) || (c == 2 && cell(i, j));
    }

    // Swap buffers
    m_frame = !m_frame;
}

ul::utils::range2d<int> ul::Grid::grid_indeces()
{
    utils::range<int> rx(width());
    utils::range<int> ry(height());
    return utils::range2d<int>(rx, ry);
}

ul::GridInitialize::GridInitialize(Grid &grid_ref) : m_grid_ref(grid_ref) {};

void ul::GridInitialize::receive(ul::script::cell cell)
{
    m_grid_ref.aliven(cell.first, cell.second);
}