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
    }
}