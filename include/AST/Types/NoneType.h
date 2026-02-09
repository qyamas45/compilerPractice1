//
// Created by alyam on 2/9/2026.
//

#ifndef COMPILERPRACTICE1_NONETYPE_H
#define COMPILERPRACTICE1_NONETYPE_H
#include "Type.h"


class NoneType : public Type {
public:
    std::string toString() const override {
        return "None";
    }
    NoneType* asNoneType() {
        return this;
    }
    bool isIntType()const override {
        return false;
    }
    bool isFloatType()const override {
        return false;
    }
    bool isStringType() const override {
        return false;
    }
    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_NONETYPE_H