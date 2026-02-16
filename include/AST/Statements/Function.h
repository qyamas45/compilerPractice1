//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_FUNCTION_H
#define COMPILERPRACTICE1_FUNCTION_H
#include "Statement.h"
#include "Parameters.h"
#include "ReturnType.h"

#include <memory>

//def <name> <type> () { ... }
class Function : public Statement{
public:
    std::unique_ptr<Name> name;
    std::unique_ptr<ReturnType> returnType;
    std::unique_ptr<Parameters> params;
    std::vector<std::unique_ptr<Statement>> statements;

};


#endif //COMPILERPRACTICE1_FUNCTION_H