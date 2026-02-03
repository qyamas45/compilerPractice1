//
// Created by alyam on 1/17/2026.
//

#ifndef COMPILERPRACTICE1_VAR_H
#define COMPILERPRACTICE1_VAR_H
#include "Statement.h"
#include "../Expressions/Name.h"
#include "../Types/Type.h"
#include "../Expressions/Expressions.h"
/*
 * Represents variable
 * var name type [= expression]
 * @code in expression is optional
 */
class Var : public Statement{
public:
    Var(std::unique_ptr<Expressions>exp,
        std::unique_ptr<Type> type,
        std::unique_ptr<Name> name) {
        this->value = std::move(exp);
        this->type = std::move(type);
        this->name = std::move(name);

        Statement::addChild(std::move(name));
        Statement::addChild(std::move(type));

        if (exp != nullptr)
            Statement::addChild(std::move(exp));
    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Expressions> value;
    std::unique_ptr<Type> type;
    std::unique_ptr<Name> name;

};


#endif //COMPILERPRACTICE1_VAR_H