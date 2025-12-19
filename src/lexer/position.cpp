//
// Created by alyam on 12/14/2025.
//

#include "../../include/lexer/position.h"

position::position(const int line, const int column) {
    this->column = column;
    this->line = line;
}

position position::addWidth(const int width) const {
    position t = position(line, column);
    t.columns(width);
    return t;
}
void position::lines(const int count) {
    if(count > 0) {
        column = 1;
        line = add(line, count);
    }
}

void position::columns(const int count) {
    column = add(column, count);
}

int position::add(const int lhs, const int rhs) {
    return std::max(lhs+rhs, 1);
}

std::string position::toString() const {
    return std::to_string(line) + "." + std::to_string(column);
}
bool position::operator==(const position& other) const {
    return this->line == other.line && this->column == other.column;
}
bool position::operator!=(const position& other) const {
    return this->line != other.line || this->column != other.column;
}
bool position::isBefore(const position& other) const {
    if (this->line == other.line) {
        return this->column < other.column;
    }
    return this->line < other.line;
}
bool position::isAfter(const position& other) const {
    if (this->line == other.line) {
        return this->column > other.column;
    }
    return this->line > other.line;
}
bool position::isBeforeEqual(const position& other) const {
    return isBefore(other) || operator==(other);
}
bool position::isAfterEqual(const position& other) const {
    return isAfter(other) || operator==(other);
}
