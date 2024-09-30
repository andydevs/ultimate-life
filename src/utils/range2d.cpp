#include <utils/range2d.h>

using namespace ul::utils;

template <typename T>
void range2d<T>::iterator::__update_pair() {
    m_current = {*m_x_current, *m_y_current};
}

template <typename T>
range2d<T>::iterator::iterator(typename range<T>::iterator x_start,
                               typename range<T>::iterator x_end,
                               typename range<T>::iterator x_current,
                               typename range<T>::iterator y_start,
                               typename range<T>::iterator y_end,
                               typename range<T>::iterator y_current) 
    : m_x_start(x_start), m_x_end(x_end), m_x_current(x_current),
    m_y_start(y_start), m_y_end(y_end), m_y_current(y_current)
{
    __update_pair();
};

template <typename T>
typename range2d<T>::iterator::reference 
range2d<T>::iterator::operator*() 
{
    return m_current;
};

template <typename T>
typename range2d<T>::iterator::pointer 
range2d<T>::iterator::operator->() 
{
    return &m_current;
};

template <typename T>
typename range2d<T>::iterator& 
range2d<T>::iterator::operator++() 
{
    if (m_x_current != m_x_end)
    {
        ++m_x_current;
    }
    if (m_x_current == m_x_end && m_y_current != m_y_end)
    {
        m_x_current = m_x_start;
        ++m_y_current;
    }
    __update_pair();
    return *this;
};

template <typename T>
typename range2d<T>::iterator 
range2d<T>::iterator::operator++(int) 
{
    iterator tmp = *this; 
    ++(*this); 
    return tmp; 
};

template <typename T>
bool range2d<T>::iterator::operator== (const range2d<T>::iterator& other) const 
{
    return m_x_current == other.m_x_current
        && m_y_current == other.m_y_current;
};

template <typename T>
bool range2d<T>::iterator::operator!= (const range2d<T>::iterator& other) const 
{
    return m_x_current != other.m_x_current
        || m_y_current != other.m_y_current;
}; 

template <typename T>
range2d<T>::range2d(range<T> x, range<T> y)
: m_x_range(x), m_y_range(y)
{}

template <typename T>
typename range2d<T>::iterator 
range2d<T>::begin()
{
    return iterator(m_x_range.begin(), m_x_range.end(), m_x_range.begin(), m_y_range.begin(), m_y_range.end(), m_y_range.begin());
}

template <typename T>
typename range2d<T>::iterator 
range2d<T>::end()
{
    return iterator(m_x_range.begin(), m_x_range.end(), m_x_range.begin(), m_y_range.begin(), m_y_range.end(), m_y_range.end());
}

// Concrete definitions for range2d
template class ul::utils::range2d<int>;
template class ul::utils::range2d<unsigned int>;
template class ul::utils::range2d<long>;
template class ul::utils::range2d<unsigned long>;
template class ul::utils::range2d<float>;
template class ul::utils::range2d<double>;