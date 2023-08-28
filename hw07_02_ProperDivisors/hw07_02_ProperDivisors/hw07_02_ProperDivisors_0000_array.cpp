
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

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

    vector<int> num_to_sumDivs;
    vector<bool> num_to_isPerfect;

    for (int i = 0; i < size; i++) {

        if (i < 2) {
            num_to_sumDivs.push_back(-1);
            num_to_isPerfect.push_back(false);
            continue;
        }

        int outCountDivs = 0, outSumDivs = 0;
        analyzeDividors(i, outCountDivs, outSumDivs);

        num_to_sumDivs.push_back(outSumDivs);
        num_to_isPerfect.push_back( isPerfect(i) );
    }


    cout << "All the perfect numbers between 2 and " << number_m << endl;
    bool is_first = true;
    for (int i = 0; i < num_to_isPerfect.size(); i++) {
        if (num_to_isPerfect[i]) {
            cout << (is_first? "" : ", ") << i;
            
            if (is_first) {
                is_first = false;
            }
        }
    }

    cout << endl << endl;


    cout << "pairs of amicable numbers that are between 2 and " << number_m << endl;
    for (int i = 0; i < num_to_sumDivs.size(); i++) {
        
        int potential_amicable_num = num_to_sumDivs[i];
        if (potential_amicable_num >= 2 && potential_amicable_num < num_to_sumDivs.size()) {

            if (num_to_sumDivs[potential_amicable_num] == i 
                //exclude perfect number from amicable numbers
                && potential_amicable_num != i
                //remove dpulicates
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