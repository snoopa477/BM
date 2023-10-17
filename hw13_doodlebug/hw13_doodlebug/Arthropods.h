#ifndef ARTHROPODS_H
#define ARTHROPODS_H
#include <string>
#include<tuple>
#include<string>
#include "StepStatus.h"
#include "Direction.h"
#include "Species.h"
#include "Common.h"
#include "RandomManager.h"

using namespace std;

namespace predator_prey_simulation
{
    class Arthropods
    {
    public:

        Arthropods(Arthropods* board[][SIZE]);
        Arthropods(Arthropods* board[][SIZE], Species vspecies);

        Arthropods(Arthropods* board[][SIZE], tuple<int, int> v_coordinate, Direction direction, Species vspecies);

        virtual void  move(Arthropods* board[][SIZE]) = 0;
        virtual void  move(Arthropods* board[][SIZE], Direction direction) = 0;
        virtual Arthropods*  breed(Arthropods* board[][SIZE]) = 0;
        virtual Arthropods*  live(Arthropods* board[][SIZE]) = 0;

        Species get_species();

        tuple<int, int> get_coordinate() const;

        StepStatus get_next_step_status( Arthropods* board[][SIZE], Direction direction ) const;
        Direction next_dirction( Direction direction );

        //return IDLE if no such, else UP, DOWN, LEFT, RIGHT
        Direction get_neighborhood_such_step_status(Arthropods* board[][SIZE], StepStatus target_step_status);

        static RandomManager* p_randomManager;

    protected:
        tuple<int, int> coordinate;
        int longevity;

        

    private: 
        Species species;
    };

    
}
#endif //ATHROPODS_H