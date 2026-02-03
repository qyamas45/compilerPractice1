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
        this->condition = nullptr;
        this->var = nullptr;
        this->update = nullptr;
    }
    ForStatement(std::unique_ptr<Expressions> condition,
                std::unique_ptr<Var>var,
                std::vector<std::unique_ptr<Statement>>statement,
                std::unique_ptr<Expressions> update) {
        this->condition = std::move(condition);
        this->var = std::move(var);
        this->body = std::move(statement);

        Statement::addChild(std::move(condition));
        Statement::addChild(std::move(var));

        for (auto& stmt:statement) {
            Statement::addChild(std::move(stmt));
        }

    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Expressions>condition;
    std::unique_ptr<Var>var;
    std::vector<std::unique_ptr<Statement>> body;
    std::unique_ptr<Expressions> update;
};


#endif //COMPILERPRACTICE1_FORSTATEMENT_H