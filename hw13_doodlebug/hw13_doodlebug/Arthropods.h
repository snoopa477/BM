#ifndef ARTHROPODS_H
#define ARTHROPODS_H
#include <string>
#include<tuple>
#include<string>
#include "StepStatus.h"
#include "Direction.h"
#include "Species.h"

using namespace std;

namespace predator_prey_simulation
{
    class Arthropods
    {
    public:

        Arthropods();
        Arthropods(Species species);

        void virtual move(Arthropods* board[][SIZE], Direction direction) = 0;
        void virtual breed() = 0;

        Species get_species();

        tuple<int, int> get_coordinate() const;

        StepStatus get_next_step_status( Arthropods* board[][SIZE], Direction direction ) const;

    protected:
        tuple<int, int> coordinate;

    private: 
        Species species;
    };
}
#endif //ATHROPODS_H