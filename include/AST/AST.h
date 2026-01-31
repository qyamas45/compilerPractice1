//
// Created by alyam on 1/5/2026.
//

#ifndef COMPILERPRACTICE1_AST_H
#define COMPILERPRACTICE1_AST_H
#include "lexer/token.h"
#include <memory>
#include <vector>

#include <string>


class AST {
public:
    AST() = default;
    virtual ~AST() = default;
    int line{};
    int charBegin{};
    int nchildren = 0;

    std::vector<std::shared_ptr<AST>> children;
    //int IntType;

    AST(int pLine, int pCharBegin);
    AST(Token t);

    AST(AST &n);

    //AST(AST& n);
    std::string toString();
    void tab(std::ostream& os, int amount);
    std::string intToString(int i, int w);
    void print(std::ostream& os, int depth);

    virtual void addChild(std::unique_ptr<AST> child);

};
#endif //COMPILERPRACTICE1_AST_H