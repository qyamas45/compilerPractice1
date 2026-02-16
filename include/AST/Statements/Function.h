//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_FUNCTION_H
#define COMPILERPRACTICE1_FUNCTION_H
#include "Statement.h"
#include "../Parameter.h"
#include "ReturnType.h"
#include "../Expressions/Name.h"
#include <memory>

//def <name> <type> () { ... }
class Function : public Statement{
public:
    Function(
        std::unique_ptr<Name> name,
        std::unique_ptr<Parameter> parameters,
        std::unique_ptr<ReturnType> returnType,
        std::vector<std::unique_ptr<Statement>> statements) {

        }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Name> name;
    std::unique_ptr<ReturnType> returnType;
    std::unique_ptr<Parameter> params;
    std::vector<std::unique_ptr<Statement>> statements;

};


#endif //COMPILERPRACTICE1_FUNCTION_H