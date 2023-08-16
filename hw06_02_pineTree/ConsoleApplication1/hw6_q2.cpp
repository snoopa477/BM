#include <iostream>
//https://ithelp.ithome.com.tw/articles/10276673
#include <string>
using namespace std;

//C++ Function Declaration
//https://www.programiz.com/cpp-programming/function
void printShiftedTriangle(int layers, int left_spaces, char symbol);
void printSymbols(int frequency, char symbol);
void printPineTree(int n, char symbol);



int main()
{
    const string str_end_of_program = "end";
    string user_input = "";

    int layers;
    char symbol;

    cout << "To end the program, type `end`"<<endl;

    while (true) {
        cout << "number of layers of a pineTree: ";
        cin >> user_input;
        if ( user_input.compare(str_end_of_program) == 0) {
            break;
        }

        //string to integer, stoi, acronym for "string to integer"
        //https://www.scaler.com/topics/string-to-int-in-cpp/
        //https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
        layers = stoi(user_input);


        cout << "symbol that construcs a pine tree: ";
        cin >> user_input;
        //https://www.digitalocean.com/community/tutorials/compare-strings-in-c-plus-plus
        if (user_input.compare(str_end_of_program) == 0) {
            break;
        }

        symbol = user_input[0];

        printPineTree(layers, symbol);
    }
}



void printShiftedTriangle(int layers, int left_spaces, char symbol) {

    for (int i = 0; i < layers; i++) {

        printSymbols(left_spaces, ' ');
        printSymbols(layers - 1 - i, ' ');
        printSymbols(i * 2 + 1, symbol);

        cout << endl;
    }
}



void printSymbols(int frequency, char symbol) {
    for (int i = 0; i < frequency; i++) {
        printf("%c", symbol);
    }
}



void printPineTree(int n, char symbol) {

    for (int i = 0; i < n; i++) {
        printShiftedTriangle(2 + i, n - 1 - i, symbol);
    }
}