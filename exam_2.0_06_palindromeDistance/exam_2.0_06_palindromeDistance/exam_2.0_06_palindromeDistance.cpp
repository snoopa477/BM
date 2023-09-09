#include <iostream>

using namespace std;

int palindromeDistance(int* arr, int arrSize);
//wrong: overload
//int palindromeDistance(int* arr, int arrSize, int left_idx);
int palindromeDistanceHelper(int* arr, int arrSize, int left_idx);

void testAndPrint(int* arr, int size);
void printArr(int* arr, int arrSize);



int main()
{
    int size = 6;
    int arr[] = { 1, 3, 6, 6, 5, 2 };
    testAndPrint(arr, size);

    int size2 = 6;
    int arr2[] = { 1, 3, 6, 6, 3, 1 };
    testAndPrint(arr2, size2);

    int size3 = 10;
    int arr3[] = { 0, 1, 2, 3, 4, 44, 33, 2, 11, 0 };
    testAndPrint(arr3, size3);
}



int palindromeDistance(int* arr, int arrSize) {
    return palindromeDistanceHelper( arr, arrSize, 0);
}



int palindromeDistanceHelper(int* arr, int arrSize, int left_idx) {

    //base case
    /* DETAIL:
        when arrSize = 5, (arrSize / 2) == 2
        when arrSize = 4, (arrSize / 3) == 2
    */
    if (left_idx == arrSize/2) {
        return 0;
    }

    int right_idx = arrSize - 1 - left_idx;
    int current_distance = (arr[left_idx] == arr[right_idx] ) ?  0: 1;
 
    //seek for next idx
    int result = current_distance + palindromeDistanceHelper(arr, arrSize, left_idx + 1);
    return result;

}



void testAndPrint( int* arr, int size) {

    printArr(arr, size);
    cout << "palindrome distance is " << palindromeDistance(arr, size) << endl;
}



void printArr(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}