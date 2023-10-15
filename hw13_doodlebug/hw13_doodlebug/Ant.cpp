//This is the implementation file: sale.cpp
//This is the implementation for the class Sale.
//The interface for the class Sale is in
//the header file sale.h.
#include "Ant.h"
#include "Common.h"
#include "Direction.h"

#include <cstdlib>  
#include <ctime>  

namespace predator_prey_simulation
{

	Ant::Ant() :Arthropods("Ant")
	{};

	void Ant::move()
	{
		Direction direction = static_cast<Direction>(rand() % ALL_DIRECTIONS.size());

		switch (direction)
		{
		case Direction::UP:
			if (0 + 1 < get<ROW_IDX>(coordinate) && get<ROW_IDX>(coordinate) < SIZE)
			{
				get<ROW_IDX>(coordinate) = get<ROW_IDX>(coordinate) - 1;
			}
			break;

		case Direction::DOWN:
			if (0 < get<ROW_IDX>(coordinate) && get<ROW_IDX>(coordinate) < SIZE -1)
			{
				get<ROW_IDX>(coordinate) = get<ROW_IDX>(coordinate) + 1;
			}
			break;

		case Direction::LEFT:
			if (0 + 1 < get<COL_IDX>(coordinate) && get<COL_IDX>(coordinate) < SIZE)
			{
				get<COL_IDX>(coordinate) = get<COL_IDX>(coordinate) - 1;
			}
			break;

		case Direction::RIGHT:
			if (0 < get<COL_IDX>(coordinate) && get<COL_IDX>(coordinate) < SIZE - 1)
			{
				get<COL_IDX>(coordinate) = get<COL_IDX>(coordinate) + 1;
			}
			break;
		}

	}

	void Ant::breed()
	{
	}




}//salesavitch