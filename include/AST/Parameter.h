//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_PARAMETERS_H
#define COMPILERPRACTICE1_PARAMETERS_H
#include <memory>
#include "AST.h"
#include "Expressions/Name.h"
#include "Types/Type.h"

class Parameter : public AST {
public:
    Parameter() {
        this->name = nullptr;
        this->type = nullptr;
    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Name> name;
    std::unique_ptr<Type> type;
};


#endif //COMPILERPRACTICE1_PARAMETERS_H