//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_TOKENTYPE_H
#define COMPILERPRACTICE1_TOKENTYPE_H
#include <string>


enum class tokenType {
        ENDOFFILE,
        INVALID,

        //KEYWORDS
        IMPORT,
        FROM,
        IN,
        DEF,
        IF,
        ELIF,
        ELSE,
        WHILE,
        FOR,
        TRY,
        EXCEPT,
        FINALLY,
        PASS,
        TRUE,
        FALSE,
        PRINT,
        INPUT,
        BREAK,
        RETURN,
        CLASS,
        VAR,
        INT,
        REAL,
        BOOL,
        STRING,
        NONE,
        FLOAT,
        INDENT,
        //LITERAL (TYPE)
        INT_LITERAL,
        REAL_LITERAL,
        FLOAT_LITERAL,
        STRING_LITERAL,
        COMMENT,

        //MATH OPERATIONS
        PLUS,
        MINUS,
        MUL,
        DIV,
        MOD,
        BIT_AND,
        BIT_OR,
        XOR,
        POWER,
        //OPERATORS
        ASSIGN,
        PLUS_EQUAL,
        MINUS_EQUAL,
        MUL_EQUAL,
        DIV_EQUAL,
        MOD_EQUAL,
        POWER_EQUAL,

        //SEMANTICS
        PARENL,
        PARENR,
        CURLYL,
        CURLYR,
        BRACKL,
        BRACKR,

        //SYNTAX
        COLON,
        SEMI,
        COMMA,
        DOT,
        //LOGICAL OPERATORS
        EQUAL,
        NOT_EQUAL,
        LT,
        LE,
        GT,
        GE,
        SHIFT_RIGHT,
        SHIFT_LEFT,
        AND,
        OR,

        NEG,
        IS,
        NOT,
        AT
    };
std::string tokenTypeToString(tokenType type);
#endif //COMPILERPRACTICE1_TOKENTYPE_H