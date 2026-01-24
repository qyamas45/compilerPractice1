//
// Created by alyam on 1/21/2026.
//

#ifndef COMPILERPRACTICE1_REALLITERAL_H
#define COMPILERPRACTICE1_REALLITERAL_H
#include "Literal.h"


class RealLiteral : public Literal {
public:
    float value;
    explicit RealLiteral(float val) : value(val) {};
};


#endif //COMPILERPRACTICE1_REALLITERAL_H