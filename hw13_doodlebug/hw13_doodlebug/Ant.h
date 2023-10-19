#ifndef ANT_H
#define ANT_H
#include "Arthropods.h"
#include <string>
#include<tuple>
using namespace std;

namespace predator_prey_simulation
{
    class Ant : public Arthropods
    {
    public:
        Ant(Arthropods* board[][SIZE]);
        Ant(Arthropods* board[][SIZE], tuple<int, int> v_coordinate, Direction direction);


        Arthropods* breed(Arthropods* board[][SIZE]) override ;
        Arthropods* live(Arthropods* board[][SIZE]) override;
    private:
        static const int breeding_frequency = 3;
    };
}
#endif //ANTHROPODS_H