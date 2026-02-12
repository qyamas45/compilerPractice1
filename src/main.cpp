#include <iostream>
#include "../include/lexer/lexer.h"
#include "../include/lexer/token.h"
#include "../include/parser/parser.h"
#include "../include/AST/PrintVisitor.h"
int main()
{
 
	std::string test =
						"var test1 real = 3.5\n"
						"var test2 int = 2\n"
						"var test3 none = None\n"
						"var test4 string = \"test\"\n"
						"var test5 bool = false\n"
						"var test6 bool = true\n"
						"print \"test\"";

	lexer* lex = new lexer(test);
	Token token{};
	//do {
	//	token = lex->nextToken();
	//	std::cout << token.toString() << std::endl;
	//}while (token.type != tokenType::ENDOFFILE);

	auto* parser = new Parser(lex);
	//parser->parseProgram();

	PrintVisitor printer;

	auto ast = parser->parseProgram();

	ast->accept(printer);
	std::cout << "Hello world" << std::endl;
    return 0;
}