#include <iostream>

using namespace std;

int fib(int number);


int main()
{
    int number = 1;
    cout << "Please	enter a positive integer: ";
    cin >> number;

    cout << fib(number);


    return 0;
}


//recursion
//https://www.programiz.com/cpp-programming/recursion
int fib(int number) {
    
    if (number == 1 || number == 2) {
        return 1;
    }

    int number_minus_one = number - 1;
    int number_minus_two = number - 2;

    int result = fib(number_minus_one) + fib(number_minus_two);
    return result;
}
