//
// Created by alyam on 1/5/2026.
//

#ifndef COMPILERPRACTICE1_STATEMENT_H
#define COMPILERPRACTICE1_STATEMENT_H
#include "../AST.h"

class Statement : public AST {
public:
    virtual ~Statement() = default;
    Statement() = default;
    Statement(Token t);
    Statement(AST a);
    Statement(const Statement& statement);

};


#endif //COMPILERPRACTICE1_STATEMENT_H