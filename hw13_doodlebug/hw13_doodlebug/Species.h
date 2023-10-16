#ifndef SPECIES_H
#define SPECIES_H

#include<vector>

using namespace std;

enum class Species {
    ANT, DOODLEBUG, ARTHORPODS, UNDEFINED
};

static vector<Species> ALL_SPECIES(
    { Species::ANT,
    Species::DOODLEBUG,
    Species::ARTHORPODS,
    Species::UNDEFINED });

#endif