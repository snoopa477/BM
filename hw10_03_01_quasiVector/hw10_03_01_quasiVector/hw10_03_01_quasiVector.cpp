#include <iostream>
#include <iomanip>
//TIP: it's better not to use double pointers; it is really confusing

void initializeArr(int*& arr, int& arr_size, int& arr_capacity);
void pushBack(int*& arr, int new_element, int& arr_size, int& arr_capacity);
bool checkIfReachCapacityLimit(int arr_size, int arr_capacity);
void enlargeArrCapacity(int*& arr, int arr_size, int& arr_capacity);
void copyArray(int* src, int size_src, int* target);
void printArray(int* arr, int arrSize);

using namespace std;

const int INITIAL_CAPACITY = 2;

int main(){
    std::cout << "Hello World!\n";

    int* arr = NULL;
    int arr_size = 0;
    int arr_capacity = 0;

    initializeArr(arr, arr_size, arr_capacity);

    for (int i = 0; i < 30; i++) {
        cout << "i " << i << " a address: " << arr << endl;
        pushBack(arr, i, arr_size, arr_capacity);
    }

    printArray(arr, arr_size);

}



void initializeArr(int*& arr, int& arr_size, int& arr_capacity) {
    arr_size = 0;
    arr_capacity = INITIAL_CAPACITY;
    arr = new int[arr_capacity] {};
}



void pushBack(int*& arr, int new_element, int& arr_size, int& arr_capacity) {

    if ( checkIfReachCapacityLimit(arr_size, arr_capacity) ) {
        enlargeArrCapacity(arr, arr_size, arr_capacity);
    }

    //pushBack
    arr[arr_size] = new_element;
    arr_size++;
}



bool checkIfReachCapacityLimit(int arr_size, int arr_capacity) {
    return arr_size >= arr_capacity;
}



void enlargeArrCapacity(int*& arr, int arr_size, int& arr_capacity) {

    //double the size
    arr_capacity *= 2;

    int* enlargedArr = new int[arr_capacity] {};
    //transfer values from arr to enlargedArr
    copyArray(arr, arr_size, enlargedArr);

    //we don't need this old arr anymore
    delete[] arr;

    //now points to the new enlarged arr
    arr = enlargedArr;

}



//use the method under the premise that size_src <= target array's size
void copyArray(int* src, int size_src, int* target) {

    for (int i = 0; i < size_src; i++) {
        target[i] = src[i];
    }
}



void printArray(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}
