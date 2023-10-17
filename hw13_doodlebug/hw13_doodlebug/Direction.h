#ifndef DIRECTION_H
#define DIRECTION_H

#include<vector>

using namespace std;

enum class Direction {
    UP, DOWN, LEFT, RIGHT, IDLE
};

static vector<Direction> ALL_DIRECTIONS(
    { Direction::UP, 
    Direction::DOWN, 
    Direction::LEFT, 
    Direction::RIGHT,
    Direction::IDLE
    });


#endif