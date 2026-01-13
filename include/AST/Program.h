//
// Created by alyam on 1/6/2026.
//

#ifndef COMPILERPRACTICE1_PROGRAM_H
#define COMPILERPRACTICE1_PROGRAM_H
#include <memory>
#include <vector>

#include "AST.h"
#include "Statements/Statement.h"


class Program :public AST {
public:
    std::vector<std::unique_ptr<Statement>> statements;

    explicit Program(std::vector<std::unique_ptr<Statement>> statements) : statements(std::move(statements)) {}
};


#endif //COMPILERPRACTICE1_PROGRAM_H