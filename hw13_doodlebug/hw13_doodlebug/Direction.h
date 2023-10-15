#include<vector>

using namespace std;

enum class Direction {
    UP, DOWN, LEFT, RIGHT
};

static vector<Direction> ALL_DIRECTIONS({ Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT });