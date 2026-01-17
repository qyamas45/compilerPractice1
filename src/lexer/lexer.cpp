#include "../../include/lexer/lexer.h"
#include <iostream>
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
Token lexer::string() {
    std::string lexeme;
    loc.step();
    while (ch != '"' && ch != '\0') {
        lexeme += ch;
        consume();
    }
    consume();
    loc.columns(lexeme.length());
    loc.columns(1);
    return Token(tokenType::STRING_LITERAL, lexeme, loc.copy());
}

Token lexer::comment() {
    std::string lexeme;
    loc.step();
    while (ch != '\n') {
        lexeme += ch;
        consume();
    }
    loc.columns(lexeme.length());
    return Token(tokenType::COMMENT, lexeme, loc.copy());
}
Token lexer::identifier() {
    std::string lexeme;
    loc.step();
    while (isAlpha()) {
        lexeme += ch;
        consume();
    }
    loc.columns(lexeme.length());
    addSemicolon = false;
    if (lexeme == "import")
        return Token(tokenType::IMPORT, "import", loc.copy());
    else if (lexeme == "from")
        return Token(tokenType::FROM, "from", loc.copy());
    else if (lexeme == "in")
        return Token(tokenType::IN, "in", loc.copy());
    else if (lexeme == "def")
        return Token(tokenType::DEF, "def", loc.copy());
    else if (lexeme == "if")
        return Token(tokenType::IF, "if", loc.copy());
    else if (lexeme == "elif")
        return Token(tokenType::ELIF, "elif", loc.copy());
    else if (lexeme == "else")
        return Token(tokenType::ELSE, "else", loc.copy());
    else if (lexeme == "while")
        return Token(tokenType::WHILE, "while", loc.copy());
    else if (lexeme == "for")
        return Token(tokenType::FOR, "for", loc.copy());
    else if (lexeme == "try")
        return Token(tokenType::TRY, "try", loc.copy());
    else if (lexeme == "except")
        return Token(tokenType::EXCEPT, "except", loc.copy());
    else if (lexeme == "finally")
        return Token(tokenType::FINALLY, "finally", loc.copy());
    else if (lexeme == "pass") {
        addSemicolon = true;
        return Token(tokenType::PASS, "pass", loc.copy());
    }   
    else if (lexeme == "true")
        return Token(tokenType::TRUE, "true", loc.copy());
    else if (lexeme == "false")
        return Token(tokenType::FALSE, "false", loc.copy());
    else if (lexeme == "print")
        return Token(tokenType::PRINT, "print", loc.copy());
    else if (lexeme == "input")
        return Token(tokenType::INPUT, "input", loc.copy());
    else if (lexeme == "break") {
        addSemicolon = true;
        return Token(tokenType::BREAK, "break", loc.copy());
    }
    else if (lexeme == "return") {
        addSemicolon = true;
        return Token(tokenType::RETURN, "return", loc.copy());
    }
    else if (lexeme == "class")
        return Token(tokenType::CLASS, "class", loc.copy());
    else if (lexeme == "var")
        return Token(tokenType::VAR, "var", loc.copy());
    else if (lexeme == "int")
        return Token(tokenType::INT, "int", loc.copy());
    else if (lexeme == "real")
        return Token(tokenType::REAL, "real", loc.copy());
    else if (lexeme == "bool")
        return Token(tokenType::BOOL, "bool", loc.copy());
    else if (lexeme == "string")
        return Token(tokenType::STRING, "string", loc.copy());
    else if (lexeme == "none")
        return Token(tokenType::NONE, "none", loc.copy());
    else if (lexeme == "float")
        return Token(tokenType::FLOAT, "float", loc.copy());
    else if (lexeme == "indent")
        return Token(tokenType::INDENT, "indent", loc.copy());
    else {
        addSemicolon = true;
        return Token(tokenType::INDENT, lexeme, loc.copy());
    }
}
Token lexer::number() {
    std::string lexeme;
    //grab the first number and continue
    lexeme += ch;
    consume();
    //if there is still continue number, consume
    while (isDigit()) {
        lexeme += ch;
        consume();
    }
    //decimal if ch encounters
    //ex: .4
    if (ch == '.') {
        addSemicolon = true;
        //4
        lexeme += ch;
        consume();

        //*blank*
        lexeme += ch;
        consume();
        //if there is a continue i.e. .3333
        //then while loop until it becomes /*blank*
        while (isDigit()) {
            lexeme += ch;
            consume();
        }
    }


    std::string lex = lexeme;
    loc.columns(lex.length());
    //if value is like 3.45, return real
    if (lex.find('.') != std::string::npos) {

        return Token(tokenType::REAL_LITERAL, lexeme, loc.copy());
    }
    return Token(tokenType::INT_LITERAL, lexeme, loc.copy());
}

