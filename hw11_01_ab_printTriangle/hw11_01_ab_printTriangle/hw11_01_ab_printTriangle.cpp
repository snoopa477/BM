#include <iostream>
using namespace std;

void printTriangle(int n);
void printTriangleHelper(int current_n, int max_n);
void printOppositeTriangles(int n);
void printOppositeTrianglesHelper(int current_n, int max_n);
void printStarInLine(int number_stars);


int main(){

    cout << "test printTriangle(4);" << endl;
    printTriangle(4);
    
    cout << "\ntest printOppositeTriangles(4);" << endl;
    printOppositeTriangles(4);
}



void printTriangle(int n) {
    printTriangleHelper(1, n);
}



void printTriangleHelper(int current_n, int max_n) {

    //base case, stop furthing calling itself
    if (current_n > max_n) {
        return;
    }

    printStarInLine(current_n);
    printTriangleHelper(current_n + 1, max_n);
}



void printOppositeTriangles(int n) {
    printOppositeTrianglesHelper(n, n);
}



void printOppositeTrianglesHelper(int current_n, int max_n) {

    //base case, stop furthing calling itself, call other function instead
    if (current_n <= 0) {
        printTriangle(max_n);
        /*WRONG if I miss this line, because it will continue to executes, calling printOppositeTrianglesHelper(current_n - 1, max_n);
        * causing another calling printTriangle(max_n), leading infinite loop
        */
        return;
    }

    printStarInLine(current_n);
    //DETAIL: note the difference from printTriangleHelper(int current_n, int max_n) 
    printOppositeTrianglesHelper(current_n - 1, max_n);
}



void printStarInLine(int number_stars) {
    for (int i = 0; i < number_stars; i++) {
        cout << "*";
    }
    cout << endl;
}