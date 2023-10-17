#ifndef RANDOMMANAGER_H
#define RANDOMMANAGER_H
#include <string>
#include<tuple>
using namespace std;

namespace predator_prey_simulation
{
    class RandomManager
    {
    public:
        //precondition: size has to be positive
        RandomManager(int size);
        bool has_next_index();
        int next_index();

    private:
        int size;
        //inclusive
        int last;
        int* values;

        void swap(int* values, int i, int j);
    };
}
#endif