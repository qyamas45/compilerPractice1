//
// Created by alyam on 2/2/2026.
//

#include "../../include/AST/PrintVisitor.h"
#include "../../include/AST/Program.h"
#include "../../include/AST/Statements/Var.h"
#include "../../include/AST/Expressions/StringLiteral.h"
#include "../../include/AST/Expressions/BoolLiteral.h"
#include "../../include/AST/Expressions/IntLiteral.h"
#include "../../include/AST/Expressions/RealLiteral.h"

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
void PrintVisitor::visit(Type& Type) {
    std::cout << "Visited Type!" << std::endl;
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
void PrintVisitor::visit(IntLiteral& l) {
    std::cout << "Visited IntLiteral!" << std::endl;
    std::cout << "Value: " << l.value << std::endl << std::endl;
}
void PrintVisitor::visit(RealLiteral& r) {
    std::cout << "Visited RealLiteral!" << std::endl;
    std::cout << "Value: " << r.value << std::endl << std::endl;
}
void PrintVisitor::visit(StringLiteral& s) {
    std::cout << "Visited StringLiteral!" << std::endl;
    std::cout << "Value: " << s.value << std::endl << std::endl;
}
void PrintVisitor::visit(NoneLiteral&) {
    std::cout << "Visited NoneLiteral!" << std::endl << std::endl;
}
void PrintVisitor::visit(BoolLiteral& l) {
    std::cout << "Visited BoolLiteral!" << std::endl;
    std::cout << "Value: " << l.value << std::endl << std::endl;
}
void PrintVisitor::visit(Var& var) {
    std::cout << "Visited Var!" << std::endl;
    std::cout << "Type: " << var.type->toString() << std::endl;
    std::cout << "Name: " << var.name->toString() << std::endl;
    if (var.value != nullptr)
        var.value->accept(*this);
}
