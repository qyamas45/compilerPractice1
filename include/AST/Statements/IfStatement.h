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
    std::unique_ptr<Expressions> condition;
    std::vector<std::unique_ptr<Statement>> body;
    std::vector<std::unique_ptr<Statement>> elseStatement;
    IfStatement() {
        this->condition = std::make_unique<Expressions>();

    }
    IfStatement(std::unique_ptr<Expressions> expr,
                std::vector<std::unique_ptr<Statement>> thenStatement) {
        this->condition = std::move(expr);
        this->elseStatement = std::move(thenStatement);
    }
    IfStatement(std::unique_ptr<Expressions> expr,
                std::vector<std::unique_ptr<Statement>> thenStatement,
                std::vector<std::unique_ptr<Statement>> elseStatement) {
        this->condition = std::move(expr);
        this->body = std::move(thenStatement);
        this->elseStatement = std::move(elseStatement);


    }
};


#endif //COMPILERPRACTICE1_IFSTATEMENT_H