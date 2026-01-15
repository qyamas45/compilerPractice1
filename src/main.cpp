#include <iostream>
#include "../include/lexer/lexer.h"
#include "../include/lexer/token.h"
#include "../include/parser/parser.h"

int main()
{
 
	std::string test = """"
						"print \"hello world!\""
						"var invalid = 3.4"
						"x + 3"
					  """";
	lexer* lex = new lexer(test);

	Token token{};
	do {
		token = lex->nextToken();

		std::cout << token.toString() << std::endl;
	}while (token.type != tokenType::ENDOFFILE);
	auto* parser = new Parser(lex);
	parser->parseProgram();

	std::cout << "Hello world" << std::endl;
    return 0;
}