//
// Created by alyam on 2/2/2026.
//

#ifndef COMPILERPRACTICE1_PRINTVISITOR_H
#define COMPILERPRACTICE1_PRINTVISITOR_H
#include "ASTVisitor.h"
#include <iostream>

class PrintVisitor : public ASTVisitor{
public:
    void visit(Program& program) override;
};


#endif //COMPILERPRACTICE1_PRINTVISITOR_H