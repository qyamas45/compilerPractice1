
// Generated from ./grammar/miniCPP.g4 by ANTLR 4.13.2


#include "miniCPPLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MiniCPPLexerStaticData final {
  MiniCPPLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCPPLexerStaticData(const MiniCPPLexerStaticData&) = delete;
  MiniCPPLexerStaticData(MiniCPPLexerStaticData&&) = delete;
  MiniCPPLexerStaticData& operator=(const MiniCPPLexerStaticData&) = delete;
  MiniCPPLexerStaticData& operator=(MiniCPPLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag minicpplexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MiniCPPLexerStaticData> minicpplexerLexerStaticData = nullptr;

void minicpplexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (minicpplexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(minicpplexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MiniCPPLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "ID", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'{'", "'}'", "'int'", "'float'", "'void'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,9,56,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,2,8,7,8,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,5,7,45,8,7,10,7,12,7,48,
  	9,7,1,8,4,8,51,8,8,11,8,12,8,52,1,8,1,8,0,0,9,1,1,3,2,5,3,7,4,9,5,11,
  	6,13,7,15,8,17,9,1,0,3,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,
  	122,3,0,9,10,13,13,32,32,57,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,
  	0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,
  	1,19,1,0,0,0,3,21,1,0,0,0,5,23,1,0,0,0,7,25,1,0,0,0,9,27,1,0,0,0,11,31,
  	1,0,0,0,13,37,1,0,0,0,15,42,1,0,0,0,17,50,1,0,0,0,19,20,5,40,0,0,20,2,
  	1,0,0,0,21,22,5,41,0,0,22,4,1,0,0,0,23,24,5,123,0,0,24,6,1,0,0,0,25,26,
  	5,125,0,0,26,8,1,0,0,0,27,28,5,105,0,0,28,29,5,110,0,0,29,30,5,116,0,
  	0,30,10,1,0,0,0,31,32,5,102,0,0,32,33,5,108,0,0,33,34,5,111,0,0,34,35,
  	5,97,0,0,35,36,5,116,0,0,36,12,1,0,0,0,37,38,5,118,0,0,38,39,5,111,0,
  	0,39,40,5,105,0,0,40,41,5,100,0,0,41,14,1,0,0,0,42,46,7,0,0,0,43,45,7,
  	1,0,0,44,43,1,0,0,0,45,48,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,0,47,16,1,
  	0,0,0,48,46,1,0,0,0,49,51,7,2,0,0,50,49,1,0,0,0,51,52,1,0,0,0,52,50,1,
  	0,0,0,52,53,1,0,0,0,53,54,1,0,0,0,54,55,6,8,0,0,55,18,1,0,0,0,3,0,46,
  	52,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minicpplexerLexerStaticData = std::move(staticData);
}

}

miniCPPLexer::miniCPPLexer(CharStream *input) : Lexer(input) {
  miniCPPLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *minicpplexerLexerStaticData->atn, minicpplexerLexerStaticData->decisionToDFA, minicpplexerLexerStaticData->sharedContextCache);
}

miniCPPLexer::~miniCPPLexer() {
  delete _interpreter;
}

std::string miniCPPLexer::getGrammarFileName() const {
  return "miniCPP.g4";
}

const std::vector<std::string>& miniCPPLexer::getRuleNames() const {
  return minicpplexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& miniCPPLexer::getChannelNames() const {
  return minicpplexerLexerStaticData->channelNames;
}

const std::vector<std::string>& miniCPPLexer::getModeNames() const {
  return minicpplexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& miniCPPLexer::getVocabulary() const {
  return minicpplexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView miniCPPLexer::getSerializedATN() const {
  return minicpplexerLexerStaticData->serializedATN;
}

const atn::ATN& miniCPPLexer::getATN() const {
  return *minicpplexerLexerStaticData->atn;
}




void miniCPPLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  minicpplexerLexerInitialize();
#else
  ::antlr4::internal::call_once(minicpplexerLexerOnceFlag, minicpplexerLexerInitialize);
#endif
}
