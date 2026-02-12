//
// Created by alyam on 2/2/2026.
//

#ifndef COMPILERPRACTICE1_PRINTVISITOR_H
#define COMPILERPRACTICE1_PRINTVISITOR_H
#include "ASTVisitor.h"



class PrintVisitor : public ASTVisitor{
public:
    void visit(Program& program) override;
    void visit(Statement& statement) override;
    void visit(Assignment& assignment) override;
    void visit(Name& name) override;
    void visit(Expressions& expressions) override;
    void visit(IfStatement& ifStatement) override;
    void visit(Print& print) override;
    void visit(Type& Type) override;
    void visit(NoneLiteral&) override;
    void visit(IntLiteral& l) override;
    void visit(StringLiteral& s) override;
    void visit(RealLiteral& r)override;
    void visit(BoolLiteral& l) override;
    void visit(Group&) override;
    void visit(NotOperator&) override;
    void visit(UnaryOperator&) override;
    void visit(Var& var) override;
};


#endif //COMPILERPRACTICE1_PRINTVISITOR_H