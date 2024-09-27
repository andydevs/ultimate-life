#include <utils/range.h>


template<typename T>
ul::utils::range<T>::iterator::iterator(T current, const T step, const T end)
    : m_current(current),
    m_step(step),
    m_end(end)
{ }

template<typename T>
ul::utils::range<T>::iterator::iterator(const iterator& other)
    : m_current(other.m_current),
    m_step(other.m_step),
    m_end(other.m_end)
{ }


template<typename T>
T& ul::utils::range<T>::iterator::operator*() 
{ return m_current; }

template<typename T>
T* ul::utils::range<T>::iterator::operator->() 
{ return &m_current; }

template<typename T>
typename ul::utils::range<T>::iterator& 
ul::utils::range<T>::iterator::operator++() 
{ 
    m_current = (m_current + m_step); 
    if (m_current > m_end) { m_current = m_end; }
    return *this; 
}

template<typename T>
typename ul::utils::range<T>::iterator 
ul::utils::range<T>::iterator::operator++(int) 
{ 
    iterator tmp = *this; 
    ++(*this); 
    return tmp; 
}

template <typename T>
typename ul::utils::range<T>::iterator& 
ul::utils::range<T>::iterator::operator=(iterator& other)
{
    m_current = other.m_current;
    m_step = other.m_step;
    m_end = other.m_end;
    return *this;
}

template <typename T>
bool ul::utils::range<T>::iterator::operator==(const ul::utils::range<T>::iterator& other) const
{
    return m_current == other.m_current;
}

template <typename T>
bool ul::utils::range<T>::iterator::operator!=(const ul::utils::range<T>::iterator& other) const
{
    return m_current != other.m_current;
}

template<typename T>
ul::utils::range<T>::range(const T end): m_start(0), m_end(end), m_step(1) {}

template<typename T>
ul::utils::range<T>::range(const T start, const T end): m_start(start), m_end(end), m_step(1) {}

template<typename T>
ul::utils::range<T>::range(const T start, const T end, const T step): m_start(start), m_end(end), m_step(step) {}

template<typename T>
typename ul::utils::range<T>::iterator 
ul::utils::range<T>::begin() { return iterator(m_start, m_step, m_end); }

template<typename T>
typename ul::utils::range<T>::iterator 
ul::utils::range<T>::end() { return iterator(m_end, m_step, m_end); }

// Concrete definitions for range
template class ul::utils::range<int>;
template class ul::utils::range<unsigned int>;
template class ul::utils::range<long>;
template class ul::utils::range<unsigned long>;
template class ul::utils::range<float>;
template class ul::utils::range<double>;