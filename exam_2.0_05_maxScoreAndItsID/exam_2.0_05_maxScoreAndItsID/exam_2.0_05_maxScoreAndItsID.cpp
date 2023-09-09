#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void initialPromptMessage();
void promptMessage();
bool readIdAndScore(int& id, int& score);
void updateScoresToIds(vector<int> scores_to_IDs[], int id, int score);

//this is not good, since this function serves two purpoes: find max and print. Better split 2 tasks into 2 functions
//void printHighestScoreAndItsIds(vector<int> scores_to_IDs[], int size);
int findHighestScore(vector<int> scores_to_IDs[], int size);
void printScoreAndItsIds(vector<int> scores_to_IDs[], int score);

void printVector(vector<int> v);


const int ALL_SCORES = 101;
const char WHITE_SPACE = ' ';
const string END_OF_INPUT = "-1";


int main()
{
    https://www.geeksforgeeks.org/array-of-vectors-in-c-stl/
    vector<int> scores_to_IDs[ALL_SCORES];
    
    int id = 0;
    int score = 0;
    initialPromptMessage();
    while (readIdAndScore(id, score)) {

        updateScoresToIds(scores_to_IDs, id, score);
        promptMessage();
    };

    int highest_core = findHighestScore(scores_to_IDs, ALL_SCORES);
    printScoreAndItsIds(scores_to_IDs, highest_core);

    //free the unused memory
    delete[] scores_to_IDs;
}



void initialPromptMessage() {
    //https://www.geeksforgeeks.org/printing-output-in-multiple-lines-in-cpp/
    cout << "Please enter a non-empty sequence of lines." << endl
    << "Each line should have a student ID and their grade(0 - 100), separated by a space." << endl
    << "To indicate the end of the input, enter - 1 as a student ID : " << endl;
}



void promptMessage() {
    cout << "Please enter a non-empty sequence of lines." << endl;
}



bool readIdAndScore(int& id, int& score) {

    //adopt this
    //https://cplusplus.com/reference/sstream/stringstream/stringstream/
    
    //in this scenario we don't adopt this reference, because input not always come with two tokens, separted with one white space
    //https://stackoverflow.com/questions/5738882/read-input-separated-by-whitespaces-or-newline

    string user_input;
    getline(cin, user_input);
    stringstream ss(user_input);

    string token;

    int max_num_tokens = 2;
    int i = 0;
    while (getline(ss, token, WHITE_SPACE) && i < max_num_tokens) {
        
        if (token.compare(END_OF_INPUT) == 0) {
            return false;
        }

        switch ( i )
        {
            case 0:
                id = stoi(token);
            break;
            case 1 :
                score = stoi(token);
            default:
            break;
        }

        i++;
    }

    return true;
}



void updateScoresToIds(vector<int> scores_to_IDs[], int id, int score) {
    //https://www.programiz.com/cpp-programming/list
    scores_to_IDs[score].push_back(id);
}



int findHighestScore(vector<int> scores_to_IDs[], int size){

    //REASONING: the first encountering with vector with size non-zero has highest score
    //and then we quit iterating
    for (int score = ALL_SCORES - 1; score >= 0; score--) {
        if (scores_to_IDs[score].size() != 0) {
            return score;
        }
    }

}



void printScoreAndItsIds(vector<int> scores_to_IDs[], int score) {
    cout << "The highest grade is " << score << endl;
    cout << "The students with grade " << score << " are ";
    printVector(scores_to_IDs[score]);
    cout << "." << endl;
}



//https://stackoverflow.com/questions/10750057/how-do-i-print-out-the-contents-of-a-vector
void printVector(vector<int> v) {

    for (int num : v) {
        cout << num << ' ';
    }
}