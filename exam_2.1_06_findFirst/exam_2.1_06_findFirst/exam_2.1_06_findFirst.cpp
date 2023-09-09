#include <iostream>
using namespace std;

int findFirstPosition(int arr[], int arrSize, int elem);
int findFirstPositionHelper(int arr[], int arrSize, int elem, int index);

void testAndPrint(int* arr, int size, int elem_to_find);
void printArr(int* arr, int arrSize);

const int NOT_FOUND_VALUE = -1;


int main()
{
    int size = 10;
    int arr[] = { 2, 15, 3, 8, 3, 10, 6, 23, 12, 32 };

    testAndPrint(arr, size, 3);
    testAndPrint(arr, size, 7);
    testAndPrint(arr, size, 10);

}



int findFirstPosition(int arr[], int arrSize, int elem) {
    //DETAIL: we start with index 0
    return findFirstPositionHelper(arr, arrSize, elem, 0);
}



int findFirstPositionHelper(int arr[], int arrSize, int elem, int index) {

    //base case
    /*REASONING: when index == arrSize, we can say we already searched for elem 
    from the whole valid indexes(0 to arrSize - 1)
    * and still not find any. Therefore, index == arrSize means not found
    */
    if (arrSize == index) {
        return NOT_FOUND_VALUE;
    }


    if (arr[index] == elem) {
        return index;
    }
    //REASONING: reaching here means both preivous conditions don't hold
   

    //PURPOSE: delegate the 'find First Element' job to next function, with index + 1
    int next_index = index + 1;
    int result = findFirstPositionHelper(arr, arrSize, elem, next_index);
    return result;
}



void testAndPrint(int* arr, int size, int elem_to_find) {

    printArr(arr, size);
    cout << "First position of (" << elem_to_find << ") is " << findFirstPosition(arr, size, elem_to_find) << endl << endl;
}



void printArr(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}