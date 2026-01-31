//
// Created by alyam on 1/31/2026.
//

#ifndef COMPILERPRACTICE1_RETURN_H
#define COMPILERPRACTICE1_RETURN_H
#include "Statement.h"
#include "../Expressions/Expressions.h"

class Return : public Statement {
public:
    Return() {
        expr = nullptr;
    }



    Return (std::unique_ptr<Expressions>exp) {
        this->expr = std::move(exp);
        // when expression isn't null
        if (this->expr!=nullptr)
            addChild(std::move(exp));
    }

    std::unique_ptr<Expressions> expr;
};


#endif //COMPILERPRACTICE1_RETURN_H