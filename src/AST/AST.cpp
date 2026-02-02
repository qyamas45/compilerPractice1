#include "../include/AST/AST.h"



AST::AST(int pline, int pCharBegin) {

}

AST::AST(Token t) {

}

AST::AST(AST &n) {
}

std::string AST::toString() const {
    return "AST";
}

void AST::tab(std::ostream& os, int amount) {

}

std::string AST::intToString(int i, int w) {

}
void AST::print(std::ostream& os, int depth) const {
    std::cout << children.size() << std::endl;
    os << toString() << std::endl;
    for (const auto& c: children) {

        if (c)
            c->print(os, depth+1);
        else {
            assert(c && "AST child must not be null");
        }

    }
}
void AST::addChild(std::unique_ptr<AST> child) {

    if (!child)
        return;
    children.push_back(std::move(child));
    ++nchildren;
}