
#include <iostream>
using namespace std;


void reverseArray(int arr[], int arrSize);
//pass by reference
//https://www.w3schools.com/cpp/cpp_function_reference.asp
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

bool isEven(int num);
bool isOdd(int num);

void printArray(int arr[], int arrSize);

int main()
{
    int arr1[10] = { 9, 2, 14, 12, -3 };
    int arr1Size = 5;

    int arr2[10] = { 21, 12, 6, 7, 14 };
    int arr2Size = 5;

    int arr3[10] = { 3, 6, 4, 1, 12 };
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}



void printArray(int arr[], int arrSize) {
    int i;

    for (i = 0; i < arrSize; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}



void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



bool isEven(int num) {
    return num % 2 == 0;
}



bool isOdd(int num) {
    return !isEven(num);
}



void reverseArray(int arr[], int arrSize) {

    int left_index = 0;
    int right_index = arrSize - 1;

    while (left_index < right_index) {
        swap(arr, left_index, right_index);
        left_index++;
        right_index--;
    }
}



void removeOdd(int arr[], int& arrSize) {

    int collector_index = 0;
    int seeker_index = 0;

    for (; seeker_index < arrSize; seeker_index++) {

        if (isEven(arr[seeker_index] )) {
            arr[collector_index] = arr[seeker_index];
            collector_index++;
        }
    }

    int newSize = collector_index - 1 + 1;
    arrSize = newSize;
}



void splitParity(int arr[], int arrSize) {

    int left_index = 0;
    int right_index = arrSize - 1;

    while (left_index < right_index) {

        //proceed until it stops at even number
        while (isOdd(arr[left_index]) && left_index < arrSize) {
            left_index++;
        }

        //proceed until it stops at odd number
        while (isEven(arr[right_index]) && right_index >= 0) {
            right_index--;
        }

        /*now that we have even number at left_index,
        * odd number at right_index.
        * After swapping: 
        * odd number at left_index,
        * even number at right_index.
        */
        if (left_index < right_index) {
            swap(arr, left_index, right_index);
            left_index++;
            right_index--;
        }
    }

}


