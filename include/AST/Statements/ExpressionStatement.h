//
// Created by alyam on 1/12/2026.
//

#ifndef COMPILERPRACTICE1_EXPRESSIONSTATEMENT_H
#define COMPILERPRACTICE1_EXPRESSIONSTATEMENT_H

#include "Statement.h"
#include "../Expressions/Expressions.h"
#include <memory>
#pragma once


class ExpressionStatement  : public Statement{
public:
    //Expressions exp;
    explicit ExpressionStatement(std::unique_ptr<Expressions> expr)
        : expression(std::move(expr)) {
        addChild(std::move(expr));
    }
    ~ExpressionStatement() override = default;

    std::unique_ptr<Expressions> expression;
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_EXPRESSIONSTATEMENT_H