Token lexer::nextToken() {
    //std::cout << this->ch << std::endl;
    //std::cout << "ch = " << static_cast<int>(ch) << std::endl;
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

            case '\n': {
                loc.lines(1);
                loc.step();
                consume();
                const bool addSemi = this->addSemicolon;
                this->addSemicolon = false;
                if (addSemi) {
                    return Token(tokenType::SEMI, ";", loc.copy());
                }
                break;
            }
            case '"':
                addSemicolon = true;
                consume();
                loc.columns(1);
                if (ch == '"') {
                    consume();
                    return Token(tokenType::STRING_LITERAL, "", loc.copy());
                }
                return string();

            case ':':
                addSemicolon = false;
                loc.lines(1);
                loc.step();
                return Token(tokenType::COLON, ":", loc.copy());


            case '=':
                addSemicolon = false;
                consume();
                loc.lines(1);
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::EQUAL, "==", loc.copy());
                }

                return Token(tokenType::ASSIGN, "=", loc.copy());\
            case '+':
                addSemicolon = false;
                consume();
                loc.lines(1);
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::PLUS_EQUAL, "+=", loc.copy());
                }
                return Token(tokenType::PLUS, "+", loc.copy());
            case '-':
                addSemicolon = false;
                consume();
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::MINUS_EQUAL, "-=", loc.copy());
                }
                return Token(tokenType::MINUS, "-", loc.copy());
            case '*':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '*') {
                    consume();
                    loc.columns(1);
                    if (ch == '=') {
                        consume();
                        loc.columns(1);
                        return Token(tokenType::POWER_EQUAL, "**=", loc.copy());
                    }
                    return Token(tokenType::POWER, "**", loc.copy());
                }
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::MUL_EQUAL, "*=", loc.copy());
                }
                return Token(tokenType::MUL, "*", loc.copy());
            case '/':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::DIV_EQUAL, "/=", loc.copy());
                }
                if (ch == '/') {
                    consume();
                    loc.columns(1);
                    return comment();
                }
                return Token(tokenType::DIV, "/", loc.copy());
            case '%':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::MOD_EQUAL, "%=", loc.copy());

                }
                return Token(tokenType::MOD, "%", loc.copy());
            case '&':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::BIT_AND, "&", loc.copy());
            case '|':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::BIT_OR, "|", loc.copy());
            case '^':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::XOR, "^", loc.copy());
            case ';':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::SEMI, ";", loc.copy());
            case '.':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::DOT, ".", loc.copy());
            case ',':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::COMMA, ",", loc.copy());

            case '!':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::NOT_EQUAL, "!=", loc.copy());
                }
            case '<':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '<') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::SHIFT_LEFT, "<<", loc.copy());
                }
                if (ch == '>') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::NOT_EQUAL, "<>", loc.copy());
                }
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::LE, "<=", loc.copy());
                }
                return Token(tokenType::LT, "<", loc.copy());
            case '>':
                addSemicolon = false;
                consume();
                loc.columns(1);
                if (ch == '>') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::SHIFT_RIGHT, ">>", loc.copy());
                }
                if (ch == '=') {
                    consume();
                    loc.columns(1);
                    return Token(tokenType::GE, ">=", loc.copy());
                }
                return Token(tokenType::GT, ">", loc.copy());
            case '@':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::AT, "@", loc.copy());
            case '~':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::NEG, "~", loc.copy());

            case '(':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::PARENL, "(", loc.copy());
            case ')':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::PARENR, ")", loc.copy());
            case '{':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::CURLYL, "{", loc.copy());
            case '}':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::CURLYR, "}", loc.copy());
            case '[':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::BRACKL, "[", loc.copy());
            case ']':
                addSemicolon = false;
                consume();
                loc.columns(1);
                return Token(tokenType::BRACKR, "]", loc.copy());
            case '#':
                consume();
                loc.columns(1);
                return comment();
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                addSemicolon = true;
                return number();
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '_':
                return identifier();


            default:
                addSemicolon = false;
                loc.columns(1);
                return Token(tokenType::INVALID, "invalid", loc.copy());

        }
    }

}


