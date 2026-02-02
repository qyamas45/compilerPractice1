//
// Created by alyam on 1/16/2026.
//

#ifndef COMPILERPRACTICE1_BINARYOPERATOR_H
#define COMPILERPRACTICE1_BINARYOPERATOR_H

#include <string>
#include <utility>
#include "Expressions.h"
class BinaryOperator : public Expressions{
public:
    std::string op;

    BinaryOperator(std::unique_ptr<Expressions> left,
        std::unique_ptr<Expressions> right
        , std::string op) {
        this->left = std::move(left);
        this->right = std::move(right);
        this->operation = std::move(op);

        AST::addChild(std::move(left));
        AST::addChild(std::move(right));
    }
private:
    std::unique_ptr<Expressions> left;
    std::unique_ptr<Expressions> right;
    std::string operation;





};


#endif //COMPILERPRACTICE1_BINARYOPERATOR_H