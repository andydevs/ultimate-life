#pragma once
#include <lifescript/lifescript.h>
#include <LifeScriptBaseVisitor.h>
#include <vector>
#include <string>
#include <map>

namespace ul
{
    namespace ls
    {
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
    }
}