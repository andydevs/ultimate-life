
// Generated from LifeScript.g4 by ANTLR 4.13.1


#include "LifeScriptVisitor.h"

#include "LifeScriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LifeScriptParserStaticData final {
  LifeScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LifeScriptParserStaticData(const LifeScriptParserStaticData&) = delete;
  LifeScriptParserStaticData(LifeScriptParserStaticData&&) = delete;
  LifeScriptParserStaticData& operator=(const LifeScriptParserStaticData&) = delete;
  LifeScriptParserStaticData& operator=(LifeScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lifescriptParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
LifeScriptParserStaticData *lifescriptParserStaticData = nullptr;

void lifescriptParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lifescriptParserStaticData != nullptr) {
    return;
  }
#else
  assert(lifescriptParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LifeScriptParserStaticData>(
    std::vector<std::string>{
      "script", "gridstmt", "prefdef", "prefelems", "relprefab", "relcell", 
      "abscell", "absprefab"
    },
    std::vector<std::string>{
      "", "'grid'", "'def'", "'end'", "'@'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "IDENTIFIER", "NEWLINE", "WS", "RELNUM", "ABSNUM"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,9,56,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,1,0,1,0,1,0,5,0,21,8,0,10,0,12,0,24,9,0,1,1,1,1,1,1,1,1,1,2,1,
  	2,1,2,1,2,1,2,1,3,1,3,5,3,37,8,3,10,3,12,3,40,9,3,1,4,1,4,1,4,1,4,1,5,
  	1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,1,
  	1,0,8,9,53,0,22,1,0,0,0,2,25,1,0,0,0,4,29,1,0,0,0,6,38,1,0,0,0,8,41,1,
  	0,0,0,10,45,1,0,0,0,12,48,1,0,0,0,14,51,1,0,0,0,16,21,3,4,2,0,17,21,3,
  	2,1,0,18,21,3,12,6,0,19,21,3,14,7,0,20,16,1,0,0,0,20,17,1,0,0,0,20,18,
  	1,0,0,0,20,19,1,0,0,0,21,24,1,0,0,0,22,20,1,0,0,0,22,23,1,0,0,0,23,1,
  	1,0,0,0,24,22,1,0,0,0,25,26,5,1,0,0,26,27,5,5,0,0,27,28,5,9,0,0,28,3,
  	1,0,0,0,29,30,5,2,0,0,30,31,5,5,0,0,31,32,3,6,3,0,32,33,5,3,0,0,33,5,
  	1,0,0,0,34,37,3,10,5,0,35,37,3,8,4,0,36,34,1,0,0,0,36,35,1,0,0,0,37,40,
  	1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,7,1,0,0,0,40,38,1,0,0,0,41,42,
  	5,4,0,0,42,43,5,5,0,0,43,44,3,10,5,0,44,9,1,0,0,0,45,46,7,0,0,0,46,47,
  	7,0,0,0,47,11,1,0,0,0,48,49,5,9,0,0,49,50,5,9,0,0,50,13,1,0,0,0,51,52,
  	5,4,0,0,52,53,5,5,0,0,53,54,3,12,6,0,54,15,1,0,0,0,4,20,22,36,38
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lifescriptParserStaticData = staticData.release();
}

}

LifeScriptParser::LifeScriptParser(TokenStream *input) : LifeScriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

LifeScriptParser::LifeScriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  LifeScriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *lifescriptParserStaticData->atn, lifescriptParserStaticData->decisionToDFA, lifescriptParserStaticData->sharedContextCache, options);
}

LifeScriptParser::~LifeScriptParser() {
  delete _interpreter;
}

const atn::ATN& LifeScriptParser::getATN() const {
  return *lifescriptParserStaticData->atn;
}

std::string LifeScriptParser::getGrammarFileName() const {
  return "LifeScript.g4";
}

