//
// Created by alyam on 1/25/2026.
//

#ifndef COMPILERPRACTICE1_GROUP_H
#define COMPILERPRACTICE1_GROUP_H
#include "Expressions.h"


class Group :public Expressions {
public:
    std::unique_ptr<Expressions> expr;
    Group(std::unique_ptr<Expressions> expr) {
        this->expr = std::move(expr);
    }
    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_GROUP_H