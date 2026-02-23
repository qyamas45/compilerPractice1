#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "../include/lexer/lexer.h"
#include "../include/lexer/token.h"
#include "../include/parser/parser.h"
#include "../include/AST/PrintVisitor.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
int main()
{
    std::string testDir = "testcases";
    bool allPassed = true;

    if (!std::filesystem::exists(testDir)) {
        std::cerr << "Test directory not found: " << testDir << std::endl;
        return 1;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(testDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".lang") {
            std::cout << "Testing: " << entry.path().string() << std::endl;
            
            std::ifstream file(entry.path());
            std::stringstream buffer;
            buffer << file.rdbuf();
            std::string fileContent = buffer.str();
            
            lexer* lex = new lexer(fileContent);
            auto* parser = new Parser(lex);
            
            try {
                auto ast = parser->parseProgram();
                if (ast) {
                    std::cout << GREEN << "  -> PASSED" << RESET << std::endl;
                } else {
                    std::cout << RED << "  -> FAILED (No AST returned)" << RESET << std::endl;
                    allPassed = false;
                }
            } catch (const std::exception& e) {
                std::cout << RED << "  -> FAILED (" << e.what() << ")" << RESET << std::endl;
                allPassed = false;
            } catch (...) {
                std::cout << RED << "  -> FAILED (Unknown error)" << RESET << std::endl;
                allPassed = false;
            }
            
            delete parser;
            delete lex;
        }
    }

    if (allPassed) {
        std::cout << "\nAll tests passed successfully!" << std::endl;
    } else {
        std::cout << "\nSome tests failed." << std::endl;
    }
    
    return allPassed ? 0 : 1;
}