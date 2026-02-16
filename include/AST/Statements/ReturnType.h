//
// Created by alyam on 2/15/2026.
//

#ifndef COMPILERPRACTICE1_RETURNTYPE_H
#define COMPILERPRACTICE1_RETURNTYPE_H
#include <memory>
#include "Statement.h"
#include "../Types/Type.h"
#include "../Expressions/Name.h"


class ReturnType : public Statement {
public:
    std::unique_ptr<Name> name;
    std::unique_ptr<Type> type;
};


#endif //COMPILERPRACTICE1_RETURNTYPE_H