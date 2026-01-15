//
// Created by alyam on 1/15/2026.
//

#include "../../../include/AST/Expressions/Name.h"

std::string Name::toString() {
    return identifier;
}
bool Name::isName() {
    return true;
}
bool Name::asName() {
    return true;
}
