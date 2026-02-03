//
// Created by alyam on 1/5/2026.
//

#ifndef COMPILERPRACTICE1_AST_H
#define COMPILERPRACTICE1_AST_H
#include "lexer/token.h"
#include <memory>
#include <vector>
#include <cassert>
#include <string>
#include <iostream>

#include "ASTVisitor.h"

class AST {
public:
    AST() = default;
    virtual ~AST() = default;
    virtual void accept(ASTVisitor& v)= 0;
    int line{};
    int charBegin{};
    int nchildren = 0;

    std::vector<std::shared_ptr<AST>> children;
    //int IntType;

    AST(int pLine, int pCharBegin);
    AST(Token t);

    AST(AST &n);

    //AST(AST& n);
    [[nodiscard]] virtual std::string toString() const;
    void tab(std::ostream& os, int amount);
    std::string intToString(int i, int w);
    void print(std::ostream& os, int depth) const;

    virtual void addChild(std::unique_ptr<AST> child);

};
#endif //COMPILERPRACTICE1_AST_H