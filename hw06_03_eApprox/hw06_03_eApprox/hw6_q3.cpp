#include <iostream>

using namespace std;

//global variable
//https://openhome.cc/Gossip/CppGossip/Scope.html
double factorials[15 + 1];
double array_of_eApprox[15 + 1];

void set_factorials(int n);
double eApprox(int n);



int main()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }

    return 0;
}


//n! = (n-1)! * n
void set_factorials(int n) {

    if (n == 1) {
        factorials[1] = 1;
        return;
    }

    factorials[n] = factorials[n - 1] * n;
}



double eApprox(int n) {

    /* PURPOSE:
    * 1. calcualte factorial of n by using precomputed factorial of (n-1) and store the result to array
    * 2. calcualte eApprox of n by using precomputed eApprox of (n-1) and precomputed factorial of n and stores the result to array
    * 
    * we do so because eApprox of n is based on previous eApprox of (n-1) and factorial, we don't want to repeat the whole calculation process,
    * , which is already done before
    *
    * so we store both eApprox and factorial in array for future use.
    */

    //step1
    set_factorials(n);

    //step2
    if (n == 1) {
        array_of_eApprox[0] = 1;
    }
    array_of_eApprox[n] = array_of_eApprox[n - 1] + 1.0 / factorials[n];

    //get the result
    return array_of_eApprox[n];
}



