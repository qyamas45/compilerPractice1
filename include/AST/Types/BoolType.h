//
// Created by alyam on 2/11/2026.
//

#ifndef COMPILERPRACTICE1_BOOLTYPE_H
#define COMPILERPRACTICE1_BOOLTYPE_H
#include "Type.h"


class BoolType : public Type {
public:
    std::string toString() const override {
        return "bool";
    }
    BoolType* asIntType() {
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


#endif //COMPILERPRACTICE1_BOOLTYPE_H