#include <iostream>
#include <vector>
using namespace std;


int* findMissing(int arr[], int n, int& resArrSize);
int* findMissingHelper(bool* num_to_exist, int n, int& resArrSize);
int* vectorToArray(vector<int> v);
void printArray(int* arr, int arrSize);

int main(){
    {
        int arr[] = { 3, 1, 3, 0, 6, 4 };
        int size = 6;
        int resArrSize = 0;

        int* missing_numbers = findMissing(arr, size, resArrSize);
        printArray(missing_numbers, resArrSize);
    }

    {
        int arr[] = { 0, 2, 4, 2, 3, 4 };
        int size = 6;
        int resArrSize = 0;

        int* missing_numbers = findMissing(arr, size, resArrSize);
        printArray(missing_numbers, resArrSize);
    }
}



int* findMissing(int arr[], int n, int& resArrSize) {

    //as the question defines
    int totalPossibleNumbers = n + 1;

    //use {} to set default as fault
    bool* num_to_exist = new bool[totalPossibleNumbers] {};

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        num_to_exist[num] = true;
    }

    int* missing_numbers = findMissingHelper(num_to_exist, totalPossibleNumbers, resArrSize);
    return missing_numbers;
}



int* findMissingHelper(bool* num_to_exist, int n, int& resArrSize) {

    vector<int> missing_numbers;

    for (int i = 0; i < n; i++) {
        //if missing, add this to result
        if (num_to_exist[i] == false) {
            missing_numbers.push_back(i);
        }
    }

    resArrSize = missing_numbers.size();

    return vectorToArray(missing_numbers);
}



//REFERENCE: hw10_01_StrTokens.cpp
int* vectorToArray(vector<int> v) {

    int* arr = new int[v.size()];


    int i = 0;
    for (int element : v) {
        arr[i] = element;
        i++;
    }

    return arr;
}



void printArray(int* arr, int arrSize) {

    bool is_first = true;

    for (int i = 0; i < arrSize; i++) {
        cout << (is_first ? "" : ", ") << arr[i];
        is_first = false;
    }
    cout << endl;
}
