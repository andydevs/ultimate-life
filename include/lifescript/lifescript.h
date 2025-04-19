#pragma once
#include <ultimate_life/grid.h>
#include <LifeScriptBaseVisitor.h>
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

        class PrefabdefVisitor : public LifeScriptBaseVisitor
        {
        private:
            std::vector<LSElem> m_elems;
        public:
            std::vector<LSElem>& elems();
            std::any visitPrefelems(LifeScriptParser::PrefelemsContext *context) override;
            std::any visitRelprefab(LifeScriptParser::RelprefabContext *context) override;
            std::any visitRelcell(LifeScriptParser::RelcellContext *context) override;
        };

        class LifeScriptConverterVisitor : public LifeScriptBaseVisitor
        {
        private:
            LifeScript& m_ls;
        public:
            LifeScriptConverterVisitor(LifeScript& ls);
            std::any visitGridstmt(LifeScriptParser::GridstmtContext *context) override;
            std::any visitPrefdef(LifeScriptParser::PrefdefContext *context) override;
            std::any visitAbscell(LifeScriptParser::AbscellContext *context) override;
            std::any visitAbsprefab(LifeScriptParser::AbsprefabContext *context) override;
        };

        LifeScript readScript(std::string& filename);
    };
};