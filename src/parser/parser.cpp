#include <memory>
#include <string>
#include "parser/parser.h"
#include "../../include/AST/Types/Type.h"
#include "../../include/AST/Types/IntType.h"
#include "../../include/AST/Types/RealType.h"
#include "../../include/AST/Statements/Statement.h"
#include "../../include/AST/Statements/IfStatement.h"
#include "../../include/AST/Expressions/Expressions.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Statements/ExpressionStatement.h"
#include "../../include/AST/Expressions/Name.h"
#include "../../include/AST/Expressions/BinaryOperator.h"
#include "../../include/AST/Expressions/IntLiteral.h"
#include "../../include/AST/Expressions/RealLiteral.h"
#include "../../include/AST/Statements/Var.h"
#include "../../include/AST/Statements/Assignment.h"
#include <iostream>
//util functions
/*
 *  Function name: fill
 *  Parameters: int n
 *  Purpose: Push back lookahead (tokens)
 */
void Parser::fill(int n) {
    for (int i = 0; i < n; ++i) {
        lookahead.push_back(input->nextToken());
    }

}
/*
 *  Function name: synchronize
 *  Parameters: int index
 *  Purpose: synchronize the position of code parsed.
 */
void Parser::synchronize(int index) {

    if (pos + index > lookahead.size()) {
        int n = (pos+index) - (lookahead.size());
        //std::cout << n << std::endl;
        fill(n);
    }

}
/*
 *  Function name: consume
 *  Parameters:
 *  Purpose: Changes posiition of token
 */
void Parser::consume() {
    pos++;
    if (pos == lookahead.size()) {
        pos = 0;
        lookahead.clear();
    }
   //synchronize
    synchronize(1);
}

/*
 *  Function name: peek
 *  Parameters:
 *  Purpose: pushes token to lookahead vector of tokens
 *  Return: current token
 */
Token Parser::peek() {

    if (current >= lookahead.size()) {

        lookahead.push_back(input->nextToken());
    }

    return lookahead[current];
}
Token Parser::LT(int index) {
    synchronize(index);
    //std::cout << this->lookahead[pos + index-1].toString() << std::endl;

    return this->lookahead.at(pos + index-1);
}
tokenType Parser::LA(int index) {
    //std::cout << tokenTypeToString(LT(index).type) << std::endl;
    return LT(index).type;
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
    if (check({tokenType::IF, tokenType::WHILE, tokenType::FOR,
                    tokenType::DEF, tokenType::CLASS, tokenType::RETURN})) {
        return compoundStatement();
    }

    //else return expressionStatement
    return simpleStatement();
}
std::unique_ptr<Statement> Parser::compoundStatement() {
    if (check(tokenType::IF)) {
        return ifStatement();
    }
    if (check(tokenType::WHILE)) {
        return whileStatement();
    }
    if (check(tokenType::FOR)) {
        return forStatement();
    }
    if (check(tokenType::DEF)) {
        return defStatement();
    }
    if (check(tokenType::CLASS)) {
        return classStatement();
    }
    if (check(tokenType::RETURN)){
        return returnStatement();
    }
}
std::unique_ptr<Statement> Parser::simpleStatement() {
    //Statement | Var  |  Import
    //            Pass |  From
    if (LA(1) == tokenType::INDENT &&
        (LA(2) == tokenType::EQUAL  ||
        LA(2) == tokenType::MINUS_EQUAL ||
        LA(2) == tokenType::PLUS_EQUAL  ||
        LA(2) == tokenType::DIV_EQUAL))
    {

            return assignStatement();
    }

    if (check(tokenType::VAR)) {
        return declarationStatement();
    }
    return  parserExpressionStatement();
}
std::unique_ptr<Assignment> Parser::assignStatement() {

    auto identifier = std::make_unique<Name>(LT(1).lexeme);
    match(tokenType::INDENT);
    std::string op = LT(1).lexeme;
    match({tokenType::EQUAL, tokenType::MINUS_EQUAL,
        tokenType::PLUS_EQUAL, tokenType::DIV_EQUAL, tokenType::MUL_EQUAL,
        tokenType::POWER_EQUAL});
    auto val = parseExpression();
    if (check(tokenType::SEMI)) {
        match(tokenType::SEMI);
    }

    return std::make_unique<Assignment>(std::move(identifier),
        std::move(val), std::move(op));

}

