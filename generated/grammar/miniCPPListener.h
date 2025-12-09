
// Generated from ./grammar/miniCPP.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "miniCPPParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by miniCPPParser.
 */
class  miniCPPListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterTranslationUnit(miniCPPParser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(miniCPPParser::TranslationUnitContext *ctx) = 0;

  virtual void enterFunctionDecl(miniCPPParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(miniCPPParser::FunctionDeclContext *ctx) = 0;

  virtual void enterType(miniCPPParser::TypeContext *ctx) = 0;
  virtual void exitType(miniCPPParser::TypeContext *ctx) = 0;


};