const std::vector<std::string>& LifeScriptParser::getRuleNames() const {
  return lifescriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& LifeScriptParser::getVocabulary() const {
  return lifescriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LifeScriptParser::getSerializedATN() const {
  return lifescriptParserStaticData->serializedATN;
}


//----------------- ScriptContext ------------------------------------------------------------------

LifeScriptParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LifeScriptParser::PrefdefContext *> LifeScriptParser::ScriptContext::prefdef() {
  return getRuleContexts<LifeScriptParser::PrefdefContext>();
}

LifeScriptParser::PrefdefContext* LifeScriptParser::ScriptContext::prefdef(size_t i) {
  return getRuleContext<LifeScriptParser::PrefdefContext>(i);
}

std::vector<LifeScriptParser::GridstmtContext *> LifeScriptParser::ScriptContext::gridstmt() {
  return getRuleContexts<LifeScriptParser::GridstmtContext>();
}

LifeScriptParser::GridstmtContext* LifeScriptParser::ScriptContext::gridstmt(size_t i) {
  return getRuleContext<LifeScriptParser::GridstmtContext>(i);
}

std::vector<LifeScriptParser::AbscellContext *> LifeScriptParser::ScriptContext::abscell() {
  return getRuleContexts<LifeScriptParser::AbscellContext>();
}

LifeScriptParser::AbscellContext* LifeScriptParser::ScriptContext::abscell(size_t i) {
  return getRuleContext<LifeScriptParser::AbscellContext>(i);
}

std::vector<LifeScriptParser::AbsprefabContext *> LifeScriptParser::ScriptContext::absprefab() {
  return getRuleContexts<LifeScriptParser::AbsprefabContext>();
}

LifeScriptParser::AbsprefabContext* LifeScriptParser::ScriptContext::absprefab(size_t i) {
  return getRuleContext<LifeScriptParser::AbsprefabContext>(i);
}


size_t LifeScriptParser::ScriptContext::getRuleIndex() const {
  return LifeScriptParser::RuleScript;
}


std::any LifeScriptParser::ScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitScript(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::ScriptContext* LifeScriptParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 0, LifeScriptParser::RuleScript);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 534) != 0)) {
      setState(20);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LifeScriptParser::T__1: {
          setState(16);
          prefdef();
          break;
        }

        case LifeScriptParser::T__0: {
          setState(17);
          gridstmt();
          break;
        }

        case LifeScriptParser::ABSNUM: {
          setState(18);
          abscell();
          break;
        }

        case LifeScriptParser::T__3: {
          setState(19);
          absprefab();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(24);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GridstmtContext ------------------------------------------------------------------

LifeScriptParser::GridstmtContext::GridstmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LifeScriptParser::GridstmtContext::IDENTIFIER() {
  return getToken(LifeScriptParser::IDENTIFIER, 0);
}

tree::TerminalNode* LifeScriptParser::GridstmtContext::ABSNUM() {
  return getToken(LifeScriptParser::ABSNUM, 0);
}


size_t LifeScriptParser::GridstmtContext::getRuleIndex() const {
  return LifeScriptParser::RuleGridstmt;
}


std::any LifeScriptParser::GridstmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitGridstmt(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::GridstmtContext* LifeScriptParser::gridstmt() {
  GridstmtContext *_localctx = _tracker.createInstance<GridstmtContext>(_ctx, getState());
  enterRule(_localctx, 2, LifeScriptParser::RuleGridstmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(LifeScriptParser::T__0);
    setState(26);
    match(LifeScriptParser::IDENTIFIER);
    setState(27);
    match(LifeScriptParser::ABSNUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefdefContext ------------------------------------------------------------------

LifeScriptParser::PrefdefContext::PrefdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LifeScriptParser::PrefdefContext::IDENTIFIER() {
  return getToken(LifeScriptParser::IDENTIFIER, 0);
}

LifeScriptParser::PrefelemsContext* LifeScriptParser::PrefdefContext::prefelems() {
  return getRuleContext<LifeScriptParser::PrefelemsContext>(0);
}


size_t LifeScriptParser::PrefdefContext::getRuleIndex() const {
  return LifeScriptParser::RulePrefdef;
}


std::any LifeScriptParser::PrefdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitPrefdef(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::PrefdefContext* LifeScriptParser::prefdef() {
  PrefdefContext *_localctx = _tracker.createInstance<PrefdefContext>(_ctx, getState());
  enterRule(_localctx, 4, LifeScriptParser::RulePrefdef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(LifeScriptParser::T__1);
    setState(30);
    match(LifeScriptParser::IDENTIFIER);
    setState(31);
    prefelems();
    setState(32);
    match(LifeScriptParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrefelemsContext ------------------------------------------------------------------

LifeScriptParser::PrefelemsContext::PrefelemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LifeScriptParser::RelcellContext *> LifeScriptParser::PrefelemsContext::relcell() {
  return getRuleContexts<LifeScriptParser::RelcellContext>();
}

LifeScriptParser::RelcellContext* LifeScriptParser::PrefelemsContext::relcell(size_t i) {
  return getRuleContext<LifeScriptParser::RelcellContext>(i);
}

std::vector<LifeScriptParser::RelprefabContext *> LifeScriptParser::PrefelemsContext::relprefab() {
  return getRuleContexts<LifeScriptParser::RelprefabContext>();
}

LifeScriptParser::RelprefabContext* LifeScriptParser::PrefelemsContext::relprefab(size_t i) {
  return getRuleContext<LifeScriptParser::RelprefabContext>(i);
}


size_t LifeScriptParser::PrefelemsContext::getRuleIndex() const {
  return LifeScriptParser::RulePrefelems;
}


std::any LifeScriptParser::PrefelemsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitPrefelems(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::PrefelemsContext* LifeScriptParser::prefelems() {
  PrefelemsContext *_localctx = _tracker.createInstance<PrefelemsContext>(_ctx, getState());
  enterRule(_localctx, 6, LifeScriptParser::RulePrefelems);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 784) != 0)) {
      setState(36);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case LifeScriptParser::RELNUM:
        case LifeScriptParser::ABSNUM: {
          setState(34);
          relcell();
          break;
        }

        case LifeScriptParser::T__3: {
          setState(35);
          relprefab();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(40);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelprefabContext ------------------------------------------------------------------

LifeScriptParser::RelprefabContext::RelprefabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LifeScriptParser::RelprefabContext::IDENTIFIER() {
  return getToken(LifeScriptParser::IDENTIFIER, 0);
}

LifeScriptParser::RelcellContext* LifeScriptParser::RelprefabContext::relcell() {
  return getRuleContext<LifeScriptParser::RelcellContext>(0);
}


size_t LifeScriptParser::RelprefabContext::getRuleIndex() const {
  return LifeScriptParser::RuleRelprefab;
}


std::any LifeScriptParser::RelprefabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitRelprefab(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::RelprefabContext* LifeScriptParser::relprefab() {
  RelprefabContext *_localctx = _tracker.createInstance<RelprefabContext>(_ctx, getState());
  enterRule(_localctx, 8, LifeScriptParser::RuleRelprefab);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(LifeScriptParser::T__3);
    setState(42);
    match(LifeScriptParser::IDENTIFIER);
    setState(43);
    relcell();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelcellContext ------------------------------------------------------------------

LifeScriptParser::RelcellContext::RelcellContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LifeScriptParser::RelcellContext::ABSNUM() {
  return getTokens(LifeScriptParser::ABSNUM);
}

tree::TerminalNode* LifeScriptParser::RelcellContext::ABSNUM(size_t i) {
  return getToken(LifeScriptParser::ABSNUM, i);
}

std::vector<tree::TerminalNode *> LifeScriptParser::RelcellContext::RELNUM() {
  return getTokens(LifeScriptParser::RELNUM);
}

tree::TerminalNode* LifeScriptParser::RelcellContext::RELNUM(size_t i) {
  return getToken(LifeScriptParser::RELNUM, i);
}


size_t LifeScriptParser::RelcellContext::getRuleIndex() const {
  return LifeScriptParser::RuleRelcell;
}


std::any LifeScriptParser::RelcellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitRelcell(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::RelcellContext* LifeScriptParser::relcell() {
  RelcellContext *_localctx = _tracker.createInstance<RelcellContext>(_ctx, getState());
  enterRule(_localctx, 10, LifeScriptParser::RuleRelcell);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _la = _input->LA(1);
    if (!(_la == LifeScriptParser::RELNUM

    || _la == LifeScriptParser::ABSNUM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(46);
    _la = _input->LA(1);
    if (!(_la == LifeScriptParser::RELNUM

    || _la == LifeScriptParser::ABSNUM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbscellContext ------------------------------------------------------------------

LifeScriptParser::AbscellContext::AbscellContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LifeScriptParser::AbscellContext::ABSNUM() {
  return getTokens(LifeScriptParser::ABSNUM);
}

tree::TerminalNode* LifeScriptParser::AbscellContext::ABSNUM(size_t i) {
  return getToken(LifeScriptParser::ABSNUM, i);
}


size_t LifeScriptParser::AbscellContext::getRuleIndex() const {
  return LifeScriptParser::RuleAbscell;
}


std::any LifeScriptParser::AbscellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitAbscell(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::AbscellContext* LifeScriptParser::abscell() {
  AbscellContext *_localctx = _tracker.createInstance<AbscellContext>(_ctx, getState());
  enterRule(_localctx, 12, LifeScriptParser::RuleAbscell);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(LifeScriptParser::ABSNUM);
    setState(49);
    match(LifeScriptParser::ABSNUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AbsprefabContext ------------------------------------------------------------------

LifeScriptParser::AbsprefabContext::AbsprefabContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LifeScriptParser::AbsprefabContext::IDENTIFIER() {
  return getToken(LifeScriptParser::IDENTIFIER, 0);
}

LifeScriptParser::AbscellContext* LifeScriptParser::AbsprefabContext::abscell() {
  return getRuleContext<LifeScriptParser::AbscellContext>(0);
}


size_t LifeScriptParser::AbsprefabContext::getRuleIndex() const {
  return LifeScriptParser::RuleAbsprefab;
}


std::any LifeScriptParser::AbsprefabContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<LifeScriptVisitor*>(visitor))
    return parserVisitor->visitAbsprefab(this);
  else
    return visitor->visitChildren(this);
}

LifeScriptParser::AbsprefabContext* LifeScriptParser::absprefab() {
  AbsprefabContext *_localctx = _tracker.createInstance<AbsprefabContext>(_ctx, getState());
  enterRule(_localctx, 14, LifeScriptParser::RuleAbsprefab);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(LifeScriptParser::T__3);
    setState(52);
    match(LifeScriptParser::IDENTIFIER);
    setState(53);
    abscell();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void LifeScriptParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lifescriptParserInitialize();
#else
  ::antlr4::internal::call_once(lifescriptParserOnceFlag, lifescriptParserInitialize);
#endif
}
