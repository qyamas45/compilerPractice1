//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_TOKEN_H
#define COMPILERPRACTICE1_TOKEN_H
#include <string>
#include "location.h"
#include "tokenType.h"

struct Token {
    tokenType type;
    std::string lexeme;
    location loc;

    Token(tokenType type, std::string lexeme, location loc);

    Token();

    [[nodiscard]] std::string toString() const;


};
#endif //COMPILERPRACTICE1_TOKEN_H