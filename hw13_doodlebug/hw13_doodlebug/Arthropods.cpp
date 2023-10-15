//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "Arthropods.h"
#include "Common.h"
#include "StepStatus.h"
#include "Direction.h"

#include <cstdlib>  
#include <ctime>  


namespace predator_prey_simulation
{
	Arthropods::Arthropods()
	{
		get<ROW_IDX>(coordinate) = rand() % SIZE;
		get<COL_IDX>(coordinate) = rand() % SIZE;
	}

	Arthropods::Arthropods(string species) : Arthropods()
	{
		species = species;
	}


	tuple<int, int> Arthropods::get_coordinate() const
	{
		return coordinate;
	}

	string Arthropods::get_species()
	{
		return species;
	}


	StepStatus Arthropods::get_next_step_status(Arthropods* board[][SIZE], Direction direction) const
	{

		StepStatus step_status = StepStatus::EMPTY;


		if ( (direction == Direction::UP &&  0 == get<ROW_IDX>(coordinate) )
			|| (direction == Direction::DOWN && SIZE == get<ROW_IDX>(coordinate))
			|| (direction == Direction::LEFT && 0 == get<COL_IDX>(coordinate))
			|| (direction == Direction::RIGHT && SIZE == get<COL_IDX>(coordinate)))
		{
			step_status = StepStatus::OBSTACLE;
		}

		//switch (direction)
		//{
		//case Direction::UP:

		//	//if (0 + 1 < get<ROW_IDX>(coordinate) && get<ROW_IDX>(coordinate) < SIZE)
		//	if ( 0 + 1 < get<ROW_IDX>(coordinate) )
		//	{

		//	}
		//	else 
		//	{
		//		step_status = StepStatus::OBSTACLE;
		//	}
		//	break;

		//case Direction::DOWN:
		//	//if (0 < get<ROW_IDX>(coordinate) && get<ROW_IDX>(coordinate) < SIZE - 1)
		//	if ( get<ROW_IDX>(coordinate) < SIZE - 1)
		//	{

		//	}
		//	else
		//	{
		//		step_status = StepStatus::OBSTACLE;
		//	}
		//	break;

		//case Direction::LEFT:
		//	//if (0 + 1 < get<COL_IDX>(coordinate) && get<COL_IDX>(coordinate) < SIZE)
		//	if (0 + 1 < get<COL_IDX>(coordinate) )
		//	{
	
		//	}
		//	else
		//	{
		//		step_status = StepStatus::OBSTACLE;
		//	}
		//	break;

		//case Direction::RIGHT:
		//	//if (0 < get<COL_IDX>(coordinate) && get<COL_IDX>(coordinate) < SIZE - 1)
		//	if (get<COL_IDX>(coordinate) < SIZE - 1)
		//	{

		//	}
		//	else
		//	{
		//		step_status = StepStatus::OBSTACLE;
		//	}
		//	break;
		//}


	}


}//salesavitch