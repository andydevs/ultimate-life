#include <lifescript/celliterator.h>

using namespace ul::ls;

cell_iterator::cell_iterator(LifeScript &ls): m_ls(ls), m_cell(0, 0) {};

cell_iterator::cell_iterator(const cell_iterator& other): m_ls(other.m_ls), m_cell(other.m_cell) {};

cell& cell_iterator::operator*() { return m_cell; };

cell* cell_iterator::operator->() { return &m_cell; };

cell_iterator& cell_iterator::operator++() { return (*this); };

cell_iterator cell_iterator::operator++(int) { return (*this); };

cell_iterator& cell_iterator::operator=(const cell_iterator& other) {
    m_ls = other.m_ls;
    m_cell = other.m_cell;
    return (*this);
};

bool cell_iterator::operator==(const cell_iterator& other) const { return false; };

bool cell_iterator::operator!=(const cell_iterator& other) const { return false; };