//
// Created by alyam on 1/29/2026.
//

#ifndef COMPILERPRACTICE1_FORSTATEMENT_H
#define COMPILERPRACTICE1_FORSTATEMENT_H
#include "Statement.h"
#include "Var.h"
#include "../Expressions/Expressions.h"
//for(var, expression, arithmetic)
//{
// body
//}
class ForStatement : public Statement {
public:
    ForStatement() {
        this->condition = std::make_unique<Expressions>();
    }
    ForStatement(std::unique_ptr<Expressions> condition,
                std::unique_ptr<Var>var,
                std::vector<std::unique_ptr<Statement>>statement) {
        this->condition = std::move(condition);
        this->var = std::move(var);
        this->body = std::move(statement);

    }
    std::unique_ptr<Expressions>condition;
    std::unique_ptr<Var>var;
    std::vector<std::unique_ptr<Statement>> body;
};


#endif //COMPILERPRACTICE1_FORSTATEMENT_H