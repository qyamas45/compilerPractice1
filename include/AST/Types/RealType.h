//
// Created by alyam on 1/21/2026.
//

#ifndef COMPILERPRACTICE1_REALTYPE_H
#define COMPILERPRACTICE1_REALTYPE_H
#include "Type.h"


class RealType : public Type {
public:
    std::string toString() {
        return "real";
    }
    RealType* asRealType() {
        return this;
    }
    bool isRealType() {
        return true;
    }
};


#endif //COMPILERPRACTICE1_REALTYPE_H