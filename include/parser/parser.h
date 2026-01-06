//
// Created by alyam on 1/5/2026.
//
#include <memory>

#include "../AST/Expressions/Expressions.h"
#include "../AST/Statements/Statement.h"
#include "../lexer/token.h"
#include "../lexer/tokenType.h"
#ifndef COMPILERPRACTICE1_PARSER_H
#define COMPILERPRACTICE1_PARSER_H
class Parser {
    Parser(const std::vector<Token>& tokens);

    //Entry
    std::unique_ptr<AST> parseProgram();
    //Grammar
    std::unique_ptr<Statement> parseStatement();
    std::unique_ptr<Expressions> parseExpression();
private:
    const std::vector<Token> tokens;
    size_t current;

    bool match(tokenType type);
    Token consume(tokenType type);
    Token previous();
    bool isAtEnd();
};
#endif //COMPILERPRACTICE1_PARSER_H