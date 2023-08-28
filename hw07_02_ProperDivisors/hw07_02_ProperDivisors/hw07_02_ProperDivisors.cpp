
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);


int main()
{
  
    string user_input = "";
    cout << "enter the number: ";
    cin >> user_input;
    cout << endl;

    int number_m = stoi(user_input);
    int size = number_m + 1;


    cout << "All the perfect numbers between 2 and " << number_m << endl;
    bool is_first = true;
    for (int i = 2; i < size; i++) {
        if ( isPerfect(i) ) {
            cout << (is_first? "" : ", ") << i;
            
            if (is_first) {
                is_first = false;
            }
        }
    }

    cout << endl << endl;


    cout << "pairs of amicable numbers that are between 2 and " << number_m << endl;
    for (int i = 2; i < size; i++) {
        
        int outCountDivs = 0, outSumDivs = 0;
        analyzeDividors(i, outCountDivs, outSumDivs);

        int potential_amicable_num = outSumDivs;
        if (potential_amicable_num < size) {

            int pam_outCountDivs = 0, pam_outSumDivs = 0;
            analyzeDividors(potential_amicable_num, pam_outCountDivs, pam_outSumDivs);

            if (pam_outSumDivs == i
                //exclude perfect number from amicable numbers
                && potential_amicable_num != i
                //avoid dpulicates: (220, 284) and (284, 220) are the same in the sense of pair
                && i < potential_amicable_num) {
                cout << "( " << i << ", " << potential_amicable_num << " )" << endl;
            }
        }
        

    }
    cout << endl;

}



void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {


    outCountDivs = 0;
    outSumDivs = 0;

    double root_of_num = sqrt(num);

    for (int i = 1; i <= root_of_num; i++) {

        if (num % i == 0) {

            int corresponding_divisor = num / i;

            if (corresponding_divisor != i) {
                outCountDivs += 2;
                outSumDivs += (i + corresponding_divisor);
            }
        }
    }

    //exclude num itself from those vars
    outCountDivs--;
    outSumDivs -= num;
}



bool isPerfect(int num) {

    int outCountDivs = 0, outSumDivs = 0;
    analyzeDividors(num, outCountDivs, outSumDivs);
    return num == outSumDivs;

}