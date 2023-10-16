#ifndef ARTHROPODS_H
#define ARTHROPODS_H
#include <string>
#include<tuple>
#include<string>
#include "StepStatus.h"
#include "Direction.h"
#include "Species.h"
#include "Common.h"

using namespace std;

namespace predator_prey_simulation
{
    class Arthropods
    {
    public:

        Arthropods(Arthropods* board[][SIZE]);
        Arthropods(Arthropods* board[][SIZE], Species species);

        void virtual move(Arthropods* board[][SIZE]) = 0;
        void virtual move(Arthropods* board[][SIZE], Direction direction) = 0;
        void virtual breed() = 0;

        Species get_species();

        tuple<int, int> get_coordinate() const;

        StepStatus get_next_step_status( Arthropods* board[][SIZE], Direction direction ) const;
        Direction next_dirction( Direction direction );

    protected:
        tuple<int, int> coordinate;

    private: 
        Species species;
    };
}
#endif //ATHROPODS_H