//
// Created by alyam on 1/25/2026.
//

#ifndef COMPILERPRACTICE1_NOTOPERATOR_H
#define COMPILERPRACTICE1_NOTOPERATOR_H
#include "Expressions.h"


class NotOperator : public Expressions {
public:
    std::unique_ptr<Expressions> expression;
    NotOperator(std::unique_ptr<Expressions> expr) {
        this->expression = std::move(expr);
    }
};


#endif //COMPILERPRACTICE1_NOTOPERATOR_H