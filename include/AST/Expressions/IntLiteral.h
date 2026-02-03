//
// Created by alyam on 1/16/2026.
//

#ifndef COMPILERPRACTICE1_INTLITERAL_H
#define COMPILERPRACTICE1_INTLITERAL_H
#include "Literal.h"


class IntLiteral : public Literal {
public:


    IntLiteral(const int value): value(value) {};
    int value;
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_INTLITERAL_H