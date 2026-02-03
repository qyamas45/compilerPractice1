#include <iostream>
#include "../include/lexer/lexer.h"
#include "../include/lexer/token.h"
#include "../include/parser/parser.h"
#include "../include/AST/PrintVisitor.h"
int main()
{
 
	std::string test = """"
						"var test int = 3.4"
					  """";
	lexer* lex = new lexer(test);
	Token token{};
	//do {
		//token = lex->nextToken();

		//std::cout << token.toString() << std::endl;
	//}while (token.type != tokenType::ENDOFFILE);
	auto* parser = new Parser(lex);
	//parser->parseProgram();
	PrintVisitor printer;
	auto ast = parser->parseProgram();
	ast->accept(printer);
	std::cout << "Hello world" << std::endl;
    return 0;
}