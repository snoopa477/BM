#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string input;
    cout << "Please enter a word: ";
    cin >> input;
    
    cout << input << " is " << (isPalindrome(input) ? "" : "not ") << "palindrome" << endl;

}



//https://cplusplus.com/reference/string/string/
//https://openhome.cc/Gossip/CppGossip/string2.html
bool isPalindrome(string str) {

    //start with last index: str.length() - 1
    int right_index = str.length() - 1;
    
    int left_index = 0;

    //assum it's true, until there is situation that viloates the rule of palindrome
    while (left_index < right_index) {

        if (str[left_index] != str[right_index]) {
            return false;
        }

        left_index++;
        right_index--;
    }

    //reaching here means all situation satisfiy the rule of palindrome
    return true;
}