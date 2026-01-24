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
                std::vector<Statement> thenStatement) {
        this->condition = std::move(expr);
    }
    IfStatement(std::unique_ptr<Expressions> expr,
                std::vector<Statement> thenStatement,
                std::vector<Statement> elseStatement) {
        this->condition = std::move(expr);


    }
};


#endif //COMPILERPRACTICE1_IFSTATEMENT_H