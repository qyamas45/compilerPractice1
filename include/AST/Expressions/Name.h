//
// Created by alyam on 1/15/2026.
//

#ifndef COMPILERPRACTICE1_NAME_H
#define COMPILERPRACTICE1_NAME_H
#include <memory>
#include <string>
#include "Expressions.h"

class Name : public Expressions{
public:

    explicit Name(const std::string &identifier): identifier(identifier){}
    std::string toString();
    static bool isName();
    static bool asName();

    std::string identifier;

};


#endif //COMPILERPRACTICE1_NAME_H