#include <memory>
#include <string>
#include "parser/parser.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Types/Type.h"
#include "../../include/AST/Types/IntType.h"
#include "../../include/AST/Types/RealType.h"

#include "../../include/AST/Statements/Assignment.h"
#include "../../include/AST/Statements/ExpressionStatement.h"
#include "../../include/AST/Statements/IfStatement.h"
#include "../../include/AST/Statements/ForStatement.h"
#include "../../include/AST/Statements/Statement.h"
#include "../../include/AST/Statements/Var.h"
#include "../../include/AST/Statements/WhileStatement.h"
#include "../../include/AST/Expressions/Expressions.h"
#include "../../include/AST/Expressions/Name.h"
#include "../../include/AST/Expressions/BinaryOperator.h"
#include "../../include/AST/Expressions/IntLiteral.h"
#include "../../include/AST/Expressions/RealLiteral.h"
#include "../../include/AST/Expressions/NoneLiteral.h"
#include "../../include/AST/Expressions/BoolLiteral.h"
#include "../../include/AST/Expressions/Group.h"


#include <iostream>

#include "AST/Expressions/BoolLiteral.h"
#include "AST/Expressions/NoneLiteral.h"
#include "AST/Expressions/NotOperator.h"
#include "AST/Expressions/StringLiteral.h"
#include "AST/Expressions/UnaryOperator.h"
#include "AST/Statements/Print.h"
#include "AST/Types/BoolType.h"
#include "AST/Types/NoneType.h"
#include "AST/Types/StringType.h"

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
    //std::cout << "called in  parser: " << statements.size() << std::endl;
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

    return nullptr;
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
    if (check(tokenType::PRINT)) {
        std::cout << "TEST";
        return printStatement();
    }
    return  parserExpressionStatement();
}
std::unique_ptr<Statement> Parser::printStatement() {
    match(tokenType::PRINT);

    auto val = parseExpression();
    if (check(tokenType::SEMI)) {
        match(tokenType::SEMI);
    }

    return std::make_unique<Print>(std::move(val));
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
    auto whileStatement = std::make_unique<WhileStatement>();
    whileStatement->condition = parseExpression();

    auto statements = block();
    whileStatement->body.insert(
    whileStatement->body.end(),
    std::make_move_iterator(statements.begin()),
    std::make_move_iterator(statements.end())
    );
    return std::make_unique<WhileStatement>(std::move(whileStatement->condition), std::move(statements));

}
std::unique_ptr<Statement> Parser::forStatement() {
    //for (var, expression, arithmetic(update)){
    // body
    //}
    //var
    match(tokenType::FOR);
    auto forStatement = std::make_unique<ForStatement>();
    forStatement->condition = parseExpression();
    if (check(tokenType::VAR)) {
        match(tokenType::VAR);
        forStatement->var = declarationStatement();
    } else if (!check(tokenType::SEMI)) {
        forStatement->var = declarationStatement();
    }
    match(tokenType::SEMI);
    //condition
    if (!check(tokenType::SEMI)) {
        forStatement->condition = parseExpression();
    }
    //update
    match(tokenType::SEMI);
    if (!check(tokenType::SEMI)) {
        forStatement->update = parseExpression();
    }
    match(tokenType::SEMI);
    //body
    auto statements = block();
    forStatement->body.insert(
        forStatement->body.end(),
        std::make_move_iterator(statements.begin()),
        std::make_move_iterator(statements.end())
        );
    return std::make_unique<ForStatement>(
        std::move(forStatement->condition),
        std::move(forStatement->var),
        std::move(forStatement->body),
        std::move(forStatement->update));
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
        || check(tokenType::INT) || check(tokenType::STRING) || check(tokenType::NONE)) {

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
    if (check(tokenType::STRING)) {
        match(tokenType::STRING);

        return std::make_unique<StringType>();
    }
    if (check(tokenType::NONE)) {
        match(tokenType::NONE);
        return std::make_unique<NoneType>();
    }
    if (check(tokenType::BOOL)) {
        match(tokenType::BOOL);
        return std::make_unique<BoolType>();
    }
    return nullptr;
}
std::unique_ptr<Var> Parser::declarationStatement() {

    match(tokenType::VAR);
    std::string name = LT(1).lexeme;

    match(tokenType::INDENT);
    auto typ = type();
    match(tokenType::ASSIGN);
    std::unique_ptr<Expressions> expr = parseExpression();

    //if var int x;
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
    auto expr = orExpression();
    if (check(tokenType::ASSIGN) ){
        match(tokenType::ASSIGN);
        auto right = parseExpression();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), "=");
    }
    return expr;
}
std::unique_ptr<Expressions> Parser::orExpression() {
    auto expr = andExpression();
    //if there is expression | expression
    if (check(tokenType::OR)) {
        std::string op = LT(1).lexeme;
        match(tokenType::OR);
        auto right = andExpression();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::andExpression() {
    auto expr = notExpression();
    //if there is expression & expression
    if (check(tokenType::AND)) {
        std::string op = LT(1).lexeme;
        match(tokenType::AND);
        auto right = notExpression();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::notExpression() {
    if (eatIfPresent(tokenType::NOT)) {
        auto expr = comparison();
        return std::make_unique<NotOperator>(std::move(expr));
    }
    return comparison();
}
std::unique_ptr<Expressions>Parser::comparison() {
    auto expr = atom();
    while (check({tokenType::EQUAL, tokenType::NOT_EQUAL, tokenType::LT,
        tokenType::LE, tokenType::GT, tokenType::GE, tokenType::IS
    }))
    {
        std::string op = LT(1).lexeme;
        if (LA(1) == tokenType::IS && LA(2) == tokenType::NOT) {
            match(tokenType::IS);
            op += " " + LT(1).lexeme;
            match(tokenType::NOT);
        }
        else {
            match({tokenType::EQUAL, tokenType::NOT_EQUAL, tokenType::LT,
            tokenType::LE, tokenType::GT, tokenType::GE, tokenType::IS});
        }
        auto right = atom();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::bitOrExpr() {
    auto expr = xorExpr();
    while (check(tokenType::BIT_OR)) {
        std::string op = LT(1).lexeme;
        match(tokenType::BIT_OR);
        auto right = xorExpr();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::xorExpr() {
    auto expr = bitAndExpr();
    while (check(tokenType::XOR)) {
        std::string op = LT(1).lexeme;
        match(tokenType::XOR);
        auto right = bitAndExpr();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::bitAndExpr() {
    auto expr = shiftExpr();
    while (check(tokenType::BIT_AND)) {
        std::string op = LT(1).lexeme;
        match(tokenType::BIT_AND);
        auto right = shiftExpr();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::shiftExpr() {
    auto expr = arithExpr();
    while (check({tokenType::SHIFT_RIGHT, tokenType::SHIFT_LEFT}))
    {
        std::string op = LT(1).lexeme;
        match({tokenType::SHIFT_RIGHT, tokenType::SHIFT_LEFT});
        auto right = arithExpr();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::arithExpr() {
    auto expr = term();
    while (check({tokenType::PLUS_EQUAL, tokenType::MINUS_EQUAL})) {
        std::string op = LT(1).lexeme;
        match({tokenType::PLUS_EQUAL, tokenType::MINUS_EQUAL});
        auto right = term();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::term() {
    auto expr = factor();
    while (check({tokenType::DIV, tokenType::MUL, tokenType::MOD})) {
        std::string op = LT(1).lexeme;
        match({tokenType::DIV, tokenType::MUL, tokenType::MOD});
        auto right = factor();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);
    }
    return expr;
}
std::unique_ptr<Expressions>Parser::factor() {
    if (check({tokenType::PLUS, tokenType::MINUS, tokenType::NEG})) {
        std::string op = LT(1).lexeme;
        match({tokenType::PLUS, tokenType::MINUS, tokenType::NEG});
        auto right = factor();
        return std::make_unique<UnaryOperator>(std::move(right), op);

    }
    return power();
}
std::unique_ptr<Expressions>Parser::power() {
    auto expr = atom();
    while (check(tokenType::POWER)) {
        std::string op = LT(1).lexeme;
        match({tokenType::POWER});
        auto right = factor();
        expr = std::make_unique<BinaryOperator>(std::move(expr), std::move(right), op);

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
        return std::make_unique<Name>(std::move(name));
    }
    if (check(tokenType::INT_LITERAL)) {
        match(tokenType::INT_LITERAL);
        auto val = std::stoi(literal);
        return std::make_unique<IntLiteral>(val);
    }
    if (check(tokenType::REAL_LITERAL)) {
        match(tokenType::REAL_LITERAL);
        auto val = std::stof(literal);
        return std::make_unique<RealLiteral>(val);
    }
    if (check(tokenType::STRING_LITERAL)) {
        match(tokenType::STRING_LITERAL);
        return std::make_unique<StringLiteral>(literal);
    }
    if (check(tokenType::NONE_LITERAL)) {
        match(tokenType::NONE_LITERAL);
        return std::make_unique<NoneLiteral>();
    }

    if (check({tokenType::TRUE, tokenType::FALSE})) {
        match({tokenType::TRUE, tokenType::FALSE});

        const bool val = (literal == "true");

        return std::make_unique<BoolLiteral>(val);

    }
    match(tokenType::PARENL);
    auto expr = parseExpression();
    match(tokenType::PARENR);
    return std::make_unique<Group>(std::move(expr));
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

