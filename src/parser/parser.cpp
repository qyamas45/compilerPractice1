

#include <memory>
#include "parser/parser.h"
#include "../../include/AST/Statements/Statement.h"
#include "../../include/AST/Expressions/Expressions.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Statements/ExpressionStatement.h"


#include <iostream>
//util functions
Token Parser::peek() {
    if (current >= lookahead.size()) {
        lookahead.push_back(input->nextToken());
    }
    return lookahead[current];
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

