//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_FUNCTION_H
#define COMPILERPRACTICE1_FUNCTION_H
#include "Statement.h"
#include "../Parameter.h"
#include "../Types/Type.h"
#include "../Expressions/Name.h"
#include <memory>

//def <name> <type> () { ... }
class Function : public Statement{
public:
    Function() {
        this->returnType = nullptr;
        this->name = nullptr;
    }
    Function(
        std::unique_ptr<Name> name,
        std::vector<std::unique_ptr<Parameter>> parameters,
        std::unique_ptr<Type> returnType,
        std::vector<std::unique_ptr<Statement>> statements) {

        this->name = std::move(name);
        this->params = std::move(parameters);
        this->returnType = std::move(returnType);
        this->statements = std::move(statements);

        Statement::addChild(std::move(name));

        Statement::addChild(std::move(returnType));

        for (auto& param: parameters) {
            Statement::addChild(std::move(param));
        }
        for (auto& statement: statements) {
            Statement::addChild(std::move(statement));
        }
    }
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
    std::unique_ptr<Name> name;
    std::unique_ptr<Type> returnType;
    std::vector<std::unique_ptr<Parameter>> params;
    std::vector<std::unique_ptr<Statement>> statements;

};


#endif //COMPILERPRACTICE1_FUNCTION_H