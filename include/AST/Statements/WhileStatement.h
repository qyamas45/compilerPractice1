//
// Created by alyam on 1/24/2026.
//

#ifndef COMPILERPRACTICE1_WHILESTATEMENT_H
#define COMPILERPRACTICE1_WHILESTATEMENT_H
#include "Statement.h"
#include "../Expressions/Expressions.h"
#include <memory>
#include <vector>

class WhileStatement : public Statement  {
public:
    std::unique_ptr<Expressions> condition;
    std::vector<std::unique_ptr<Statement>> body;
    WhileStatement() {
        this->condition = std::make_unique<Expressions>();
    }
    WhileStatement(std::unique_ptr<Expressions> expr,
        std::vector<std::unique_ptr<Statement>> body) {
        this->condition = std::move(expr);
        this->body = std::move(body);

    }

};


#endif //COMPILERPRACTICE1_WHILESTATEMENT_H