//
// Created by alyam on 2/2/2026.
//
#ifndef COMPILERPRACTICE1_ASTVISITOR_H
#define COMPILERPRACTICE1_ASTVISITOR_H
class Program;
class Statement;
class Expressions;
class IfStatement;
class Assignment;
class Type;
class NoneLiteral;
class IntLiteral;
class RealLiteral;
class Group;
class NotOperator;
class UnaryOperator;
class Name;
class Var;
class StringLiteral;
class BoolLiteral;
class Print;
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visit(class Program&) = 0;
    virtual void visit(class Statement&) = 0;
    virtual void visit(class Name&) = 0;
    virtual void visit(class Expressions&) = 0;
    virtual void visit(class IfStatement&) = 0;
    virtual void visit(class Print&) = 0;
    virtual void visit(class Assignment&) = 0;
    virtual void visit(class Type&) = 0;
    virtual void visit(class NoneLiteral&) = 0;
    virtual void visit(class IntLiteral&) = 0;
    virtual void visit(class RealLiteral&) = 0;
    virtual void visit(class StringLiteral&) = 0;
    virtual void visit(class BoolLiteral&) = 0;
    virtual void visit(class Group&) = 0;
    virtual void visit(class NotOperator&)=0;
    virtual void visit(class UnaryOperator&) = 0;
    virtual void visit(class Var&) = 0;

};


#endif //COMPILERPRACTICE1_ASTVISITOR_H