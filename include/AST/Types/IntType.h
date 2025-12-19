//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_INTTYPE_H
#define COMPILERPRACTICE1_INTTYPE_H
#include "Type.h"
#include <string>

#endif //COMPILERPRACTICE1_INTTYPE_H

class IntType : public Type {
    public:
    static std::string toString() {
        return "int";
    }
    IntType* asIntType() {
        return this;
    }
    bool isIntType() {
        return true;
    }
};