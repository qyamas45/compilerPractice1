

#include <memory>
#include <string>
#include "parser/parser.h"
#include "../../include/AST/Statements/Statement.h"
#include "../../include/AST/Expressions/Expressions.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Statements/ExpressionStatement.h"
#include "../../include/AST/Expressions/Name.h"
#include "../../include/AST/Expressions/BinaryOperator.h"
#include "../../include/AST/Expressions/IntLiteral.h"
#include "../../include/AST/Statements/Var.h"
#include <iostream>
//util functions

void Parser::fill(int n) {
    for (int i = 1; i <= n; ++i) {
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
    synchronize(1);
}

bool Parser::expects() const {
    return !positions.empty();
}
Token Parser::peek() {

    if (current >= lookahead.size()) {

        lookahead.push_back(input->nextToken());
    }

    return lookahead[current];
}
Token Parser::LT(int index) {
    synchronize(index);
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
    // Program | Statements
    std::vector<std::unique_ptr<Statement>> statements;

    while (!check(tokenType::ENDOFFILE)) {
        statements.push_back(parseStatement());
    }
    return std::make_unique<Program>(std::move(statements));

}

std::unique_ptr<Statement> Parser::parseStatement() {
    //Statements | statement Statements
    //              epsilon

    //check if its while,if,for,def,class,try,return


    //else return expressionStatement
    return simpleStatement();
}

std::unique_ptr<Statement> Parser::simpleStatement() {
    //Statement | Var  |  Import
    //            Pass |  From
    if (check(tokenType::VAR)) {
        return declarationStatement();
    }
    return  parserExpressionStatement();
}


std::unique_ptr<Var> Parser::declarationStatement() {

}
std::unique_ptr<ExpressionStatement> Parser::parserExpressionStatement() {
    //var expr = new ExpressionStat(expression());
    auto expr = parseExpression();
    if (check(tokenType::SEMI)) {
        match(tokenType::SEMI);
    }
    return std::make_unique<ExpressionStatement>(std::move(expr));
}
std::unique_ptr<Expressions> Parser::parseExpression() {
    //logical operators here
    auto expr = atom();
    if (check(tokenType::ASSIGN) ){
        match(tokenType::ASSIGN);
        auto right = parseExpression();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), "=");


    }
    return expr;
}
std::unique_ptr<Expressions> Parser::atom() {
    std::string literal = LT(1).lexeme;
    // LiteralType | INT, REAL, STRING,
    //               BOOL, NONE, NAME
    if (check(tokenType::INDENT)) {
        std::string name = LT(1).lexeme;
        match(tokenType::INDENT);
        return std::unique_ptr<Expressions>(new Name(name));
    }
    if (check(tokenType::INT_LITERAL)) {
        match(tokenType::INT_LITERAL);
        auto val = std::stoi(literal);
        return std::unique_ptr<Expressions>(new IntLiteral(val));
    }

    return nullptr;
}
bool Parser::check(tokenType type) {
    return peek().type == type;

}

