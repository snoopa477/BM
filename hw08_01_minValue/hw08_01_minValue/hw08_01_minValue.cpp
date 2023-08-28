#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits.h>

using namespace std;

const int SIZE = 20;

void tokenize(string input, int arr[], int arrSize);
int minInArray(int arr[], int arrSize);
void printMinAndIndeces(int arr[], int arrSize);

//https://cplusplus.com/reference/string/string/getline/


int main()
{

    string user_input;
    cout << "Please enter 20 integers separated by a space: ";
    //https://stackoverflow.com/questions/5882872/reading-a-full-line-of-input
    getline( cin, user_input);
 
    int numbers[SIZE] = {};
    tokenize(user_input, numbers, SIZE);

    printMinAndIndeces(numbers, SIZE);

    return 0;
}



//https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
void tokenize(string input, int arr[], int arrSize) {

    //https://cplusplus.com/reference/sstream/stringstream/stringstream/
    stringstream ss(input);

    int i = 0;
    string token;
    while (getline(ss, token, ' ') && i < SIZE) {
        arr[i] = stoi(token);
        i++;
    }
}



int minInArray(int arr[], int arrSize) {

    //https://www.geeksforgeeks.org/int_max-int_min-cc-applications/
    int min = INT_MAX;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}



void printMinAndIndeces(int arr[], int arrSize) {

    int min = minInArray(arr, SIZE);
    cout << "The minimum value is " << min << ", and it is located in the following indices:";

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            cout << " " << i;
        }
    }
    cout << endl;
}