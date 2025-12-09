
// Generated from ./grammar/miniCPP.g4 by ANTLR 4.13.2


#include "miniCPPListener.h"

#include "miniCPPParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct MiniCPPParserStaticData final {
  MiniCPPParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MiniCPPParserStaticData(const MiniCPPParserStaticData&) = delete;
  MiniCPPParserStaticData(MiniCPPParserStaticData&&) = delete;
  MiniCPPParserStaticData& operator=(const MiniCPPParserStaticData&) = delete;
  MiniCPPParserStaticData& operator=(MiniCPPParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag minicppParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MiniCPPParserStaticData> minicppParserStaticData = nullptr;

void minicppParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (minicppParserStaticData != nullptr) {
    return;
  }
#else
  assert(minicppParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MiniCPPParserStaticData>(
    std::vector<std::string>{
      "translationUnit", "functionDecl", "type"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'{'", "'}'", "'int'", "'float'", "'void'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,9,24,2,0,7,0,2,1,7,1,2,2,7,2,1,0,5,0,8,8,0,10,0,12,0,11,9,0,1,0,1,
  	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,0,0,3,0,2,4,0,1,1,0,5,7,21,
  	0,9,1,0,0,0,2,14,1,0,0,0,4,21,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,11,1,
  	0,0,0,9,7,1,0,0,0,9,10,1,0,0,0,10,12,1,0,0,0,11,9,1,0,0,0,12,13,5,0,0,
  	1,13,1,1,0,0,0,14,15,3,4,2,0,15,16,5,8,0,0,16,17,5,1,0,0,17,18,5,2,0,
  	0,18,19,5,3,0,0,19,20,5,4,0,0,20,3,1,0,0,0,21,22,7,0,0,0,22,5,1,0,0,0,
  	1,9
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  minicppParserStaticData = std::move(staticData);
}

}

miniCPPParser::miniCPPParser(TokenStream *input) : miniCPPParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

miniCPPParser::miniCPPParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  miniCPPParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *minicppParserStaticData->atn, minicppParserStaticData->decisionToDFA, minicppParserStaticData->sharedContextCache, options);
}

miniCPPParser::~miniCPPParser() {
  delete _interpreter;
}

const atn::ATN& miniCPPParser::getATN() const {
  return *minicppParserStaticData->atn;
}

std::string miniCPPParser::getGrammarFileName() const {
  return "miniCPP.g4";
}

const std::vector<std::string>& miniCPPParser::getRuleNames() const {
  return minicppParserStaticData->ruleNames;
}

const dfa::Vocabulary& miniCPPParser::getVocabulary() const {
  return minicppParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView miniCPPParser::getSerializedATN() const {
  return minicppParserStaticData->serializedATN;
}


//----------------- TranslationUnitContext ------------------------------------------------------------------

miniCPPParser::TranslationUnitContext::TranslationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* miniCPPParser::TranslationUnitContext::EOF() {
  return getToken(miniCPPParser::EOF, 0);
}

std::vector<miniCPPParser::FunctionDeclContext *> miniCPPParser::TranslationUnitContext::functionDecl() {
  return getRuleContexts<miniCPPParser::FunctionDeclContext>();
}

miniCPPParser::FunctionDeclContext* miniCPPParser::TranslationUnitContext::functionDecl(size_t i) {
  return getRuleContext<miniCPPParser::FunctionDeclContext>(i);
}


size_t miniCPPParser::TranslationUnitContext::getRuleIndex() const {
  return miniCPPParser::RuleTranslationUnit;
}

void miniCPPParser::TranslationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTranslationUnit(this);
}

void miniCPPParser::TranslationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTranslationUnit(this);
}

miniCPPParser::TranslationUnitContext* miniCPPParser::translationUnit() {
  TranslationUnitContext *_localctx = _tracker.createInstance<TranslationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, miniCPPParser::RuleTranslationUnit);
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
    setState(9);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 224) != 0)) {
      setState(6);
      functionDecl();
      setState(11);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(12);
    match(miniCPPParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

miniCPPParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

miniCPPParser::TypeContext* miniCPPParser::FunctionDeclContext::type() {
  return getRuleContext<miniCPPParser::TypeContext>(0);
}

tree::TerminalNode* miniCPPParser::FunctionDeclContext::ID() {
  return getToken(miniCPPParser::ID, 0);
}


size_t miniCPPParser::FunctionDeclContext::getRuleIndex() const {
  return miniCPPParser::RuleFunctionDecl;
}

void miniCPPParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void miniCPPParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

miniCPPParser::FunctionDeclContext* miniCPPParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, miniCPPParser::RuleFunctionDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    type();
    setState(15);
    match(miniCPPParser::ID);
    setState(16);
    match(miniCPPParser::T__0);
    setState(17);
    match(miniCPPParser::T__1);
    setState(18);
    match(miniCPPParser::T__2);
    setState(19);
    match(miniCPPParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

miniCPPParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t miniCPPParser::TypeContext::getRuleIndex() const {
  return miniCPPParser::RuleType;
}

void miniCPPParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void miniCPPParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<miniCPPListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

miniCPPParser::TypeContext* miniCPPParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 4, miniCPPParser::RuleType);
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
    setState(21);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 224) != 0))) {
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

void miniCPPParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  minicppParserInitialize();
#else
  ::antlr4::internal::call_once(minicppParserOnceFlag, minicppParserInitialize);
#endif
}
