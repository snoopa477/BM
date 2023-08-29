#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits.h>

using namespace std;

vector<string>  getTokens(string input);
bool isAllDigits(string str);
string genMasks(int num);
void printMaskedSentence(vector<string> tokens);

int main(){

    string user_input;
    cout << "Please enter a line of text: \n";
    getline(cin, user_input);

    vector<string> tokens = getTokens(user_input);

    printMaskedSentence(tokens);

}


//see hw08_01_minValue
vector<string>  getTokens(string input) {

    //https://cplusplus.com/reference/vector/vector/push_back/
    vector<string> tokens;

    //https://cplusplus.com/reference/sstream/stringstream/stringstream/
    stringstream ss(input);

    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back( token );
    }
    return tokens;
}


//https://www.programiz.com/cpp-programming/library-function/cctype/isdigit#google_vignette
bool isAllDigits(string str) {
    
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }

    return true;
}



string maskNumbers(string str) {

    if (isAllDigits(str)) {
        return genMasks(str.length());
    }
    return str;
}


string genMasks(int num) {

    string s ="";
    for (int i = 0; i < num; i++) {
        s += "x";
    }
    return s;

}



void printMaskedSentence(vector<string> tokens) {

    for (int i = 0; i < tokens.size(); i++) {

        //https://cplusplus.com/reference/vector/vector/operator[]/
        cout << maskNumbers(tokens[i]) << " ";

    }
    cout << endl;
}