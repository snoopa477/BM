#include <iostream>

using namespace std;


int sumOfSquares(int arr[], int arrSize);
int sumOfSquaresHelper(int arr[], int arrSize, int i);
bool isSorted(int arr[], int arrSize);
bool isSortedHelper(int arr[], int arrSize, int i);
void printArray(int* arr, int arrSize);


int main(){
    int arr1[] = { 2, -1, 3, 10 };
    int arr2[] = { -1, 2, 3, 10 };

    printArray(arr1, 4);
    cout << "The sum of squares of menteiond above array: " << sumOfSquares(arr1, 4) << endl << endl;


    printArray(arr1, 4);
    cout << "Is the array mentioned above sorted ascendingly?" << isSorted(arr1, 4) << endl << endl;

    printArray(arr2, 4);
    cout << "Is the array mentioned above sorted ascendingly?" << isSorted(arr2, 4) << endl << endl;

}



int sumOfSquares(int arr[], int arrSize) {
    return sumOfSquaresHelper(arr, arrSize, 0);
}



int sumOfSquaresHelper(int arr[], int arrSize, int i) {

    //base case, stop calling itself and return 0, since there's nothing here
    if (i == arrSize) {
        return 0;
    }

    return (arr[i] * arr[i]) + sumOfSquaresHelper(arr, arrSize, i + 1);
}



bool isSorted(int arr[], int arrSize) {
    //DETAIL: we start with 1, not 0, becuase we compare index i, and previous one: i-1
    return isSortedHelper(arr, arrSize, 1);
}



bool isSortedHelper(int arr[], int arrSize, int i) {

    /*REASONING
    * Reaching here means `any` of functions from f(0) to f(arrSize-1) not fail, not returning false; 
    * Therefore, we can say `all` functions from f(0) to f(arrSize-1)  succeed, returning true
    */
    if (i == arrSize) {
        return true;
    }

    /*REASONING 
     the precondition of sorted ascendingly is one pair statisfying arr[i - 1] <= arr[i]
    */
    if (arr[i - 1] <= arr[i]) {
        //this function passes, check for the next function
        return isSortedHelper(arr, arrSize, i + 1);
    }

    //REACHING here means (arr[i - 1] > arr[i]), which violates sorted ascendingly, return false if any function reaches here
    return false;
}



void printArray(int* arr, int arrSize) {

    bool is_first = true;

    for (int i = 0; i < arrSize; i++) {
        cout << (is_first ? "" : ", ") << arr[i];
        is_first = false;
    }
    cout << endl;
}
