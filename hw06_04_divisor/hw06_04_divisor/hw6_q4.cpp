#include <iostream>
/*
REFERENCE:
https://www.csie.ntu.edu.tw/~b01902011/material.php?type=cpp&&id=1
https://cplusplus.com/reference/stack/stack/
https://cplusplus.com/reference/stack/stack/pop/
*/
#include <stack>
#include <cmath>
using namespace std;


void printDivisors(int num);

int main()
{
    int number;
    cout << "Please enter a positive integer >= 2: ";
    cin >> number;

    printDivisors(number);

    return 0;
}



void printDivisors(int num) {

    stack<int> corresponding_divisors;
    /*
    * REFERENCE: 
    * https://www.programiz.com/cpp-programming/library-function/cmath/sqrt
    */
    
    double root_of_num = sqrt(num);


    /*
    * REASONING:
    * whenever you can find a divisor `X` that is smaller than `root_of_num`,
    * you can aslo find corresponding divisor, which is `num/X`, and is greater than `root_of_num`
    * Therefore, iteration within `root_of_num` would suffice
    */
    for (int i = 1; i < root_of_num; i++) {
        /* REASONING:
        * when the result of remainder of i is zero, it means `num` is divisible by `i`
        * , and `num / i` is the quotient
        * 
        * Besides, `num / i` is also a divisor as iterations go on...
        * However, we can store `num / i` in advance when `i`, so we can cut off the for loop at `root_of_num`
        */
        if (num % i == 0) {
            cout << i << " ";
            /*
            * REASONING:
            * `num / i`s are found descresingly, 
            * e.g. when num = 100
            * i = 1, num / i = 100
            * i = 2, num / i = 50
            * i = 4, num / i = 25
            * ...
            * 
            * But we want to print them ascendingly,
            * so we store them in stack, which is FILO
            */
            corresponding_divisors.push(num / i);
        }
    }


    while (!corresponding_divisors.empty()) {
        cout << corresponding_divisors.top() << " ";
        corresponding_divisors.pop();
    }

}