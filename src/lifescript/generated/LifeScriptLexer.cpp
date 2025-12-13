
// Generated from LifeScript.g4 by ANTLR 4.13.2


#include "LifeScriptLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LifeScriptLexerStaticData final {
  LifeScriptLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LifeScriptLexerStaticData(const LifeScriptLexerStaticData&) = delete;
  LifeScriptLexerStaticData(LifeScriptLexerStaticData&&) = delete;
  LifeScriptLexerStaticData& operator=(const LifeScriptLexerStaticData&) = delete;
  LifeScriptLexerStaticData& operator=(LifeScriptLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag lifescriptlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<LifeScriptLexerStaticData> lifescriptlexerLexerStaticData = nullptr;

void lifescriptlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (lifescriptlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(lifescriptlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<LifeScriptLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "IDENTIFIER", "NEWLINE", "WS", "RELNUM", 
      "ABSNUM"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'grid'", "'def'", "'end'", "'@'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "IDENTIFIER", "NEWLINE", "WS", "RELNUM", "ABSNUM"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,9,72,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,2,8,7,8,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,
  	3,1,3,1,4,1,4,5,4,37,8,4,10,4,12,4,40,9,4,1,5,1,5,5,5,44,8,5,10,5,12,
  	5,47,9,5,3,5,49,8,5,1,5,3,5,52,8,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,
  	7,1,7,4,7,64,8,7,11,7,12,7,65,1,8,4,8,69,8,8,11,8,12,8,70,1,45,0,9,1,
  	1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,1,0,4,3,0,65,90,95,95,97,122,4,
  	0,48,57,65,90,95,95,97,122,2,0,9,9,32,32,2,0,43,43,45,45,77,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,1,19,1,0,0,0,3,24,1,0,0,0,5,28,1,0,0,
  	0,7,32,1,0,0,0,9,34,1,0,0,0,11,48,1,0,0,0,13,57,1,0,0,0,15,61,1,0,0,0,
  	17,68,1,0,0,0,19,20,5,103,0,0,20,21,5,114,0,0,21,22,5,105,0,0,22,23,5,
  	100,0,0,23,2,1,0,0,0,24,25,5,100,0,0,25,26,5,101,0,0,26,27,5,102,0,0,
  	27,4,1,0,0,0,28,29,5,101,0,0,29,30,5,110,0,0,30,31,5,100,0,0,31,6,1,0,
  	0,0,32,33,5,64,0,0,33,8,1,0,0,0,34,38,7,0,0,0,35,37,7,1,0,0,36,35,1,0,
  	0,0,37,40,1,0,0,0,38,36,1,0,0,0,38,39,1,0,0,0,39,10,1,0,0,0,40,38,1,0,
  	0,0,41,45,5,35,0,0,42,44,9,0,0,0,43,42,1,0,0,0,44,47,1,0,0,0,45,46,1,
  	0,0,0,45,43,1,0,0,0,46,49,1,0,0,0,47,45,1,0,0,0,48,41,1,0,0,0,48,49,1,
  	0,0,0,49,51,1,0,0,0,50,52,5,13,0,0,51,50,1,0,0,0,51,52,1,0,0,0,52,53,
  	1,0,0,0,53,54,5,10,0,0,54,55,1,0,0,0,55,56,6,5,0,0,56,12,1,0,0,0,57,58,
  	7,2,0,0,58,59,1,0,0,0,59,60,6,6,0,0,60,14,1,0,0,0,61,63,7,3,0,0,62,64,
  	2,48,57,0,63,62,1,0,0,0,64,65,1,0,0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,
  	16,1,0,0,0,67,69,2,48,57,0,68,67,1,0,0,0,69,70,1,0,0,0,70,68,1,0,0,0,
  	70,71,1,0,0,0,71,18,1,0,0,0,7,0,38,45,48,51,65,70,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  lifescriptlexerLexerStaticData = std::move(staticData);
}

}

LifeScriptLexer::LifeScriptLexer(CharStream *input) : Lexer(input) {
  LifeScriptLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *lifescriptlexerLexerStaticData->atn, lifescriptlexerLexerStaticData->decisionToDFA, lifescriptlexerLexerStaticData->sharedContextCache);
}

LifeScriptLexer::~LifeScriptLexer() {
  delete _interpreter;
}

std::string LifeScriptLexer::getGrammarFileName() const {
  return "LifeScript.g4";
}

const std::vector<std::string>& LifeScriptLexer::getRuleNames() const {
  return lifescriptlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& LifeScriptLexer::getChannelNames() const {
  return lifescriptlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& LifeScriptLexer::getModeNames() const {
  return lifescriptlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& LifeScriptLexer::getVocabulary() const {
  return lifescriptlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView LifeScriptLexer::getSerializedATN() const {
  return lifescriptlexerLexerStaticData->serializedATN;
}

const atn::ATN& LifeScriptLexer::getATN() const {
  return *lifescriptlexerLexerStaticData->atn;
}




void LifeScriptLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  lifescriptlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(lifescriptlexerLexerOnceFlag, lifescriptlexerLexerInitialize);
#endif
}
