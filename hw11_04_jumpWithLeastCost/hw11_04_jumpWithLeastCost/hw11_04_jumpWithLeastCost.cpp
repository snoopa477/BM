#include <iostream>
#include <cmath>

int jumpWithLeastCost(int* arr, int arrSize);
int jumpWithLeastCost(int* cache, int* arr, int position);

using namespace std;


int main(){
    
    int arr1[] = { 0 , 3, 80, 6, 57, 10 };
    cout << jumpWithLeastCost(arr1, 6);
}



int jumpWithLeastCost(int* arr, int arrSize) {

    int* cache = new int[arrSize] {};
    int result = jumpWithLeastCost(cache, arr, arrSize - 1);
    delete[] cache;
    return result;
}



int jumpWithLeastCost(int* cache, int* arr, int position) {
    
    if (position <= 0) {
        return 0;
    }

    if (cache[position] == 0) {
        int least_cost_1_step_away = jumpWithLeastCost(cache, arr, position - 1);
        int least_cost_2_step_away = jumpWithLeastCost(cache, arr, position - 2);
        int least_cost_to_get_here = arr[position] + min(least_cost_1_step_away, least_cost_2_step_away);
        cache[position] = least_cost_to_get_here;
    }

    return cache[position];
}