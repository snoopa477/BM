// hw13_doodlebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ant.h"
#include "Common.h"
#include "Arthropods.h"

#include <iostream>
#include<tuple>

using namespace std;

//this line is needed to use Arthroods
//this appear before funciton declaration
using namespace predator_prey_simulation;

void  draw_board(Arthropods* board[][SIZE]);
void  print_line(Arthropods* board[]);







int main()
{
    //cannot use because it has pure virtual function
    //Arthropods a;


    //syntax wrong
    //Arthropods* [SIZE][SIZE] board;;

    //Arthropods* board[SIZE][SIZE] = new Arthropods * [SIZE][SIZE]{};
    Arthropods* board[SIZE][SIZE]{};

    Arthropods* p_ant = new Ant();

    tuple<int, int> coord = p_ant->get_coordinate();

    board[get<ROW_IDX>(coord)][get<COL_IDX>(coord)] = p_ant;

    while (true)
    {

        draw_board(board);

        coord = p_ant->get_coordinate();
        board[get<ROW_IDX>(coord)][get<COL_IDX>(coord)] = NULL;
        
        p_ant->move();

        coord = p_ant->get_coordinate();
        tuple<int, int> coord = p_ant->get_coordinate();
        board[get<ROW_IDX>(coord)][get<COL_IDX>(coord)] = p_ant;


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