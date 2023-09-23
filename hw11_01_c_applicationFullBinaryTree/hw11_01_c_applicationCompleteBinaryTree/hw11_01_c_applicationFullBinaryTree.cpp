/*
Full Binary Tree
http://alrightchiu.github.io/SecondRound/binary-tree-introjian-jie.html
https://www.programiz.com/dsa/complete-binary-tree
https://web.ntnu.edu.tw/~algo/BinaryTree.html
*/

#include <iostream>
using namespace std;

void printRuler(int n);
void printInOrder(int idx, int current_layer_idx, int total_layers);
void printDash(int current_layer_idx, int total_layers);
int getLeftIdx(int idx);
int getRightIdx(int idx);
//not used, for completion purpose
int getParent(int idx);
//not used, for completion purpose
bool isRoot(int idx);
//not used, for completion purpose
bool isLeaf(int idx, int totalLayers);
bool isOutOfTree(int idx, int totalLayers);


int main()
{
    cout << "printRuler(1)" << endl;
    printRuler(1);

    cout << "printRuler(2)" << endl;
    printRuler(2);

    cout << "printRuler(3)" << endl;
    printRuler(3);

    cout << "printRuler(4)" << endl;
    printRuler(4);

    cout << "printRuler(5)" << endl;
    printRuler(5);
}



void printRuler(int n) {
    //root is at index 1, with 0th layer
    printInOrder(1, 0, n);
}



void printInOrder(int idx, int current_layer_idx, int total_layers) {

    if (isOutOfTree(idx, total_layers)) {
        return;
    }
    
    int left_child_idx = getLeftIdx(idx);
    printInOrder(left_child_idx, current_layer_idx + 1, total_layers);

    printDash(current_layer_idx, total_layers);

    int right_child_idx = getRightIdx(idx);
    printInOrder(right_child_idx, current_layer_idx + 1, total_layers);
}



void printDash(int current_layer_idx, int total_layers) {
    int number_dashes = total_layers - current_layer_idx;
    for (int i = 0; i < number_dashes; i++) {
        cout << "-";
    }
    cout << endl;
}



int getLeftIdx(int idx) {
    return idx * 2;
}



int getRightIdx(int idx) {
    return idx * 2 + 1;
}



int getParent(int idx) {
    return idx / 2;
}



bool isRoot(int idx) {
    return idx == 1;
}



bool isLeaf(int idx, int totalLayers) {
    return (1 << (totalLayers - 1)) <= idx && idx < (1 << totalLayers);
}



bool isOutOfTree(int idx, int totalLayers) {
    return idx >= (1 << totalLayers);
}