
// Generated from ./grammar/miniCPP.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "miniCPPListener.h"


/**
 * This class provides an empty implementation of miniCPPListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  miniCPPBaseListener : public miniCPPListener {
public:

  virtual void enterTranslationUnit(miniCPPParser::TranslationUnitContext * /*ctx*/) override { }
  virtual void exitTranslationUnit(miniCPPParser::TranslationUnitContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(miniCPPParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(miniCPPParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterType(miniCPPParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(miniCPPParser::TypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

