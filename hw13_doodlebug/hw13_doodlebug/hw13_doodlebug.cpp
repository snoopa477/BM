// hw13_doodlebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ant.h"
#include "Common.h"
#include "Arthropods.h"

#include <iostream>
#include<tuple>
#include<vector>

using namespace std;

//this line is needed to use Arthroods
//this appear before funciton declaration
using namespace predator_prey_simulation;

void  draw_board(Arthropods* board[][SIZE]);
void  print_line(Arthropods* board[]);



int main()
{

    unsigned seed;
    seed = (unsigned)time(NULL);
    srand(seed); 
    //cannot use because it has pure virtual function
    //Arthropods a;


    //syntax wrong
    //Arthropods* [SIZE][SIZE] board;;

    //Arthropods* board[SIZE][SIZE] = new Arthropods * [SIZE][SIZE]{};
    Arthropods* board[SIZE][SIZE]{};

    //test if overlapping
    //int number = 399;

    int number = 10;

    vector<Arthropods*> p_ants;

    for (int i = 0; i < number; i++) {
        p_ants.push_back(new Ant(board));
    }

    //Arthropods* p_ant = new Ant(board);

  
    while (true)
    {

        draw_board(board);

 
        //p_ant->move(board);
        for (int i = 0; i < number; i++) {
            p_ants[i]->move(board);
        }
    

        system("pause");
    }


    std::cout << "Hello World!\n";
}


void  draw_board(Arthropods* board[][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        print_line(board[i]);
    }
    cout << endl;
}



void  print_line(Arthropods* row_of_board[]) {

    for( int j = 0; j < SIZE; j++)
    {
        //this would be 0 1
        //cout << " " << (row_of_board[j] != NULL) ? "o" : "-";
        cout << " " << ( (row_of_board[j] != NULL) ? "o" : "-" );
    }
    cout << endl;
}