std::unique_ptr<Statement> Parser::ifStatement() {
    match(tokenType::IF);
    auto ifStatement = std::make_unique<IfStatement>();
    ifStatement->condition = parseExpression();
    //ifStatement.body.addAll(block());
    auto statements = block();
    ifStatement->body.insert(
      ifStatement->body.end(),
      std::make_move_iterator(statements.begin()),
      std::make_move_iterator(statements.end())
    );
    //if there is else if
    if (eatIfPresent(tokenType::ELIF)) {
        //elif condition
        auto elif = parseExpression();
        auto elifBlock = block();
        //elif statement
        auto elifStatement = std::make_unique<IfStatement>(std::move(elif), std::move(elifBlock));
        //add to else
        ifStatement->elseStatement.push_back(std::move(elifStatement));
    }
    //if there is an else
    if (eatIfPresent(tokenType::ELSE)) {
        auto blockStatement = block();
        ifStatement->elseStatement.insert(
          ifStatement->elseStatement.end(),
          std::make_move_iterator(blockStatement.begin()),
          std::make_move_iterator(blockStatement.end())
        );
    }
    return std::make_unique<IfStatement>(std::move(ifStatement->condition),
        std::move(ifStatement->body),
        std::move(ifStatement->elseStatement));

}
std::unique_ptr<Statement> Parser::whileStatement() {
    match(tokenType::WHILE);

}
std::unique_ptr<Statement> Parser::forStatement() {

}
std::unique_ptr<Statement> Parser::defStatement() {

}
std::unique_ptr<Statement> Parser::classStatement() {

}
std::unique_ptr<Statement> Parser::returnStatement() {

}
 std::vector<std::unique_ptr<Statement>> Parser::block() {
    match(tokenType::CURLYL);
    std::vector<std::unique_ptr<Statement>> statements;
    while (check({tokenType::CURLYL, tokenType::ENDOFFILE})) {
        statements.push_back(parseStatement());
    }
    match(tokenType::CURLYR);
    if (check(tokenType::SEMI)) {
        match(tokenType::SEMI);
    }
    return statements;
}
std::unique_ptr<Type> Parser::type() {
    if (check(tokenType::REAL) || check(tokenType::BOOL)
        || check(tokenType::INT) || check(tokenType::STRING)) {
        return valueType();
    }
    return nullptr;
}

std::unique_ptr<Type> Parser::valueType() {
    if (check(tokenType::REAL)) {
        match(tokenType::REAL);
        return std::make_unique<RealType>();
    }
    if (check(tokenType::INT)) {
        match(tokenType::INT);
        return std::make_unique<IntType>();
    }
    return nullptr;
}
std::unique_ptr<Var> Parser::declarationStatement() {
    match(tokenType::VAR);
    std::string name = LT(1).lexeme;

    match(tokenType::INDENT);
    auto typ = type();
    match(tokenType::ASSIGN);
    auto expr = parseExpression();
    if (check(tokenType::SEMI))
        match(tokenType::SEMI);
    return std::make_unique<Var>(std::move(expr),
        std::move(typ),
        std::move(std::make_unique<Name>(std::move(name))));

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
    if (check(tokenType::REAL_LITERAL)) {
        match(tokenType::REAL_LITERAL);
        auto val = std::stof(literal);
        return std::unique_ptr<Expressions>(new RealLiteral(val));
    }
    return nullptr;
}
bool Parser::eatIfPresent(tokenType t) {
    if (LA(1) == t) {
        consume();
        return true;
    }
    return false;
}
bool Parser::check(tokenType type) {
    return LA(1) == type;
}
bool Parser::check(std::initializer_list<tokenType> types) {
    for (tokenType t: types) {
        if  (check(t))
            return true;
    }
    return false;
}
void Parser::match(tokenType type) {

    if (LA(1) == type) {
        consume();
    }
}
bool Parser::match(std::initializer_list<tokenType> types) {
    for (tokenType t: types) {
        if (LA(1) == t ) {
            consume();
            return true;
        }
    }
    return false;
}

