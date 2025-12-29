//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_POSITION_H
#define COMPILERPRACTICE1_POSITION_H


#include <string>

class position {
public:
    int line;
    int column;

    position(int line, int column);
    position addWidth(int width) const;
    void lines(int count);
    void columns(int count);

    static int add(int lhs,  int rhs);

    std::string toString() const;

    bool operator==(const position& other) const;
    bool operator!=(const position& other) const;
    bool isBefore(const position& other) const;
    bool isBeforeEqual(const position& other) const;
    bool isAfter(const position& other) const;
    bool isAfterEqual(const position& other) const;


};


#endif //COMPILERPRACTICE1_POSITION_H