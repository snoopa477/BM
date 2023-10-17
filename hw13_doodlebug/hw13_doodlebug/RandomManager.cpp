#include "RandomManager.h"
#include <cstdlib>  

//this line is a must
namespace predator_prey_simulation
{
	RandomManager::RandomManager(int size)
	{
		values = new int[size];
		last = size - 1;
		for (int i = 0; i < size; i++)
		{
			values[i] = i;
		}
	}


	bool RandomManager::has_next_index()
	{
		return last >= 0;
	}

	int RandomManager::next_index()
	{
		int random_index = rand() % (last + 1) ;
		int random_value = values[random_index];
		swap(values, random_index, last);
		last--;
		return random_value;
	}


	void RandomManager::swap(int* values, int i, int j)
	{
		int temp = values[i];
		values[i] = values[j];
		values[j] = temp;
	}

}