//
// Created by alyam on 1/29/2026.
//

#ifndef COMPILERPRACTICE1_BOOLLITERAL_H
#define COMPILERPRACTICE1_BOOLLITERAL_H
#include "Literal.h"


class BoolLiteral : public Literal{
public:

    BoolLiteral(bool value) : value(value) {};
    bool value;
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_BOOLLITERAL_H