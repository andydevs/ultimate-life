#pragma once
#include <ultimate_life/grid.h>
#include <lifescriptBaseVisitor.h>
#include <vector>
#include <string>
#include <map>

namespace ul
{
    namespace lc
    {
        using cell = std::pair<int, int>;

        struct LCElem {
            bool prefabbed;
            std::string prefab_name;
            cell cell;
        };

        class LifeConfig
        {
        public:
            void instantiate(Grid& grid);
            int grid_property(const std::string& name, int default_value);
            void set_grid_property(const std::string& name, int value);
            void add_prefab(const std::string& name, std::vector<LCElem>& elems);
            void add_elem(LCElem elem);
        private:
            std::map<std::string, int> m_grid_config;
            std::map<std::string, std::vector<LCElem>> m_prefabs;
            std::vector<LCElem> m_elems;
            void __instantiatePrefab(ul::Grid& grid, LCElem& elem);
        };

        struct LCOp
        {
            void apply(LifeConfig& cfg);
            int lcoptype;
            std::string property_name;
            int property_value;
            std::string prefab_name;
            std::vector<LCElem> prefab_elems;
            LCElem elem;
        };

        class LifeConfigVisitor : lifescriptBaseVisitor
        {
        public:
            std::any visitScript(lifescriptParser::ScriptContext *context) override;
            std::any visitGridstmt(lifescriptParser::GridstmtContext *context) override;
            std::any visitPrefdef(lifescriptParser::PrefdefContext *context) override;
            std::any visitRelprefab(lifescriptParser::RelprefabContext *context) override;
            std::any visitPrefelems(lifescriptParser::PrefelemsContext *context) override;
            std::any visitRelcell(lifescriptParser::RelcellContext *context) override;
            std::any visitAbscell(lifescriptParser::AbscellContext *context) override;
            std::any visitAbsprefab(lifescriptParser::AbsprefabContext *context) override;
        };

        LifeConfig readScript(std::string& filename);
    };
};