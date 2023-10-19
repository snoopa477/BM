
//Wrong, it will make the whole section grayed out
//#ifndef ANG_H
#ifndef DOODLEBUG_H
#define DOODLEBUG_H
#include "Arthropods.h"
#include <string>
#include<tuple>
using namespace std;

namespace predator_prey_simulation
{
    class DoodleBug : public Arthropods
    {
    public:
        DoodleBug(Arthropods* board[][SIZEE]);
        DoodleBug(Arthropods* board[][SIZEE], tuple<int, int> v_coordinate, Direction direction);


        Arthropods* breed(Arthropods* board[][SIZEE]) override;
        Arthropods* live(Arthropods* board[][SIZEE]) override;

        //if no nearby ant, returns IDLE
        bool is_ant_nearby(Arthropods* board[][SIZEE]);
        void hunt_for_nearby_ant(Arthropods* board[][SIZEE]);

        bool is_starving();
        void starve(Arthropods* board[][SIZEE]);

        
        
    private:
        static const int breeding_frequency = 8;
        static const int full_energy = 3;
        int energy_left;

    };
}
#endif //ANTHROPODS_H