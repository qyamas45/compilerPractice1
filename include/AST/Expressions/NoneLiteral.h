//
// Created by alyam on 1/29/2026.
//

#ifndef COMPILERPRACTICE1_NONELITERAL_H
#define COMPILERPRACTICE1_NONELITERAL_H
#include "Literal.h"


class NoneLiteral : public Literal {
public:
    static NoneLiteral& instance() {
        static NoneLiteral instance;
        return instance;
    }

    std::string toString()  {
        return "None";
    }

    void accept(ASTVisitor& v) override {
        v.visit(*this);
    }
    NoneLiteral()= default;
    NoneLiteral(const NoneLiteral&) = delete;
    NoneLiteral& operator=(const NoneLiteral&) = delete;
};


#endif //COMPILERPRACTICE1_NONELITERAL_H