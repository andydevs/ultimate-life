#include <ultimate_life/grid.h>
#include <utils/range2d.h>
#include <utils/range.h>

ul::Grid::Grid(Window& window, int cell_size): 
    FRAMES(2),
    m_window(window), 
    m_cell_size(cell_size),
    m_frame(0)
{
    int grid_width = width();
    int grid_height = height();
    m_buffer = new char**[FRAMES];
    for (int f : utils::range<int>(FRAMES))
    {
        m_buffer[f] = new char*[grid_width];
        for (int i : utils::range<int>(grid_width))
        {
            m_buffer[f][i] = new char[grid_height];
        }
    }
}

ul::Grid::~Grid() {
    int grid_width = width();
    for (int f : utils::range<int>(FRAMES))
    {
        for (int i : utils::range<int>(grid_width))
        {
            delete m_buffer[f][i];   
        }
        delete m_buffer[f];
    }
    delete m_buffer;
}

int ul::Grid::cell_size() {
    return m_cell_size;
}

int ul::Grid::width() {
    return m_window.width() / m_cell_size;
}

int ul::Grid::height() {
    return m_window.height() / m_cell_size;
}

int ul::Grid::cell(int i, int j) {
    return m_buffer[m_frame][i][j];
}

void ul::Grid::aliven(int i, int j) {
    m_buffer[m_frame][i][j] = 1;
}

int ul::Grid::neighbors(int i, int j) {
    int c = 0;
    utils::range<int> rx(std::max(i - 1, 0), std::min(i + 2, width()));
    utils::range<int> ry(std::max(j - 1, 0), std::min(j + 2, height()));
    for (auto [u, v] : utils::range2d<int>(rx, ry)) 
    {
        if ((u != i || v != j) && m_buffer[m_frame][u][v])
        {
            c++;
        }
    }
    return c;
}

void ul::Grid::update() {
    for (auto [i, j] : grid_indeces())
    {
        int c = neighbors(i, j);
        m_buffer[!m_frame][i][j] = (c == 3) || (c == 2 && cell(i, j));
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