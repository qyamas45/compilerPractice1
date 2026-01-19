//
// Created by alyam on 12/12/2025.
//

#ifndef COMPILERPRACTICE1_TYPES_H
#define COMPILERPRACTICE1_TYPES_H

#include "../AST.h"

class Type : public AST{
	public:
		virtual ~Type() {};
		virtual bool isIntType(){};
		virtual bool isFloatType(){};
		virtual bool isStringType(){};
	//function types

};


#endif //COMPILERPRACTICE1_TYPES_H