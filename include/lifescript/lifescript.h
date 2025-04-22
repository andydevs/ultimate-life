#pragma once
#include <lifescript/misc.h>
#include <ultimate_life/grid.h>
#include <vector>
#include <string>
#include <map>

namespace ul
{
    namespace ls
    {
        struct LSElem {
            bool prefabbed;
            std::string prefab_name;
            cell elem_cell;
        };

        class LifeScript
        {
        public:
            void instantiate(Grid& grid);
            int grid_property(const std::string& name, int default_value);
            void set_grid_property(const std::string& name, int value);
            void add_prefab(const std::string& name, std::vector<LSElem>& elems);
            void add_elem(LSElem elem);
        private:
            std::map<std::string, int> m_grid_config;
            std::map<std::string, std::vector<LSElem>> m_prefabs;
            std::vector<LSElem> m_elems;
            void __instantiatePrefab(ul::Grid& grid, LSElem& elem);
        };

        LifeScript readScript(std::string& filename);
    };
};