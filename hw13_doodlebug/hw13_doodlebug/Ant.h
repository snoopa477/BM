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
        Ant(Arthropods* board[][SIZEE]);
        Ant(Arthropods* board[][SIZEE], tuple<int, int> v_coordinate, Direction direction);


        Arthropods* breed(Arthropods* board[][SIZEE]) override ;
        Arthropods* live(Arthropods* board[][SIZEE]) override;
    private:
        static const int breeding_frequency = 3;
    };
}
#endif //ANTHROPODS_H