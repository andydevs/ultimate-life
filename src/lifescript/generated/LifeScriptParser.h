
// Generated from LifeScript.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  LifeScriptParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, IDENTIFIER = 5, NEWLINE = 6, 
    WS = 7, RELNUM = 8, ABSNUM = 9
  };

  enum {
    RuleScript = 0, RuleGridstmt = 1, RulePrefdef = 2, RulePrefelems = 3, 
    RuleRelprefab = 4, RuleRelcell = 5, RuleAbscell = 6, RuleAbsprefab = 7
  };

  explicit LifeScriptParser(antlr4::TokenStream *input);

  LifeScriptParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~LifeScriptParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ScriptContext;
  class GridstmtContext;
  class PrefdefContext;
  class PrefelemsContext;
  class RelprefabContext;
  class RelcellContext;
  class AbscellContext;
  class AbsprefabContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrefdefContext *> prefdef();
    PrefdefContext* prefdef(size_t i);
    std::vector<GridstmtContext *> gridstmt();
    GridstmtContext* gridstmt(size_t i);
    std::vector<AbscellContext *> abscell();
    AbscellContext* abscell(size_t i);
    std::vector<AbsprefabContext *> absprefab();
    AbsprefabContext* absprefab(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScriptContext* script();

  class  GridstmtContext : public antlr4::ParserRuleContext {
  public:
    GridstmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ABSNUM();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GridstmtContext* gridstmt();

  class  PrefdefContext : public antlr4::ParserRuleContext {
  public:
    PrefdefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    PrefelemsContext *prefelems();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrefdefContext* prefdef();

  class  PrefelemsContext : public antlr4::ParserRuleContext {
  public:
    PrefelemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RelcellContext *> relcell();
    RelcellContext* relcell(size_t i);
    std::vector<RelprefabContext *> relprefab();
    RelprefabContext* relprefab(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrefelemsContext* prefelems();

  class  RelprefabContext : public antlr4::ParserRuleContext {
  public:
    RelprefabContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    RelcellContext *relcell();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelprefabContext* relprefab();

  class  RelcellContext : public antlr4::ParserRuleContext {
  public:
    RelcellContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ABSNUM();
    antlr4::tree::TerminalNode* ABSNUM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RELNUM();
    antlr4::tree::TerminalNode* RELNUM(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelcellContext* relcell();

  class  AbscellContext : public antlr4::ParserRuleContext {
  public:
    AbscellContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ABSNUM();
    antlr4::tree::TerminalNode* ABSNUM(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbscellContext* abscell();

  class  AbsprefabContext : public antlr4::ParserRuleContext {
  public:
    AbsprefabContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    AbscellContext *abscell();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbsprefabContext* absprefab();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

