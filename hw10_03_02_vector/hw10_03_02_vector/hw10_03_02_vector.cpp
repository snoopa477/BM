#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getNumbersFromUserInput();
void findAndPrint(string key, vector<string> sequence_nums);

const string END_OF_INPUT = "-1";
const string SPACE = " ";


int main(){

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl
        << "End you input by typing -1" << endl;

    vector<string> sequence_nums = getNumbersFromUserInput();

    cout << "Please enter a number you want to search." << endl;

    string key;
    cin >> key;

    findAndPrint(key, sequence_nums);
}



vector<string> getNumbersFromUserInput() {
    vector<string> sequence;

    string input;
    while (true) {

        cin >> input;

        if (input.compare(END_OF_INPUT) == 0) {
            break;
        }

        sequence.push_back(input);
    }

    return sequence;
}



void findAndPrint(string key, vector<string> sequence_nums) {

    cout << key << " shows in lines ";
    bool first_found = true;

    for (int i = 0; i < sequence_nums.size(); i++) {
        if (key.compare(sequence_nums[i]) == 0) {
            cout << (first_found ? " " : ", ") << i;
            first_found = false;
        }
    }

    cout << "." << endl;
}
