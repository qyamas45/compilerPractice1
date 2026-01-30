//
// Created by alyam on 1/29/2026.
//

#ifndef COMPILERPRACTICE1_BOOLLITERAL_H
#define COMPILERPRACTICE1_BOOLLITERAL_H
#include "Literal.h"


class BoolLiteral : public Literal{
public:
    bool value;
    explicit BoolLiteral(bool value) : value(value) {};
};


#endif //COMPILERPRACTICE1_BOOLLITERAL_H