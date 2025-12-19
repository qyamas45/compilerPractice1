//
// Created by alyam on 12/14/2025.
//

#ifndef COMPILERPRACTICE1_LOCATION_H
#define COMPILERPRACTICE1_LOCATION_H
#include "position.h"
class location {
    public:
    position begin;
    position end;

    location();
    location(const int line, const int column);
    location(position a, position b);
    void step();
    void columns(int count);
    void lines(int count);
    location addLocation(const location& loc);
    location addWith(int width);
    location subWidth(int width);
    location copy();
    std::string toString() const;

};
#endif //COMPILERPRACTICE1_LOCATION_H