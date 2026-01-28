//
// Created by alyam on 1/28/2026.
//

#ifndef COMPILERPRACTICE1_UNARYOPERATOR_H
#define COMPILERPRACTICE1_UNARYOPERATOR_H
#include <ios>
#include <bits/ios_base.h>

#include "Expressions.h"


class UnaryOperator : public Expressions{
public:
    UnaryOperator(std::unique_ptr<Expressions> expr,
        std::string operation) {
        this->operation = operation;
        this->expr = std::move(expr);
    }
    std::unique_ptr<Expressions> expr;
    std::string operation;
};


#endif //COMPILERPRACTICE1_UNARYOPERATOR_H