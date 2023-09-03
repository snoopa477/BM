#include <iostream>
#include <string>
#include <iomanip>      // std::setw

using namespace std;

void updateAlphabetToCounter(bool isAddition, string s, int alphabet_to_counter[], int size);
bool isAlphabet(char c);
char convertToSmallLetter(char c);
int convertSmallLetterToIndex(char c);
char convertIndexToSmallLetter(int index);

bool isAnagram(int alphabet_to_counter[], int size);

const int ALPHABET_SIZE = 26;
const int INDENTATION_SIZE = 3;

int main()
{
    cout << "Please enter a line of text: " << endl;
    string s1;
    getline(cin, s1);

    cout << "Please enter another line of text: " << endl;
    string s2;
    getline(cin, s2);

    int alphabet_to_counter[ALPHABET_SIZE] = {};

    updateAlphabetToCounter(true, s1, alphabet_to_counter, ALPHABET_SIZE);
    updateAlphabetToCounter(false, s2, alphabet_to_counter, ALPHABET_SIZE);

    cout << "'" << s1 << "' and '" << s2 << "' are"
        << (isAnagram(alphabet_to_counter, ALPHABET_SIZE) ? " " : " not " )
        << "anagrams" << endl;

}



void updateAlphabetToCounter(bool isAddition, string sentence, int alphabet_to_counter[], int size) {

    for (int i = 0; i < sentence.size(); i++) {

        if (isAlphabet(sentence[i])) {

            char small_letter = convertToSmallLetter(sentence[i]);
            int index = convertSmallLetterToIndex(small_letter);

            if (isAddition) {
                alphabet_to_counter[index]++;
            }
            else {
                alphabet_to_counter[index]--;
            }
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



bool isAnagram(int alphabet_to_counter[], int size) {

    for (int i = 0; i < size; i++) {
        if (alphabet_to_counter[i] != 0) {
            return false;
        }
    }

    return true;
}