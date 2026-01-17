//
// Created by alyam on 1/16/2026.
//

#ifndef COMPILERPRACTICE1_INTLITERAL_H
#define COMPILERPRACTICE1_INTLITERAL_H
#include "Literal.h"


class IntLiteral : public Literal {
    public:
    int value;

    explicit IntLiteral(const int value): value(value) {};
};


#endif //COMPILERPRACTICE1_INTLITERAL_H