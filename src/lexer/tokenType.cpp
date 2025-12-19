//
// Created by alyam on 12/14/2025.
//
#include "../../include/lexer/token.h"

std::string tokenTypeToString(const tokenType type) {
    switch (type) {
        case tokenType::IMPORT: return "Import";
        case tokenType::IN: return "In";
        case tokenType::DEF: return "Def";
        case tokenType::IF: return "If";
        case tokenType::ELIF: return "Elif";
        case tokenType::ELSE: return "Else";
        case tokenType::WHILE: return "While";
        case tokenType::FOR: return "For";
        case tokenType::TRY: return "Try";
        case tokenType::EXCEPT: return "Except";
        case tokenType::FINALLY: return "Finally";
        case tokenType::PASS: return "Pass";
        case tokenType::TRUE: return "True";
        case tokenType::FALSE: return "False";
        case tokenType::PRINT: return "Print";
        case tokenType::INPUT: return "Input";
        case tokenType::BREAK: return "Break";
        case tokenType::RETURN: return "Return";
        case tokenType::CLASS: return "Class";
        case tokenType::VAR: return "Var";
        case tokenType::INT: return "Int";
        case tokenType::REAL: return "Real";
        case tokenType::BOOL: return "Bool";
        case tokenType::STRING: return "String";
        case tokenType::NONE: return "None";
        case tokenType::FLOAT: return "Float";
        case tokenType::INDENT: return "Indent";
        case tokenType::INT_LITERAL: return "IntLiteral";
        case tokenType::REAL_LITERAL: return "Realliteral";
        case tokenType::FLOAT_LITERAL: return "Floatliteral";
        case tokenType::STRING_LITERAL: return "Stringliteral";
        case tokenType::COMMENT: return "Comment";
        case tokenType::PLUS: return "Plus";
        case tokenType::MINUS: return "Minus";
        case tokenType::MUL: return "Mul";
        case tokenType::DIV: return "Div";
        case tokenType::MOD: return "Mod";
        case tokenType::BIT_OR: return "Bitor";
        case tokenType::BIT_AND: return "Bitand";
        case tokenType::XOR: return "Xor";
        case tokenType::POWER: return "Power";
        case tokenType::ASSIGN: return "Assign";
        case tokenType::PLUS_EQUAL: return "Plusequal";
        case tokenType::MINUS_EQUAL: return "Minusequal";
        case tokenType::MUL_EQUAL: return "Mulequal";
        case tokenType::DIV_EQUAL: return "Divequal";
        case tokenType::MOD_EQUAL: return "Modequal";
        case tokenType::POWER_EQUAL: return "Powerequal";

        case tokenType::PARENL: return "Parenl";
        case tokenType::PARENR: return "Parenr";
        case tokenType::CURLYL: return "Curlyl";
        case tokenType::CURLYR: return "Curlyr";
        case tokenType::BRACKL: return "Brackl";
        case tokenType::BRACKR: return "Brackr";

        case tokenType::COLON: return "Colon";
        case tokenType::SEMI: return "Semi";
        case tokenType::COMMA: return "Comma";
        case tokenType::DOT: return "Dot";

        case tokenType::EQUAL: return "Equal";
        case tokenType::NOT_EQUAL: return "Notequal";
        case tokenType::LT: return "Lt";
        case tokenType::LE: return "Le";
        case tokenType::GT: return "Gt";

        case tokenType::GE: return "Ge";
        case tokenType::SHIFT_RIGHT: return "Shiftright";
        case tokenType::SHIFT_LEFT: return "Shiftleft";
        case tokenType::AND: return "And";
        case tokenType::OR: return "Or";

        case tokenType::NEG: return "Neg";
        case tokenType::IS: return "Is";
        case tokenType::NOT: return "Not";
        case tokenType::AT: return "At";

    }
    return "unknown tokenType";
}