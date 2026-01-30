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

    static std::string toString()  {
        return "None";
    }
    NoneLiteral()= default;
    NoneLiteral(const NoneLiteral&) = delete;
    NoneLiteral& operator=(const NoneLiteral&) = delete;
};


#endif //COMPILERPRACTICE1_NONELITERAL_H