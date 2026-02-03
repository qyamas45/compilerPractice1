//
// Created by alyam on 1/20/2026.
//

#ifndef COMPILERPRACTICE1_ASSIGNMENT_H
#define COMPILERPRACTICE1_ASSIGNMENT_H
#include "Statement.h"
#include "../Expressions/Expressions.h"
#include <string>

class Assignment : public Statement{
public:
    Assignment(std::unique_ptr<Expressions>ident,
               std::unique_ptr<Expressions> expres,
               std::string oper) {
        this->identifier = std::move(ident);
        this->expression = std::move(expres);
        this->op = std::move(oper);
        Statement::addChild(std::move(expres));
        Statement::addChild(std::move(ident));
    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Expressions> identifier;
    std::unique_ptr<Expressions> expression;
    std::string op;
};


#endif //COMPILERPRACTICE1_ASSIGNMENT_H