//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "DoodleBug.h"
#include "Common.h"
#include "Direction.h"
#include "Species.h"


#include <cstdlib>  
#include <ctime>  

namespace predator_prey_simulation
{

	DoodleBug::DoodleBug(Arthropods* board[][SIZE]) :Arthropods(board, Species::DOODLEBUG)
	{
		energy_left = full_energy;
	};

	DoodleBug::DoodleBug(Arthropods* board[][SIZE], tuple<int, int> v_coordinate, Direction direction)
		:Arthropods(board, v_coordinate, direction, Species::DOODLEBUG)
	{
		energy_left = full_energy;
	};




	Arthropods* DoodleBug::breed(Arthropods* board[][SIZE])
	{

		//not the breeding time
		//if ( longevity % breeding_frequency == 0 && longevity != 0 )
		if (longevity % breeding_frequency != 0 || longevity == 0)
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

		Arthropods* newbie = new DoodleBug(board, coordinate, direction_to_breed);
		return newbie;

	}


	bool DoodleBug::is_ant_nearby(Arthropods* board[][SIZE]) 
	{
		Direction direction_to_ant = get_neighborhood_such_step_status(board, StepStatus::ANT);

		if (direction_to_ant == Direction::IDLE)
		{
			return false;
		}

		return true;
	}


	void DoodleBug::hunt_for_nearby_ant(Arthropods* board[][SIZE]) 
	{
		Direction direction_to_ant = get_neighborhood_such_step_status(board, StepStatus::ANT);

		if (direction_to_ant == Direction::IDLE)
		{
			return;
		}

		//kill the ant

		tuple<int, int> ant_coordinate = coordinate;
		switch (direction_to_ant)
		{
		case Direction::UP:
			get<ROW_IDX>(ant_coordinate) = get<ROW_IDX>(ant_coordinate) - 1;
			break;
		case Direction::DOWN:
			get<ROW_IDX>(ant_coordinate) = get<ROW_IDX>(ant_coordinate) + 1;
			break;
		case Direction::LEFT:
			get<COL_IDX>(ant_coordinate) = get<COL_IDX>(ant_coordinate) - 1;
			break;
		case Direction::RIGHT:
			get<COL_IDX>(ant_coordinate) = get<COL_IDX>(ant_coordinate) + 1;
			break;
		default:
			break;
		}

		delete board[get<ROW_IDX>(ant_coordinate)][get<COL_IDX>(ant_coordinate)];


		board[get<ROW_IDX>(ant_coordinate)][get<COL_IDX>(ant_coordinate)] = this;
		coordinate = ant_coordinate;

		energy_left = full_energy;
	}



	bool DoodleBug::is_starving()
	{
		return energy_left <= 0;
	}

	void DoodleBug::starve(Arthropods* board[][SIZE])
	{
		tuple<int, int> tmp_coordinate = coordinate;
		delete board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)];
		//Question: what if I miss this line? the pointed memory is unused?
		// wrong, object not exist so cannt access coordinate
		//board[get<ROW_IDX>(coordinate)][get<COL_IDX>(coordinate)] = NULL;
		board[get<ROW_IDX>(tmp_coordinate)][get<COL_IDX>(tmp_coordinate)] = NULL;
	}


	Arthropods* DoodleBug::live(Arthropods* board[][SIZE])
	{
		energy_left--;
		longevity++;

		if (is_ant_nearby(board))
		{
			hunt_for_nearby_ant(board);
		}
		else
		{
			move(board);
		}

		if (is_starving())
		{
			starve(board);
			return NULL;
		}

		//wrong, if it really kill itself, it cannot call any function, like breed
		//starve(board);
		Arthropods* newbie = breed(board);
		return newbie;
	}


}//salesavitch