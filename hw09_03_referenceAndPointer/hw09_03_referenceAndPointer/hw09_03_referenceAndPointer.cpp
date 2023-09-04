#include <iostream>

using namespace std;

const int SIZE = 6;
int SAMPLE_ARR[SIZE] = { 3, -1, -3, 0, 6, 4 };

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int getPosNumsSize(int* arr, int arrSize);

void testAndPrint1(int* arr, int arrSize);
void testAndPrint2(int* arr, int arrSize);
void testAndPrint3(int* arr, int arrSize);
void testAndPrint4(int* arr, int arrSize);

void printArray(int* arr, int arrSize);

//refernce: pointer and reference
//https://hackmd.io/@B7i0qMBLTyyyRp1nasdE-Q/ryfTY48qd
int main()
{
    testAndPrint1(SAMPLE_ARR, SIZE);
    testAndPrint2(SAMPLE_ARR, SIZE);
    testAndPrint3(SAMPLE_ARR, SIZE);
    testAndPrint4(SAMPLE_ARR, SIZE);
}



int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {

    outPosArrSize = getPosNumsSize(arr, arrSize);
    //WRONG! because when this function ends, local var would be cleared due to stack.
    //int new_arr[SIZE] = {};
    int* new_arr = new int[outPosArrSize];
    int new_index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            new_arr[new_index] = arr[i];
            new_index++;
        }
    }

    return new_arr;
}



int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {

    *outPosArrSizePtr = getPosNumsSize(arr, arrSize);
    int* new_arr = new int[*outPosArrSizePtr];
    int new_index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            new_arr[new_index] = arr[i];
            new_index++;
        }
    }

    return new_arr;
}



void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {

    outPosArrSize = getPosNumsSize(arr, arrSize);
    outPosArr = new int[outPosArrSize];
    int new_index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[new_index] = arr[i];
            new_index++;
        }
    }
}



void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {

    *outPosArrSizePtr = getPosNumsSize(arr, arrSize);
    *outPosArrPtr = new int[*outPosArrSizePtr];
    int new_index = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[new_index] = arr[i];
            new_index++;
        }
    }

}



int getPosNumsSize(int* arr, int arrSize) {

    int counter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            counter++;
        }
    }
    return counter;
}



void testAndPrint1(int* arr, int arrSize) {

    cout << endl << " - - - testAndPrint1 - - -" << endl;

    cout << "orginal array" << endl;
    printArray(arr, arrSize);

    int new_arr_size = 0;
    int* new_arr = getPosNums1(arr, arrSize, new_arr_size);

    cout << "new array" << endl;
    printArray(new_arr, new_arr_size);

    //https://stackoverflow.com/questions/37182040/delete-dynamic-array
    delete[] new_arr;
}



void testAndPrint2(int* arr, int arrSize) {

    cout << endl << " - - - testAndPrint2 - - -" << endl;

    cout << "orginal array" << endl;
    printArray(arr, arrSize);

    int new_arr_size = 0;
    int* new_arr = getPosNums2(arr, arrSize, &new_arr_size);

    cout << "new array" << endl;
    printArray(new_arr, new_arr_size);

    delete[] new_arr;
}



void testAndPrint3(int* arr, int arrSize){

    cout << endl << " - - - testAndPrint3 - - -" << endl;

    cout << "orginal array" << endl;
    printArray(arr, arrSize);

    int new_arr_size = 0;
    //WRONG, but why?
    //`a reference of type int & cannot be initialized with a value of type int[6]`
    //int new_arr[SIZE] = {};

    int* new_arr = new int[new_arr_size];
        
    //getPosNums3(arr, arrSize, new_arr, new_arr_size);
    getPosNums3(arr, arrSize, new_arr, new_arr_size);

    cout << "new array" << endl;
    printArray(new_arr, new_arr_size);

    
    delete[] new_arr;
}



void testAndPrint4(int* arr, int arrSize) {

    cout << endl << " - - - testAndPrint4 - - -" << endl;

    cout << "orginal array" << endl;
    printArray(arr, arrSize);

    int new_arr_size = 0;

    int* new_arr = new int[new_arr_size];

    getPosNums4(arr, arrSize, &new_arr, &new_arr_size);

    cout << "new array" << endl;
    printArray(new_arr, new_arr_size);

    delete[] new_arr;
}



void printArray(int* arr, int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}