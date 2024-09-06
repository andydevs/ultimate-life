#pragma once
#include <iterator>

namespace ul 
{
    template <typename T>
    struct range 
    {
    public:
        class iterator
        {
        public:
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::input_iterator_tag;

            iterator(T current, const T step);
            T& operator*();
            T* operator->();
            iterator& operator++();
            iterator operator++(int);
            bool operator== (const iterator& other) const;
            bool operator!= (const iterator& other) const; 
        private:
            const T m_step;
            T m_current;
        };

        range(const T end);
        range(const T start, const T end);
        range(const T start, const T end, const T step);

        iterator begin();
        iterator end();

    private:
        T m_start;
        T m_end;
        T m_step;
    };
}