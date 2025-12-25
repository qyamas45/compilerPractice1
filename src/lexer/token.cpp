
#include "../../include/lexer/token.h"
Token::Token(const tokenType type, std::string lexeme, const location loc)
    : type(type), lexeme(std::move(lexeme)), loc(loc) {}

Token::Token() : type() {
};

std::string Token::toString() const {
    std::string str = lexeme;

    // Escape newline and carriage return
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '\n') {
            str.replace(i, 1, "\\n");
            ++i;
        } else if (str[i] == '\r') {
            str.replace(i, 1, "\\r");
            ++i;
        }
    }

    return "['" + str + "'," +
           tokenTypeToString(type)+ "," +
           loc.toString() + "]";
}
