#include <iostream>
#include <iomanip>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void testOddsKeepEvensFlipAndPrint(int arr[], int arrSize);
void printArray(int* arr, int arrSize);


int main(){

    int size0 = 6;
    int arr0[] = { 5, 2, 11, 7, 6, 4 };
   
    int size1 = 10;
    int arr1[] = { 23, 84, 11, 33, 90, 107, 84, 100, 0, 1 };

    testOddsKeepEvensFlipAndPrint(arr0, size0);
    testOddsKeepEvensFlipAndPrint(arr1, size1);

}



void oddsKeepEvensFlip(int arr[], int arrSize) {

    //wrong
    //int buffer[] = new int[arrSize];
    int* buffer = new int[arrSize];

    int odd_idx = 0, even_idx = arrSize - 1;

    for (int i = 0; i < arrSize; i++) {
        
        int value = arr[i];

        //check if even
        if (value % 2 == 0) {
            buffer[even_idx] = value;
            even_idx--;
        }
        //odd
        else {
            buffer[odd_idx] = value;
            odd_idx++;
        }
    }

    //override
    for (int i = 0; i < arrSize; i++) {
        arr[i] = buffer[i];
    }

    //free the unused dynamically allocated memory
    delete[] buffer;

}



void testOddsKeepEvensFlipAndPrint(int arr[], int arrSize) {

    cout << "Before" << endl;
    printArray(arr, arrSize);

    oddsKeepEvensFlip(arr, arrSize);
    cout << "After" << endl;
    printArray(arr, arrSize);

    cout << endl;
}




void printArray(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

