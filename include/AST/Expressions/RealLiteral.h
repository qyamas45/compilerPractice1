//
// Created by alyam on 1/21/2026.
//

#ifndef COMPILERPRACTICE1_REALLITERAL_H
#define COMPILERPRACTICE1_REALLITERAL_H
#include "Literal.h"


class RealLiteral : public Literal {
public:

    explicit RealLiteral(float val) : value(val) {};
    float value;
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_REALLITERAL_H