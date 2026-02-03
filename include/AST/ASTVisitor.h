//
// Created by alyam on 2/2/2026.
//

#ifndef COMPILERPRACTICE1_ASTVISITOR_H
#define COMPILERPRACTICE1_ASTVISITOR_H


class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visit(class Program&) = 0;
    virtual void visit(class Statement&) = 0;
    virtual void visit(class Name&) = 0;
    virtual void visit(class Expressions&) = 0;
    virtual void visit(class IfStatement&) = 0;


};


#endif //COMPILERPRACTICE1_ASTVISITOR_H