#include <iostream>
#include "../include/lexer/lexer.h"
#include "../include/lexer/token.h"

int main()
{
	std::string test = "print \"hello world!\" ";
	lexer* lex = new lexer(test);
	Token token{};
	do {
		token = lex->nextToken();
		std::cout << token.toString() << std::endl;
	}while (token.type != tokenType::ENDOFFILE);


	std::cout << "Hello world" << std::endl;
    return 0;
}