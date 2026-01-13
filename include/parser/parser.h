//
// Created by alyam on 1/5/2026.
//
#include <memory>

#include "../AST/Expressions/Expressions.h"
#include "../AST/Statements/Statement.h"
#include "../lexer/token.h"
#include "../lexer/tokenType.h"
#include "../AST/Program.h"
#include "lexer/lexer.h"
#include <utility>
#include <vector>
#ifndef COMPILERPRACTICE1_PARSER_H
#define COMPILERPRACTICE1_PARSER_H
class Parser {
public:
    Parser(lexer* input) : input(input), current(0) {}

    Token peek() const;

    Token peek();

    //Entry
    std::unique_ptr<Program> parseProgram();


private:

    //Grammar
    std::unique_ptr<Statement> parseStatement();

    std::unique_ptr<Statement> parseExpressionStatement();

    std::unique_ptr<Expressions> parseExpression();

    lexer* input;
    size_t current;
    std::vector<Token> lookahead;
    std::vector<int> positions;

    Token consume(tokenType type);
    Token previous();
    bool match(tokenType type);
    bool check(tokenType type);
};
#endif //COMPILERPRACTICE1_PARSER_H