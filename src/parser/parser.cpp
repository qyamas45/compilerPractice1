

#include <memory>
#include "parser/parser.h"
#include "../../include/AST/Statements/Statement.h"
#include "../../include/AST/Expressions/Expressions.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Statements/ExpressionStatement.h"


#include <iostream>
//util functions

void Parser::fill(int n) {
    for (int i = 0; i < n; i++) {
        lookahead.push_back(input->nextToken());
    }
}
void Parser::synchronize(int index) {
    if (pos + index -1 > lookahead.size()-1) {
        int n = (pos+index-1) - (lookahead.size()-1);
        fill(n);
    }
}
void Parser::consume() {
    pos++;
    if (pos == lookahead.size()) {
        pos = 0;
        lookahead.clear();
    }
   //synchronize
}

Token Parser::peek() {
    std::cout << lookahead.size() << std::endl;
    if (current >= lookahead.size()) {

        std::cout << "TRIGGERED: " << std::endl;

        lookahead.push_back(input->nextToken());
    }

    return lookahead[current];
}
Token Parser::LT(int index) {
    return this->lookahead.at(pos + index-1);
}
tokenType Parser::LA(int index) {
    return LT(index).type;
}

void Parser::match(tokenType type) {

    if (LA(1) == type) {
        consume();
    }
}
//Grammar rules
std::unique_ptr<Program> Parser::parseProgram() {
    std::vector<std::unique_ptr<Statement>> statements;

    while (!check(tokenType::ENDOFFILE)) {
        statements.push_back(parseStatement());
    }
    return std::make_unique<Program>(std::move(statements));

}

std::unique_ptr<Statement> Parser::parseStatement() {


    return parseExpressionStatement();
}

std::unique_ptr<Statement> Parser::parseExpressionStatement() {

    auto expr = parseExpression();

    return std::make_unique<ExpressionStatement>(std::move(expr));

}
std::unique_ptr<Expressions> Parser::parseExpression() {

}

bool Parser::check(tokenType type) {
    return peek().type == type;

}

