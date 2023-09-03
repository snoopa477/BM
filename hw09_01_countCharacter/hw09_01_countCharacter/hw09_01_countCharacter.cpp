#include <iostream>
#include <string>
#include <iomanip>      // std::setw

using namespace std;

void updateAlphabetToCounter(string s, int alphabet_to_counter[], int size);
bool isAlphabet(char c);
char convertToSmallLetter(char c);
int convertSmallLetterToIndex(char c);
char convertIndexToSmallLetter(int index);
void printAlphabetToCounter(int alphabet_to_counter[], int size);
int countWords(string s);
void printCountWords(string s);

const int ALPHABET_SIZE = 26;
const int INDENTATION_SIZE = 3;

int main()
{
    cout << "Please enter a line of text: " << endl;
    //https://ithelp.ithome.com.tw/articles/10292254
    string s;
    getline(cin, s);

    // ={}: intialize all elements value to 0
    int alphabet_to_counter[ALPHABET_SIZE] = {};

    updateAlphabetToCounter(s, alphabet_to_counter, ALPHABET_SIZE);

    printCountWords(s);
    printAlphabetToCounter(alphabet_to_counter, ALPHABET_SIZE);

}



void updateAlphabetToCounter(string sentence, int alphabet_to_counter[], int size) {

    for (int i = 0; i < sentence.size() ; i++) {

        if (isAlphabet(sentence[i])) {
            
            char small_letter = convertToSmallLetter(sentence[i]);
            int index = convertSmallLetterToIndex(small_letter);

            alphabet_to_counter[index]++;
        }
    }
}



bool isAlphabet(char c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}



char convertToSmallLetter(char c) {

    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }

    return c;
}



int convertSmallLetterToIndex(char c) {
    return c - 'a';
}



char convertIndexToSmallLetter(int index) {
    return index + 'a';
}



void printAlphabetToCounter(int alphabet_to_counter[], int size) {

    https://cplusplus.com/reference/iomanip/setw/
    for (int i = 0; i < size; i++) {
        if (alphabet_to_counter[i] != 0) {
            cout << setw(INDENTATION_SIZE) <<alphabet_to_counter[i] << setw(INDENTATION_SIZE)  << (char)(i + 'a') << endl;
        }
    }

}



int countWords(string s) {
    
    int count = 0;

    for (int i = 0; i < s.size(); i++) {

        if ( (i == 0 && isAlphabet(s[i]))
            || (i > 0 && isAlphabet(s[i]) && !isAlphabet(s[i-1]))) {
            count++;
        }

    }
    return count;
}


void printCountWords(string s) {

    cout << countWords(s) << " words" << endl;
}
