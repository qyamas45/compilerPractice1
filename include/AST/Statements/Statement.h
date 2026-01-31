//
// Created by alyam on 1/5/2026.
///*-41*5+
///6.02/

#ifndef COMPILERPRACTICE1_STATEMENT_H
#define COMPILERPRACTICE1_STATEMENT_H
#include "../AST.h"

class Statement : public AST {
public:
    virtual ~Statement() = default;

    void addChild(const std::unique_ptr<Expressions> exp);

    Statement() = default;
    Statement(Token t);
    Statement(AST a);
    Statement(const Statement& statement);

    void addChild(std::unique_ptr<AST> child) override {
        children.push_back(std::move(child));
        nchildren++;
    }
};

#endif //COMPILERPRACTICE1_STATEMENT_H
