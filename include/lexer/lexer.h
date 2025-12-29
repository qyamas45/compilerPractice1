//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_LEXER_H
#define COMPILERPRACTICE1_LEXER_H
#include <string>

#include "location.h"
#include "token.h"

class lexer {
    public:

    std::string input;
    int pos;
    char ch;
    location loc;
    bool addSemicolon;

    lexer(const std::string &input) {
        this->input = input;
        this->addSemicolon = false;
        this->pos = 0;
        this->ch = input.empty() ? '\0' : input.at(0);
        this->loc = location();
    }

    void consume();
    bool isEOF() const;
    bool isDigit() const;
    bool isAlpha() const;
    bool isLetter() const;
    Token nextToken();
    Token comment();
    Token number();
    Token string();
    Token identifier();



};
#endif //COMPILERPRACTICE1_LEXER_H