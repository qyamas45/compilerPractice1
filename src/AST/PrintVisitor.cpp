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
void PrintVisitor::visit(Statement& statement) {
    std::cout << "Visited Statement!" << std::endl;
    std::cout << statement.children.size() << std::endl;
    for (auto& child: statement.children) {
        child->accept(*this);
    }
}
void PrintVisitor::visit(Assignment&) {
    std::cout << "Visited Assignment!" << std::endl;
}
void PrintVisitor::visit(Name&) {
    std::cout << "Visited Name!" << std::endl;
}
void PrintVisitor::visit(Expressions&) {
    std::cout << "Visited Expressions!" << std::endl;
}
void PrintVisitor::visit(IfStatement&) {
    std::cout << "Visited IfStatement!" << std::endl;
}
void PrintVisitor::visit(Type&) {
    std::cout << "Visited Type!" << std::endl;
}
void PrintVisitor::visit(NoneLiteral&) {
    std::cout << "Visited NoneLiteral!" << std::endl;
}
void PrintVisitor::visit(Group&) {
    std::cout << "Visited Group!" << std::endl;
}
void PrintVisitor::visit(NotOperator&) {
    std::cout << "Visited NotOperator!" << std::endl;
}
void PrintVisitor::visit(UnaryOperator&) {
    std::cout << "Visited UnaryOperator!" << std::endl;
}
void PrintVisitor::visit(Var&) {
    std::cout << "Visited Var!" << std::endl;
}
