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


	void Ant::move(Arthropods* board[][SIZE])
	{
		Direction direction = static_cast<Direction>(rand() % ALL_DIRECTIONS.size());
		move(board, direction);
	}

	void Ant::move(Arthropods* board[][SIZE], Direction direction)
	{
		
		StepStatus step_status = StepStatus::IDLE;

		//try until there's no way around
		int trial = 0;
		do{
			if (trial != 0)
			{
				direction = next_dirction(direction);
			}
			trial++;
			step_status = get_next_step_status(board, direction);
		} while ( (step_status == StepStatus::EMPTY || trial == 4 ) == false);

		//wrong if missing this line, will move randamly, overlapping with other
		if (trial == 4)
		{
			step_status = StepStatus::IDLE;
		}

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

		//wrong
		//if (row_offset != 0 && col_offset != 0)
		if(row_offset!= 0 || col_offset != 0)
		{ 
			//cancel its original place on the board
			board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] = NULL;

			//update its own place
			get<ROW_IDX>(coordinate) = get<ROW_IDX>(coordinate) + row_offset;
			get<COL_IDX>(coordinate) = get<COL_IDX>(coordinate) + col_offset;

			//update its new place on the board
			board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] = this;
		}
	}

	void Ant::breed()
	{
	}




}//salesavitch