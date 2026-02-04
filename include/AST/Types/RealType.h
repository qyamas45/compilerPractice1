//
// Created by alyam on 1/21/2026.
//

#ifndef COMPILERPRACTICE1_REALTYPE_H
#define COMPILERPRACTICE1_REALTYPE_H
#include "Type.h"


class RealType : public Type {
public:
    std::string toString()const override {
        return "real";
    }
    RealType* asRealType() {
        return this;
    }
    bool isRealType() {
        return true;
    }
    bool isIntType() const override{
        return false;
    }
    bool isFloatType() const override {
        return true;
    }
    bool isStringType() const override {
        return false;
    }
    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_REALTYPE_H