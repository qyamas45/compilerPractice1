//
// Created by alyam on 2/12/2026.
//

#ifndef COMPILERPRACTICE1_PRINT_H
#define COMPILERPRACTICE1_PRINT_H
#include "Statement.h"
#include "../Expressions/Expressions.h"


class Print : public Statement {
public:
        std::unique_ptr<Expressions> expressions;
        Print(std::unique_ptr<Expressions> expressions) {
                this->expressions = std::move(expressions);
                if (expressions != nullptr) {
                       Statement::addChild(std::move(expressions));
                }
        }
        void accept(ASTVisitor &v) override {
            v.visit(*this);
        }
};


#endif //COMPILERPRACTICE1_PRINT_H