//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "Ant.h"
#include "Common.h"
#include "Direction.h"
#include "Species.h"


#include <cstdlib>  
#include <ctime>  

namespace predator_prey_simulation
{

	Ant::Ant(Arthropods* board[][SIZE]) :Arthropods(board, Species::ANT)
	{};

	Ant::Ant(Arthropods* board[][SIZE], tuple<int, int> v_coordinate, Direction direction) 
		:Arthropods(board, v_coordinate, direction, Species::ANT)
	{};




	Arthropods* Ant::breed(Arthropods* board[][SIZE])
	{

		//not the breeding time
		//if ( longevity % breeding_frequency == 0 && longevity != 0 )
		if ( longevity % breeding_frequency != 0 || longevity == 0 )
		{
			return NULL;
		}

		Direction direction_to_breed = get_neighborhood_such_step_status(board, StepStatus::EMPTY);

		//wait for next round
		if (direction_to_breed == Direction::IDLE)
		{
			//offset longevity++, summing = 0
			longevity--;
			return NULL;
		}
		//EMPTY, can lay egg
	
		Arthropods* newbie = new Ant(board, coordinate, direction_to_breed);
		return newbie;

	}

	Arthropods* Ant::live(Arthropods* board[][SIZE])
	{
		longevity++;
		move(board);
		Arthropods* newbie = breed(board);
		return newbie;
	}


}//salesavitch