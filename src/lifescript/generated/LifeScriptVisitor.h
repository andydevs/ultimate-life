
// Generated from LifeScript.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LifeScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LifeScriptParser.
 */
class  LifeScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LifeScriptParser.
   */
    virtual std::any visitScript(LifeScriptParser::ScriptContext *context) = 0;

    virtual std::any visitGridstmt(LifeScriptParser::GridstmtContext *context) = 0;

    virtual std::any visitPrefdef(LifeScriptParser::PrefdefContext *context) = 0;

    virtual std::any visitPrefelems(LifeScriptParser::PrefelemsContext *context) = 0;

    virtual std::any visitRelprefab(LifeScriptParser::RelprefabContext *context) = 0;

    virtual std::any visitRelcell(LifeScriptParser::RelcellContext *context) = 0;

    virtual std::any visitAbscell(LifeScriptParser::AbscellContext *context) = 0;

    virtual std::any visitAbsprefab(LifeScriptParser::AbsprefabContext *context) = 0;


};

