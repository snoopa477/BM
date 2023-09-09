#include <iostream>

using namespace std;


double findMedian(int arr[], int arrSize);
double findMedianOddSize(int arr[], int arrSize);
double findMedianEvenSize(int arr[], int arrSize);

void updateNumbeToCounter(int arr[], int arrSize, int* number_to_counter);

void testAndPrint(int* arr, int arrSize);
void printArr(int* arr, int arrSize);

int main()
{

    int arr[] = { 3, 5, 3, 7, 1, 7, 6 };
    int size = 7;
    testAndPrint(arr, size) ;


    int arr2[] = { 4, 1, 6, 2, 7, 3, 2, 8 };
    int size2 = 8;
    testAndPrint(arr2, size2) ;


    int arr3[] = { 1, 2, 3, 1, 1 };
    int size3 = 5;
    testAndPrint(arr3, size3);


    int arr4[] = { 1, 2, 3, 1, 2 };
    int size4 = 5;
    testAndPrint(arr4, size4);


    int arr5[] = { 6, 6, 6, 2, 2, 2 };
    int size5 = 6;
    testAndPrint(arr5, size5);

}

double findMedian(int arr[], int arrSize) {

    //odd size
    if (arrSize % 2 == 1) {
        return findMedianOddSize(arr, arrSize);
    }
    //even size
    else {
        return findMedianEvenSize(arr, arrSize);
    }
}



double findMedianOddSize(int arr[], int arrSize) {

    //DETAIL: use {} to intialize all elements' value to 0
    int* number_to_counter = new int[arrSize + 1]{};
    
    updateNumbeToCounter(arr, arrSize, number_to_counter);

    int median_counter = (arrSize + 1) / 2;

    int number_in_arr = 1;
    while (median_counter > 0) {

        median_counter -= number_to_counter[number_in_arr];

        //WRONG if I miss this
        if (median_counter <= 0) {
            break;
        }
        number_in_arr++;
    }

    delete[] number_to_counter;
    return number_in_arr;
}



void updateNumbeToCounter(int arr[], int arrSize, int* number_to_counter) {

    for (int i = 0; i < arrSize; i++) {
        int number = arr[i];

        //DETAIL: double check if number is under defition, in case of array out of boundary error
        if (number >= 1 && number <= arrSize) {
            number_to_counter[number]++;
        }
    }
    
}



double findMedianEvenSize(int arr[], int arrSize){
    //DETAIL: use {} to intialize all elements' value to 0
    int* number_to_counter = new int[arrSize + 1]{};

    updateNumbeToCounter(arr, arrSize, number_to_counter);

    int median_counter_1 = arrSize / 2;
    int median_counter_2 = (arrSize / 2) + 1;

    int median_1 = 0;
    int median_2 = 0;

    int number_in_arr = 1;
    //PURPOSE: find median_1
    while (median_counter_1 > 0) {

        median_counter_1 -= number_to_counter[number_in_arr];

        //WRONG if I miss this
        if (median_counter_1 <= 0) {
            break;
        }
        number_in_arr++;
    }


    //PURPOSE: find median_2
    if (median_counter_1 == 0) {
        median_1 = number_in_arr;
        
        //REASONING: ...
        int median_counter_2 = median_counter_1 + 1;
        //REASONING and DETAIL: ...
        number_in_arr++;

        while (median_counter_2 > 0) {

            median_counter_2 -= number_to_counter[number_in_arr];

            //WRONG if I miss this
            if (median_counter_2 <= 0) {
                break;
            }
            number_in_arr++;
        }
        median_2 = number_in_arr;

    }
    // median_counter_1 < 0
    else {
        median_1 = median_2 = number_in_arr;
    }

    delete[] number_to_counter;


    //WRONG: DETAIL: integer + integer is still integer
    //return (median_1 + median_2) / 2;

    //DETAIL: This would be a warning since int + int might overflow before being casted us double
    //return ((median_1 + median_2) / 2.0;

    return ((double)median_1 + median_2) / 2;
}



void testAndPrint(int* arr, int arrSize) {
    
    printArr(arr, arrSize);
    cout << "The median is " << findMedian(arr, arrSize) << endl << endl;
}



void printArr(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}