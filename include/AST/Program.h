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

    Program(std::vector<std::unique_ptr<Statement>> statements) {
        std::cout << "Program created" << std::endl;
        std::cout << "In program class: " << statements.size() << std::endl;
       for (auto& stmt : statements) {
           addChild(std::move(stmt));
       }
    }
    std::string toString() const override{
        return "Program";
    }


};


#endif //COMPILERPRACTICE1_PROGRAM_H