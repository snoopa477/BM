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
        Ant();
        void move() override ;
        void breed() override ;
    private:
    };
}
#endif //ANTHROPODS_H