#pragma once
#include <ultimate_life/grid.h>
#include <lifescriptBaseVisitor.h>
#include <vector>
#include <string>
#include <map>

namespace ul
{
    namespace ls
    {
        using cell = std::pair<int, int>;

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

        class PrefabdefVisitor : public lifescriptBaseVisitor
        {
        private:
            std::vector<LSElem> m_elems;
        public:
            std::vector<LSElem>& elems();
            std::any visitPrefelems(lifescriptParser::PrefelemsContext *context) override;
            std::any visitRelprefab(lifescriptParser::RelprefabContext *context) override;
            std::any visitRelcell(lifescriptParser::RelcellContext *context) override;
        };

        class LifeScriptVisitor : public lifescriptBaseVisitor
        {
        private:
            LifeScript& m_ls;
        public:
            LifeScriptVisitor(LifeScript& ls);
            std::any visitGridstmt(lifescriptParser::GridstmtContext *context) override;
            std::any visitPrefdef(lifescriptParser::PrefdefContext *context) override;
            std::any visitAbscell(lifescriptParser::AbscellContext *context) override;
            std::any visitAbsprefab(lifescriptParser::AbsprefabContext *context) override;
        };

        LifeScript readScript(std::string& filename);
    };
};