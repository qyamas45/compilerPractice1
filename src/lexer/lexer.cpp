#include "../../include/lexer/lexer.h"
void lexer::consume() {
    pos++;
    //if pos is greater/equal to length, end
    if (pos >=  static_cast<int>(input.length())) {
        ch = EOF;
    }
    else
        ch = input[pos];
}

bool lexer::isEOF() const {
    return pos >=  static_cast<int>(input.length());
}
bool lexer::isDigit() const {
    return ch >= '0' && ch <= '9';
}
bool lexer::isLetter() const {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
bool lexer::isAlpha() const {
    return isLetter() || isDigit() || ch == '_';
}
Token lexer::nextToken() {
    if (pos >= static_cast<int>(input.size())) {
        return Token(tokenType::ENDOFFILE, "EOF", loc.copy());
    }
    while (true) {
        switch (ch) {
            case ' ':
            case '\t':
            case '\r':
                while (ch == ' ' || ch == '\t' || ch == '\r') {
                    loc.columns(1);
                    loc.step();
                    consume();
                }
                break;
            case '\n':
                loc.lines(1);
                loc.step();
                consume();
                const bool addSemi = this->addSemicolon;
                this->addSemicolon = false;
                if (addSemi) {
                    return Token(tokenType::SEMI, ";", loc.copy());
                }
        }
    }

}


