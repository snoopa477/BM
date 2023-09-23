#include <iostream>

using namespace std;
int minInArray1(int arr[], int arrSize);
int minInArray1_Helper(int arr[], int i, int arrSize);

int minInArray2(int arr[], int low, int high);
void printArray(int* arr, int arrSize);



int main(){
    int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
    int res1, res2, res3, res4;

    printArray(arr, 10);
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl << endl;  //should both be -9 

    printArray(arr + 2, 4);
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2]) 
    cout << res3 << " " << res4 << endl;  //should both be 3 

}



int minInArray1(int arr[], int arrSize) {
    //start with leftmost position: 0
    return minInArray1_Helper(arr, 0, arrSize);
}



int minInArray1_Helper(int arr[], int i, int arrSize) {

    /*base case, stop calling itself.And since it has no more right side element to compare
    , itself is the min*/
    if (i == arrSize - 1) {
        return arr[i];
    }

    //PURPOSE : compare current value with min from the right hand side, which is min from i + 1 to arrSize -1
    int min_right_side = minInArray1_Helper(arr, i + 1, arrSize);
    int current_val = arr[i];

    //compare and return the smaller one
    return current_val <= min_right_side ? current_val : min_right_side;

}



int minInArray2(int arr[], int low, int high) {

    /*base case, stop calling itself.And since it has no more right side element to compare
    , itself is the min*/
    if (low >= high) {
        return arr[low];
    }

    //PURPOSE : compare current value with min from the right hand side, which is min from i + 1 to arrSize -1
    int min_right_side = minInArray2(arr, low + 1, high);
    int current_val = arr[low];

    return current_val <= min_right_side ? current_val : min_right_side;
}



void printArray(int* arr, int arrSize) {

    bool is_first = true;

    for (int i = 0; i < arrSize; i++) {
        cout << (is_first ? "" : ", ") << arr[i];
        is_first = false;
    }
    cout << endl;
}
