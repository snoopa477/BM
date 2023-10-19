// hw13_doodlebug.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>

#include "Ant.h"
#include "Common.h"
#include "Arthropods.h"
#include "Doodlebug.h"

#include <iostream>
#include<tuple>
#include<vector>
#include <iomanip>

 

using namespace std;

//this line is needed to use Arthroods
//this appear before funciton declaration
using namespace predator_prey_simulation;

void  draw_board(Arthropods* board[][SIZEE]);
void  print_line(Arthropods* board[]);
string getSymbol(Arthropods* row_of_board[], int j);
void print_symbol(Arthropods* row_of_board[], int j);

void clear_the_deaths(vector<Arthropods*>& arthropods);

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
    Arthropods* board[SIZEE][SIZEE]{};

    //test if overlapping
    //int number = 399;

    int ant_number = 100;
    vector<Arthropods*> p_ants;
    for (int i = 0; i < ant_number; i++) {
        p_ants.push_back(new Ant(board));
    }

    //Arthropods* p_ant = new Ant(board);
    Arthropods* p_ant_newbie = NULL;
    vector<Arthropods*> p_ant_newbies ;



    int doodlebug_number = 5;
    vector<Arthropods*> p_doodlebugs;
    for (int i = 0; i < doodlebug_number; i++) {
        p_doodlebugs.push_back(new DoodleBug(board));
    }

    Arthropods* p_doodlebug_newbie = NULL;
    vector<Arthropods*> p_doodlebug_newbies;

    int round = 1;
    while (true)
    {
        cout << "----------------------------------------------- round " << round++ << endl;
        cout << endl << endl;
        cout << "number of doodlebugs (x): " << p_doodlebugs.size() << endl;
        cout << "number of ants (o): " << p_ants.size() << endl;


        //Arthropods::p_randomManager = new RandomManager(4);

        cout << endl << endl;

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

        //clear those who staves
        clear_the_deaths(p_doodlebugs);
        //clear those who are eaten
        clear_the_deaths(p_ants);

   
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


void  draw_board(Arthropods* board[][SIZEE])
{
    for (int i = 0; i < SIZEE; i++) {

        cout << setw(2) << i << " ";

        print_line(board[i]);

        
    }

    cout << "    0                   1 " << endl;
    cout << "    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 " << endl;
    cout << endl;

}



void  print_line(Arthropods* row_of_board[]) {

    for( int j = 0; j < SIZEE; j++)
    {
        //this would be 0 1
        //cout << " " << (row_of_board[j] != NULL) ? "o" : "-";
        //cout << " " << ( (row_of_board[j] != NULL) ? "o" : "-" );
        //cout << " " << getSymbol(row_of_board, j);
        print_symbol(row_of_board, j);
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
    else if (p_arthropods->get_species() == Species::DOODLEBUG)
    {
        return "x";
    }
    else
    {
        return "?";
    }

}



void print_symbol(Arthropods* row_of_board[], int j)
{
    Arthropods* p_arthropods = row_of_board[j];

    if (p_arthropods == NULL)
    {
        cout << " -";
    }
    else if (p_arthropods->get_species() == Species::ANT)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << " o";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    else if (p_arthropods->get_species() == Species::DOODLEBUG)
    {   
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << " x";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
 
    }
    else
    {
        cout << " ?";
    }

}



void clear_the_deaths(vector<Arthropods*>& arthropods)
{

    for (size_t i = 0; i < arthropods.size();) {
        if (arthropods[i]->is_dead) {
            //why i can't?
            //delete arthropods[i];
            arthropods.erase(arthropods.begin() + i);
        }
        else {
            ++i;
        }
    }
    
}