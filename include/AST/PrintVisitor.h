//
// Created by alyam on 2/2/2026.
//

#ifndef COMPILERPRACTICE1_PRINTVISITOR_H
#define COMPILERPRACTICE1_PRINTVISITOR_H
#include "ASTVisitor.h"
#include <iostream>

#include "Statements/Assignment.h"
#include "Expressions/Name.h"
#include "Statements/IfStatement.h"
#include "Expressions/Expressions.h"
class PrintVisitor : public ASTVisitor{
public:
    void visit(Program& program) override;
    void visit(Statement& statement) override;
    void visit(Assignment& assignment) override;
    void visit(Name& name) override;
    void visit(Expressions& expressions) override;
    void visit(IfStatement& ifStatement) override;
};


#endif //COMPILERPRACTICE1_PRINTVISITOR_H