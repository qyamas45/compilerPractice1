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

#include "AST/Statements/Assignment.h"
#include "AST/Statements/ExpressionStatement.h"
#include "AST/Statements/Var.h"
#include "AST/Types/IntType.h"
#ifndef COMPILERPRACTICE1_PARSER_H
#define COMPILERPRACTICE1_PARSER_H
class Parser {
public:
    Parser(lexer* input) : pos(0), input(input), current(0) {
    }

    Token peek() const;

    Token peek();

    Token LT(int index);

    tokenType LA(int index);

    //Entry
    std::unique_ptr<Program> parseProgram();
    int pos;

private:

    //Grammar
    //Main program
    std::unique_ptr<Statement> parseStatement();

    std::unique_ptr<Statement> compoundStatement();
    std::unique_ptr<Statement> simpleStatement();

    std::unique_ptr<Var> declarationStatement();
    //Expressions
    std::unique_ptr<ExpressionStatement> parserExpressionStatement();
    std::unique_ptr<Expressions> parseExpression();
    std::unique_ptr<Expressions> orOperatorExpressions();
    std::unique_ptr<Expressions> andOperatorExpressions();
    std::unique_ptr<Expressions> notOperatorExpressions();
    std::unique_ptr<Expressions> equalOperatorExpressions();

    //Statements
    std::unique_ptr<Assignment> assignStatement();
    std::unique_ptr<Statement> ifStatement();
    std::unique_ptr<Statement> whileStatement();
    std::unique_ptr<Statement> forStatement();
    std::unique_ptr<Statement> defStatement();
    std::unique_ptr<Statement> classStatement();
    std::unique_ptr<Statement> returnStatement();

    std::vector<std::unique_ptr<Statement>> blocks();

    std::vector<std::unique_ptr<Statement>> block();

    //types
    std::unique_ptr<Type> type();
    std::unique_ptr<Type> valueType();
    std::unique_ptr<Expressions> atom();

    bool eatIfPresent(tokenType t);

    //util functions
    [[nodiscard]] bool expects() const;
    void fill(int n);
    void synchronize(int index);
    void consume();

    bool check(tokenType type);
    bool check(std::initializer_list<tokenType> types);
    void match(tokenType type);
    bool match(std::initializer_list<tokenType> types);
    //variables
    lexer* input;
    size_t current;
    std::vector<Token> lookahead;



};
#endif //COMPILERPRACTICE1_PARSER_H