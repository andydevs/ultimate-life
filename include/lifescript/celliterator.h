#pragma once
#include <lifescript/lifescript.h>
#include <vector>

namespace ul
{
    namespace ls
    {
        class cell_iterator
        {
        public:
            using value_type = cell;
            using difference_type = std::ptrdiff_t;
            using pointer = cell*;
            using reference = cell&;
            using iterator_category = std::input_iterator_tag;

            cell_iterator(LifeScript& ls);
            cell_iterator(const cell_iterator& other);

            cell& operator*();
            cell* operator->();
            
            cell_iterator& operator++();
            cell_iterator operator++(int);

            cell_iterator& operator=(const cell_iterator& other);
            bool operator== (const cell_iterator& other) const;
            bool operator!= (const cell_iterator& other) const;

        private:
            LifeScript& m_ls;

            cell m_cell;
        };
    }
}