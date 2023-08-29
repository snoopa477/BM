#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits.h>

using namespace std;

vector<string>  getTokens(string input);


int main()
{
    string user_input;
    cout << "enter your name in the following format: First_Name Middle_Initial Last_Name:" << endl;
    getline(cin, user_input);

    vector<string> tokens = getTokens(user_input);
    cout << "\nname in the format--Last_Name, First_Nmae Middle_Initial-- is shown:" << endl;
    cout << tokens[2] << ", " << tokens[0] << " " << tokens[1] << endl;

}


//see hw08_01_minValue
vector<string>  getTokens(string input) {

    //https://cplusplus.com/reference/vector/vector/push_back/
    vector<string> tokens;

    //https://cplusplus.com/reference/sstream/stringstream/stringstream/
    stringstream ss(input);

    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}