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

	Ant::Ant() :Arthropods(Species::ANT)
	{};

	void Ant::move(Arthropods* board[][SIZE], Direction direction)
	{
		Direction direction = static_cast<Direction>(rand() % ALL_DIRECTIONS.size());

		StepStatus step_status = get_next_step_status(board, direction);

		int row_offset = 0;
		int col_offset = 0;
		if (step_status == StepStatus::EMPTY) 
		{
			switch (direction) 
			{
			case Direction::UP:
				row_offset = -1;
				break;
			case Direction::DOWN:
				row_offset = 1;
				break;
			case Direction::LEFT:
				col_offset = -1;
				break;
			case Direction::RIGHT:
				col_offset = 1;
				break;
			}
		}
		get<ROW_IDX>(coordinate) = get<ROW_IDX>(coordinate) + row_offset;
		get<COL_IDX>(coordinate) = get<COL_IDX>(coordinate) + col_offset;


	}

	void Ant::breed()
	{
	}




}//salesavitch