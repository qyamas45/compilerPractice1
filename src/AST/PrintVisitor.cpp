//
// Created by alyam on 2/2/2026.
//

#include "../../include/AST/PrintVisitor.h"

#include "../../include/AST/Program.h"

void PrintVisitor::visit(Program &program) {
    std::cout << "Program Started!" << std::endl;
    for (auto& child: program.children) {
        child->accept(*this);
    }
}
void PrintVisitor::visit(Statement&) {}
void PrintVisitor::visit(Assignment&) {}
void PrintVisitor::visit(Name&) {}
void PrintVisitor::visit(Expressions&) {}
void PrintVisitor::visit(IfStatement&) {}
void PrintVisitor::visit(Type&) {}
void PrintVisitor::visit(NoneLiteral&){}
void PrintVisitor::visit(Group&){}
void PrintVisitor::visit(NotOperator&){}
void PrintVisitor::visit(UnaryOperator&){}