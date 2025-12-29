//
// Created by alyam on 12/14/2025.
//
#include "../../include/lexer/location.h"
#include <iostream>
location::location() : begin(1,1), end(1,1) {}
location::location(int line, int column) : begin(line,column), end(line,column) {}
location::location(position a, position b) : begin(a), end(b){};
void location::step() {
    begin = end;
}
void location::columns(int count) {
    end = end.addWidth(count);
}
void location::lines(int count) {
    end.lines(count);
}

location location::addLocation(const location& loc) {
    location result;
    //when location is before
    if(loc.begin.line < begin.line || (loc.begin.line == begin.line && loc.begin.column < begin.column)) {
        result.begin = loc.begin;
    }
    else
        result.begin = begin;
    //when location is after
    if(loc.end.line > end.line || (loc.end.line == end.line && loc.end.column > end.column)) {
        result.end = loc.end;
    }
    else
        result.end = end;

    return result;

}
location location::addWith(int width) {
    location result(begin, end);
    result.columns(width);
    return result;
}
location location::subWidth(int width) {
    return addWith(-width);
}
location location::copy() {
    position newBegin = position(begin.line, begin.column);
    position newEnd =  position(end.line, end.column);
    return location(newBegin, newEnd);
}
std::string location::toString() const{
    int endColumn;
    if (end.column > 0)
        endColumn = end.column - 1;
    else
        endColumn = 0;
    std::string str = begin.toString();
    //std::cout << std::to_string(begin.line) << " " << std::to_string(end.line) << std::endl;
    //std::cout << endColumn << std::endl;
    if(begin.line < end.line) {
        str += "-" + std::to_string(end.line)  + "." + std::to_string(endColumn);
    }
    if(begin.column  < endColumn) {

        str += "-" + std::to_string(endColumn);
    }
    return str;
}