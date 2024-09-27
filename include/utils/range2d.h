#pragma once
#include <iterator>
#include <utils/range.h>

namespace ul::utils
{
    template <typename T>
    class range2d
    {
    public:
        class iterator
        {
        public:
            using value_type = std::pair<T, T>;
            using difference_type = std::ptrdiff_t;
            using pointer = value_type*;
            using reference = value_type&;
            using iterator_category = std::input_iterator_tag;
            using iterv = typename range<T>::iterator;

            iterator(iterv x_start, iterv x_end, iterv x_current, iterv y_start, iterv y_end, iterv y_current);
            reference operator*();
            pointer operator->();
            iterator& operator++();
            iterator operator++(int);
            bool operator== (const iterator& other) const;
            bool operator!= (const iterator& other) const; 
        private:
            iterv m_x_start;
            iterv m_x_end;
            iterv m_x_current;
            iterv m_y_start;
            iterv m_y_end;
            iterv m_y_current;
            value_type m_current;
            void __update_pair();
        };

        range2d(range<T> x, range<T> y);
        iterator begin();
        iterator end();
    private:
        range<T> m_x_range;
        range<T> m_y_range;
    };
}