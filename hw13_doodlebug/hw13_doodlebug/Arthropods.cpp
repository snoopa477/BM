//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "Arthropods.h"
#include "Common.h"
#include "StepStatus.h"
#include "Direction.h"
#include "RandomManager.h"

#include <cstdlib>  
#include <ctime>  
#include <iostream>

using namespace std;
namespace predator_prey_simulation
{
	Arthropods::Arthropods(Arthropods* board[][SIZE])
	{
		//if the place is occupied by other, redo the assignment
		do {
			get<ROW_IDX>(coordinate) = rand() % SIZE;
			get<COL_IDX>(coordinate) = rand() % SIZE;
		} while (board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] != NULL);

		//register the arthropod on the board
		board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] = this;
	}

	//wrong
	//Arthropods::Arthropods(Arthropods* board[][SIZE], Species vspecies) : Arthropods(board)
	Arthropods::Arthropods(Arthropods* board[][SIZE], Species vspecies) : Arthropods(board)
	{
		//wrong if
		//species = species
		species = vspecies;
		longevity = 0;
	}


	Arthropods::Arthropods(Arthropods* board[][SIZE], tuple<int, int> v_coordinate, Direction direction, Species vspecies)
	{
		species = vspecies;
		longevity = 0;

		int row_offset = 0;
		int col_offset = 0;

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

		get<ROW_IDX>(coordinate) = get<ROW_IDX>(v_coordinate) + row_offset;
		get<COL_IDX>(coordinate) = get<COL_IDX>(v_coordinate) + col_offset;

		board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] = this;

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
				//cout << "this is ant" << endl;
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



	Direction Arthropods::next_dirction(Direction direction)
	{
		Direction next_direction = direction;
		switch (direction)
		{
		case Direction::UP:
			next_direction = Direction::DOWN;
			break;
		case Direction::DOWN:
			next_direction = Direction::LEFT;
			break;
		case Direction::LEFT:
			next_direction = Direction::RIGHT;
			break;
		case Direction::RIGHT:
			next_direction = Direction::UP;
			break;
		default:
			break;
		}

		return next_direction;
	}


	Direction Arthropods::get_neighborhood_such_step_status(Arthropods* board[][SIZE], StepStatus target_step_status)
	{

		vector<Direction> directions{ Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};

		RandomManager randomManager(directions.size());

		//for (Direction direction : directions) {
		//	if (get_next_step_status(board, direction) == target_step_status)
		//	{
		//		return direction;
		//	}
		//}

		while (randomManager.has_next_index())
		{
			Direction direction = directions[randomManager.next_index()];
			if (get_next_step_status(board, direction) == target_step_status)
			{
				return direction;
			}
		}


		//reaching here means find nothing
		return Direction::IDLE;
	}



}//salesavitch