#include <iostream>
#include <string>

using namespace std;

string getNumbersFromUserInput();
void findAndPrint(string key, string sequence_nums);
int getFirstCharIndex(string sentence, int startIdx);

const string END_OF_INPUT = "-1";
const string SPACE = " ";


int main()
{
    cout << "Please enter a sequence of positive integers, each in a separate line." <<endl
    <<"End you input by typing -1"<<endl;

    string sequence_nums = getNumbersFromUserInput();

    //for debug purpose
    //cout << sequenceOfNums;

    cout << "Please enter a number you want to search." << endl;

    string key;
    cin >> key;

    findAndPrint(key, sequence_nums);
}



string getNumbersFromUserInput() {

    string sequence = "";

    string input;
    while (true) {

        cin >> input;

        if (input.compare(END_OF_INPUT) == 0) {
            break;
        }

        //https://cplusplus.com/reference/string/string/append/
        sequence.append(SPACE);
        sequence.append(input);
    }

    return sequence;
}



//REFERENCE: hw10_01_StrTokens
void findAndPrint(string key, string sequence_nums) {

    cout << key << " shows in lines ";

    int firstCharIdx = getFirstCharIndex(sequence_nums, 0);
    //space index,following after first char index
    int spaceIdx = 0;

    //it is also line number
    int token_counter = 1;
    bool first_found = true;
    while ((spaceIdx = sequence_nums.find(SPACE, firstCharIdx)) != string::npos) {

        string token_number = sequence_nums.substr(firstCharIdx, spaceIdx - firstCharIdx);

        if (key.compare(token_number) == 0) {
            cout << (first_found ? " " : ", ") << token_counter;
            first_found = false;
        }

        //prepare for next round
        firstCharIdx = getFirstCharIndex(sequence_nums, spaceIdx + 1);
        token_counter++;
    }

    /*REASONING: reaching here, meaning spaceIdx == string::npos
    , also meaning this is the last token, which has no following space
    */
    string token_number = sequence_nums.substr(firstCharIdx, sequence_nums.length() - firstCharIdx);
    if (key.compare(token_number) == 0) {
        cout << (first_found ? " " : ", ") << token_counter;
    }

    cout << "." << endl;
}



int getFirstCharIndex(string sentence, int startIdx) {

    int firstCharIdx = startIdx;
    while (firstCharIdx < sentence.size() && sentence[firstCharIdx] == SPACE[0]) {
        firstCharIdx++;
    }

    return firstCharIdx;

}