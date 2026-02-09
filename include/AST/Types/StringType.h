//
// Created by alyam on 2/8/2026.
//

#ifndef COMPILERPRACTICE1_STRINGTYPE_H
#define COMPILERPRACTICE1_STRINGTYPE_H
#include "Type.h"


class StringType : public Type{
public:
    std::string toString() const override {
        return "string";
    }
    StringType* asStringType() {
        return this;
    }
    bool isIntType()const override {
        return false;
    }
    bool isFloatType()const override {
        return false;
    }
    bool isStringType() const override {
        return true;
    }
    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_STRINGTYPE_H