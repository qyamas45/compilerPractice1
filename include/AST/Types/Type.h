//
// Created by alyam on 12/12/2025.
//

#ifndef COMPILERPRACTICE1_TYPES_H
#define COMPILERPRACTICE1_TYPES_H

#include "../AST.h"

class Type : public AST{
public:
	virtual ~Type() {};
	virtual bool isIntType() const = 0;
	virtual bool isFloatType() const = 0;
	virtual bool isStringType() const = 0;
	void accept(ASTVisitor& v) override {
		v.visit(*this);
	}


	//function types

};


#endif //COMPILERPRACTICE1_TYPES_H