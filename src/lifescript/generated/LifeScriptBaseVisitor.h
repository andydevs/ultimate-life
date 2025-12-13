
// Generated from LifeScript.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "LifeScriptVisitor.h"


/**
 * This class provides an empty implementation of LifeScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LifeScriptBaseVisitor : public LifeScriptVisitor {
public:

  virtual std::any visitScript(LifeScriptParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGridstmt(LifeScriptParser::GridstmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefdef(LifeScriptParser::PrefdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrefelems(LifeScriptParser::PrefelemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelprefab(LifeScriptParser::RelprefabContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelcell(LifeScriptParser::RelcellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbscell(LifeScriptParser::AbscellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbsprefab(LifeScriptParser::AbsprefabContext *ctx) override {
    return visitChildren(ctx);
  }


};

