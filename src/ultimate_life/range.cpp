#include <ultimate_life/range.h>


template<typename T>
ul::range<T>::iterator::iterator(T current, const T step)
    : m_current(current),
    m_step(step) 
{ }

template<typename T>
T& ul::range<T>::iterator::operator*() 
{ return m_current; }

template<typename T>
T* ul::range<T>::iterator::operator->() 
{ return &m_current; }

template<typename T>
typename ul::range<T>::iterator& 
ul::range<T>::iterator::operator++() 
{ 
    m_current = (m_current + m_step); 
    return *this; 
}

template<typename T>
typename ul::range<T>::iterator 
ul::range<T>::iterator::operator++(int) 
{ 
    iterator tmp = *this; 
    ++(*this); 
    return tmp; 
}

template <typename T>
bool ul::range<T>::iterator::operator==(const ul::range<T>::iterator& other) const
{
    return m_current == other.m_current;
}

template <typename T>
bool ul::range<T>::iterator::operator!=(const ul::range<T>::iterator& other) const
{
    return m_current != other.m_current;
}

template<typename T>
ul::range<T>::range(const T end): m_start(0), m_end(end), m_step(1) {}

template<typename T>
ul::range<T>::range(const T start, const T end): m_start(start), m_end(end), m_step(1) {}

template<typename T>
ul::range<T>::range(const T start, const T end, const T step): m_start(start), m_end(end), m_step(step) {}

template<typename T>
typename ul::range<T>::iterator 
ul::range<T>::begin() { return iterator(m_start, m_step); }

template<typename T>
typename ul::range<T>::iterator 
ul::range<T>::end() { return iterator(m_end, m_step); }

// Concrete definitions for range
template struct ul::range<int>;
template struct ul::range<unsigned int>;
template struct ul::range<long>;
template struct ul::range<unsigned long>;
template struct ul::range<float>;
template struct ul::range<double>;