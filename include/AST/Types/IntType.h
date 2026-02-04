//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_INTTYPE_H
#define COMPILERPRACTICE1_INTTYPE_H
#include "Type.h"
#include <string>
class IntType : public Type {
public:
    std::string toString() const override {
        return "int";
    }
    IntType* asIntType() {
        return this;
    }
    bool isIntType() const override{
        return true;
    }
    bool isFloatType() const override {
        return false;
    }
    bool isStringType() const override {
        return false;
    }
    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
};

#endif //COMPILERPRACTICE1_INTTYPE_H

