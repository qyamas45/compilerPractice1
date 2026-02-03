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
