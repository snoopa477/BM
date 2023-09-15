#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string SPACE = " ";

string* createWordsArray(string sentence, int& outWordsArrSize);
int getFirstCharIndex(string sentence, int startIdx);
string* vectorToArray(vector<string> v);
void printArray(string* arr, int arrSize);

int main(){

    {
        string str1 = "You can do it";

        int outWordsArrSize = 0;
        string* tokens = createWordsArray(str1, outWordsArrSize);
        printArray(tokens, outWordsArrSize);
    }

    //case where multi spaces exists
    {
        string str1 = "  You   can do   it  ";

        int outWordsArrSize = 0;
        string* tokens = createWordsArray(str1, outWordsArrSize);
        printArray(tokens, outWordsArrSize);
    }


    {
        string str1 = "      ";

        int outWordsArrSize = 0;
        string* tokens = createWordsArray(str1, outWordsArrSize);
        printArray(tokens, outWordsArrSize);
    }


}



string* createWordsArray(string sentence, int& outWordsArrSize) {

    vector<string> tokens;
    int firstCharIdx = getFirstCharIndex(sentence, 0);
    //space index,following after first char index
    int spaceIdx = 0;

    //https://cplusplus.com/reference/string/string/find/
    //https://cplusplus.com/reference/string/string/npos/
    while ( ( spaceIdx = sentence.find(SPACE, firstCharIdx) ) != string::npos ) {

        //https://cplusplus.com/reference/string/string/substr/
        string token = sentence.substr(firstCharIdx, spaceIdx - firstCharIdx);
        //https://cplusplus.com/reference/vector/vector/push_back/
        tokens.push_back(token);

        /*REASONING: range from firstCharIdx to spaceIdx is done searching
        , now proceed to next unprocessed, which is firstCharIdx + 1
        */
        //prepare for next round
        firstCharIdx = getFirstCharIndex( sentence, spaceIdx + 1 );
    }

    /*REASONING: reaching here, meaning spaceIdx == string::npos
    , also meaning this is the last token, which has no following space
    */
    string token = sentence.substr(firstCharIdx, sentence.length() - firstCharIdx);
    tokens.push_back(token);

    outWordsArrSize = tokens.size();

    return vectorToArray(tokens);
}



int getFirstCharIndex(string sentence, int startIdx) {

    int firstCharIdx = startIdx;
    while (firstCharIdx < sentence.size() && sentence[firstCharIdx] == SPACE[0]) {
        firstCharIdx++;
    }

    return firstCharIdx;
}



//https://www.geeksforgeeks.org/diiferent-ways-to-convert-vector-to-array-in-cpp-stl/
string* vectorToArray(vector<string> v) {

    string* arr = new string[v.size()];

    //we adopt ranged based for loop
    //https://www.geeksforgeeks.org/range-based-loop-c/
    // other to consider
    //https://www.geeksforgeeks.org/iterators-c-stl/
    int i = 0;
    for (string element : v) {
        arr[i] = element;
        i++;
    }
    
    return arr;
}



void printArray(string* arr, int arrSize) {

    bool is_first = true;

    for (int i = 0; i < arrSize; i++) {
        cout <<  (is_first? "": ", ") << arr[i];
        is_first = false;
    }
    cout << endl;
}
