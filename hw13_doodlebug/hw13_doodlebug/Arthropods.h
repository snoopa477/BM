#ifndef ARTHROPODS_H
#define ARTHROPODS_H
#include <string>
#include<tuple>
#include<string>
#include "StepStatus.h"
#include "Direction.h"

using namespace std;

namespace predator_prey_simulation
{
    class Arthropods
    {
    public:

        Arthropods();
        Arthropods(string species);

        void virtual move() = 0;
        void virtual breed() = 0;

        string get_species();

        tuple<int, int> get_coordinate() const;

        StepStatus get_next_step_status( Arthropods* board[][SIZE], Direction direction ) const;

    protected:
        tuple<int, int> coordinate;

    private: 
        string species;
    };
}
#endif //ATHROPODS_H