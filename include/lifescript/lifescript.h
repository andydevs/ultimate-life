#pragma once
#include <lifescript/misc.h>
#include <vector>
#include <string>
#include <map>

namespace ul::script
{
    class CellFunctional
    {
    public:
        virtual ~CellFunctional() = default;
        virtual void receive(cell c) = 0;
    };

    struct LSElem {
        bool prefabbed;
        std::string prefab_name;
        cell elem_cell;
    };

    class LifeScript
    {
    public:
        void foreach_cell(CellFunctional& f);
        int grid_property(const std::string& name, int default_value);
        void set_grid_property(const std::string& name, int value);
        void add_prefab(const std::string& name, std::vector<LSElem>& elems);
        void add_elem(LSElem elem);
    private:
        std::map<std::string, int> m_grid_config;
        std::map<std::string, std::vector<LSElem>> m_prefabs;
        std::vector<LSElem> m_elems;
        void __foreach_prefab(LSElem& elem, CellFunctional& f);
    };
};