
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
//https://www.javatpoint.com/how-to-generate-random-number-between-1-to-10-in-cpp
int getRandNumber1to3();
void assignRandNumber1to3(int arr[], int arrSize);
void printMessageOfPinToRand(int arr[], int arrSize);
string getAuthenticationStr(string PIN, int pin_to_rand[]);

const string PIN = "20238";
const int SIZE = 10;

int main()
{
    // Initialize random number generator.
    srand(time(0));  

    cout << "Please enter your PIN according to the following mapping: \n";
    int pin_to_rand[SIZE];
    assignRandNumber1to3(pin_to_rand, SIZE);
    printMessageOfPinToRand(pin_to_rand, SIZE);

    string authentication_str = getAuthenticationStr(PIN, pin_to_rand);

    //for debug purpose
    //cout << authentication_str << endl;

    string user_input;
    cin >> user_input;

    https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus
    if (user_input.compare(authentication_str) == 0) {
        cout << "Your PIN is correct\n";
    }
    else {
        cout << "Your PIN is NOT correct\n";
    }

    return 0;
}



int getRandNumber1to3() {
    //https://www.javatpoint.com/how-to-generate-random-number-between-1-to-10-in-cpp
    return  (rand() % 3) + 1;
}



void assignRandNumber1to3(int arr[], int arrSize) {

    for (int i = 0; i < arrSize; i++) {
        arr[i] = getRandNumber1to3();
    }
}



void printMessageOfPinToRand(int arr[], int arrSize) {

    printf("%-10s:", "PIN");
    for (int i = 0; i < arrSize; i++) {
        printf("%2d", i);
    }
    printf("\n");

    //https://stackoverflow.com/questions/2485963/c-alignment-when-printing-cout
    printf("%-10s:", "NUM");
    for (int i = 0; i < arrSize; i++) {
        printf("%2d", arr[i]);
    }
    printf("\n");
}



string getAuthenticationStr(string PIN, int pin_to_rand[]) {

    string authentication_str;
    for (int i = 0; i < PIN.length(); i++) {
        //https://sentry.io/answers/char-to-int-in-c-and-cpp/
        int rand_digit = pin_to_rand[PIN[i] - '0'];
        //https://stackoverflow.com/questions/5590381/how-to-convert-int-to-string-in-c
        authentication_str += to_string(rand_digit);
    }
    return authentication_str;
}

