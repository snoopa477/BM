// hw13_doodlebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Ant.h"
#include "Common.h"
#include "Arthropods.h"
#include "Doodlebug.h"

#include <iostream>
#include<tuple>
#include<vector>

using namespace std;

//this line is needed to use Arthroods
//this appear before funciton declaration
using namespace predator_prey_simulation;

void  draw_board(Arthropods* board[][SIZE]);
void  print_line(Arthropods* board[]);
string getSymbol(Arthropods* row_of_board[], int j);


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

    int ant_number = 1;
    vector<Arthropods*> p_ants;
    for (int i = 0; i < ant_number; i++) {
        p_ants.push_back(new Ant(board));
    }

    //Arthropods* p_ant = new Ant(board);
    Arthropods* p_ant_newbie = NULL;
    vector<Arthropods*> p_ant_newbies ;



    int doodlebug_number = 1;
    vector<Arthropods*> p_doodlebugs;
    for (int i = 0; i < doodlebug_number; i++) {
        p_doodlebugs.push_back(new DoodleBug(board));
    }

    Arthropods* p_doodlebug_newbie = NULL;
    vector<Arthropods*> p_doodlebug_newbies;

  
    while (true)
    {
        //Arthropods::p_randomManager = new RandomManager(4);

        draw_board(board);

 
        //p_ant->move(board);
        
        //WRONG: p_ants.push_back(p_newbie); affect p_ants.size(), hence inifiting calling 

        //for (int i = 0; i < p_ants.size(); i++) {
        //    cout << "helle" << p_ants.size() << endl;

        //    if ((p_newbie = p_ants[i]->live(board)) != NULL)
        //    {
        //        p_ants.push_back(p_newbie);
        //    }
        //}


        for (int i = 0; i < p_doodlebugs.size(); i++) {
            if ((p_doodlebug_newbie = p_doodlebugs[i]->live(board)) != NULL)
            {
                p_doodlebug_newbies.push_back(p_doodlebug_newbie);
            }
        }
        p_doodlebugs.insert(p_doodlebugs.end(), p_doodlebug_newbies.begin(), p_doodlebug_newbies.end());
        p_doodlebug_newbies.clear();





        for (int i = 0; i < p_ants.size(); i++) {
            if ((p_ant_newbie = p_ants[i]->live(board)) != NULL)
            {
                p_ant_newbies.push_back(p_ant_newbie);
            }
        }
        p_ants.insert(p_ants.end(), p_ant_newbies.begin(), p_ant_newbies.end());
        p_ant_newbies.clear();

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
        //cout << " " << ( (row_of_board[j] != NULL) ? "o" : "-" );
        cout << " " << getSymbol(row_of_board, j);
    }
    cout << endl;
}


string getSymbol(Arthropods* row_of_board[], int j)
{
    Arthropods* p_arthropods = row_of_board[j];

    if (p_arthropods == NULL)
    {
        return "-";
    }
    else if (p_arthropods->get_species() == Species::ANT)
    {
        return "o";
    }
    else if (p_arthropods->get_species() == Species::ARTHORPODS)
    {
        return "x";
    }
    else
    {
        return "?";
    }

}