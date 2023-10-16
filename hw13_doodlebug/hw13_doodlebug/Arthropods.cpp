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

	Arthropods::Arthropods(Species species) : Arthropods()
	{
		species = species;
	}


	tuple<int, int> Arthropods::get_coordinate() const
	{
		return coordinate;
	}

	Species Arthropods::get_species()
	{
		return species;
	}


	StepStatus Arthropods::get_next_step_status(Arthropods* board[][SIZE], Direction direction) const
	{

		StepStatus step_status = StepStatus::EMPTY;


		if ( (direction == Direction::UP &&  0 == get<ROW_IDX>(coordinate) )
			|| (direction == Direction::DOWN && SIZE -1 == get<ROW_IDX>(coordinate))
			|| (direction == Direction::LEFT && 0 == get<COL_IDX>(coordinate))
			|| (direction == Direction::RIGHT && SIZE -1 == get<COL_IDX>(coordinate)))
		{
			step_status = StepStatus::OBSTACLE;
			return step_status;
		}

		//reaching here means not blocked

		//safely assign next step
		tuple<int, int> next_step = coordinate;
		switch (direction)
		{
		case Direction::UP:
			get<ROW_IDX>(next_step) = get<ROW_IDX>(next_step) - 1;
			break;
		case Direction::DOWN:
			get<ROW_IDX>(next_step) = get<ROW_IDX>(next_step) + 1;
			break;
		case Direction::LEFT:
			get<COL_IDX>(next_step) = get<COL_IDX>(next_step) - 1;
			break;
		case Direction::RIGHT:
			get<COL_IDX>(next_step) = get<COL_IDX>(next_step) + 1;
			break;
		default:
			break;
		}


		//check is there's something already there
		
		if (board[get<ROW_IDX>(next_step)][get<COL_IDX>(next_step)] != NULL)
		{
			Arthropods* p_bug = board[get<ROW_IDX>(next_step)][get<COL_IDX>(next_step)];
			switch (p_bug->get_species())
			{
			case Species::ANT:
					step_status = StepStatus::ANT;
					break;
			case Species::DOODLEBUG:
				step_status = StepStatus::DOODLEBUG;
				break;
			case Species::UNDEFINED:
				step_status = StepStatus::UNDEFINED;
				break;
			default:
				break;
			}
		}

		return step_status;
	}


}//salesavitch