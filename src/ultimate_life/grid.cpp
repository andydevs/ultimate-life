#include <ultimate_life/grid.h>

UL::Grid::Grid(Window& window, int cell_size): 
    FRAMES(2),
    m_window(window), 
    m_cell_size(cell_size),
    m_frame(0)
{
    int grid_width = width();
    int grid_height = height();
    m_buffer = new char**[FRAMES];
    for (size_t f = 0; f < FRAMES; f++)
    {
        m_buffer[f] = new char*[grid_width];
        for (size_t i = 0; i < grid_width; i++)
        {
            m_buffer[f][i] = new char[grid_height];
        }
    }
}

UL::Grid::~Grid() {
    int grid_width = width();
    for (size_t f = 0; f < FRAMES; f++)
    {
        for (size_t i = 0; i < grid_width; i++)
        {
            delete m_buffer[f][i];
        }
        delete m_buffer[f];
    }
    delete m_buffer;
}

int UL::Grid::cell_size() {
    return m_cell_size;
}

int UL::Grid::width() {
    return m_window.width() / m_cell_size;
}

int UL::Grid::height() {
    return m_window.height() / m_cell_size;
}

int UL::Grid::cell(int i, int j) {
    return m_buffer[m_frame][i][j];
}

void UL::Grid::aliven(int i, int j) {
    m_buffer[m_frame][i][j] = 1;
}

int UL::Grid::neighbors(int i, int j) {
    int grid_width = width();
    int grid_height = height();
    int c = 0;
    for (int u = std::max(i - 1, 0); u < std::min(i + 2, grid_width); u++)
    {
        for (int v = std::max(j - 1, 0); v < std::min(j + 2, grid_height); v++)
        {
            if ((u != i || v != j) && m_buffer[m_frame][u][v])
            {
                c++;
            }
        }
    }
    return c;
}

void UL::Grid::update() {
    int grid_width = width();
    int grid_height = height();
    int c;
    // Update
    for (int i = 0; i < grid_width; i++)
    {
        for (int j = 0; j < grid_height; j++)
        {
            c = neighbors(i, j);
            m_buffer[!m_frame][i][j] = (c == 3) || (c == 2 && cell(i, j));
        }
    }
    // Swap buffers
    m_frame = !m_frame;
}