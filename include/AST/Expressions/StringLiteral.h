//
// Created by alyam on 2/8/2026.
//

#ifndef COMPILERPRACTICE1_STRINGLITERAL_H
#define COMPILERPRACTICE1_STRINGLITERAL_H
#include "Literal.h"
#include <string>
#include <utility>

class StringLiteral : public Literal {
public:
    std::string value;
    StringLiteral(std::string  word) : value(word) {
    };
    void accept(ASTVisitor &v) override {
        v.visit(*this);
    }
};


#endif //COMPILERPRACTICE1_STRINGLITERAL_H