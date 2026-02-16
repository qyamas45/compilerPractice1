//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_PARAMETERS_H
#define COMPILERPRACTICE1_PARAMETERS_H
#include <memory>

#include "Expressions/Name.h"
#include "Types/Type.h"

class Parameter : public AST {
public:

    std::unique_ptr<Name> name;
    std::unique_ptr<Type> type;
};


#endif //COMPILERPRACTICE1_PARAMETERS_H