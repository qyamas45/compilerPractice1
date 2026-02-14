//
// Created by alyam on 1/23/2026.
//

#ifndef COMPILERPRACTICE1_IFSTATEMENT_H
#define COMPILERPRACTICE1_IFSTATEMENT_H
#include "Statement.h"
#include "../Expressions/Expressions.h"
#include <memory>
#include <vector>

class IfStatement : public Statement{
    public:
    IfStatement() {
        this->condition = nullptr;
        this->body = std::vector<std::unique_ptr<Statement>>();
        this->elseStatement = std::vector<std::unique_ptr<Statement>>();
    }
    IfStatement(std::unique_ptr<Expressions> expr,
                std::vector<std::unique_ptr<Statement>> thenStatement) {
        this->condition = std::move(expr);
        this->elseStatement = std::move(thenStatement);
    }
    IfStatement(std::unique_ptr<Expressions> expr,
                std::vector<std::unique_ptr<Statement>> thenStatement,
                std::vector<std::unique_ptr<Statement>> elseStatement) {
        std::cout << "in Else: " << elseStatement.size() << std::endl;
        this->condition = std::move(expr);
        this->body = std::move(thenStatement);
        this->elseStatement = std::move(elseStatement);
        Statement::addChild(std::move(expr));
        for (auto& stmt:thenStatement) {
            Statement::addChild(std::move(stmt));
        }
        for (auto& stmt:elseStatement) {

            Statement::addChild(std::move(stmt));
        }
    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Expressions> condition;
    std::vector<std::unique_ptr<Statement>> body;
    std::vector<std::unique_ptr<Statement>> elseStatement;
};


#endif //COMPILERPRACTICE1_IFSTATEMENT_H