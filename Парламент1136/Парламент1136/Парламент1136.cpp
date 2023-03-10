#include <iostream>
using namespace std;

struct tnode {
    int field;          
    tnode* left;  
    tnode* right; 
};

void RightTreePrint(tnode* tree) {
    if (tree != nullptr) {
        RightTreePrint(tree->right); 
        RightTreePrint(tree->left); 
        cout << tree->field << endl; 
    }
}

tnode* addnode(int x, tnode* tree) {
    if (tree == nullptr) { 
        tree = new tnode; 
        tree->field = x;   
        tree->left = nullptr;
        tree->right = nullptr; 
    }
    else  if (x < tree->field)   
        tree->left = addnode(x, tree->left);
    else    
        tree->right = addnode(x, tree->right);
    return(tree);
}


int main() {
    int size;
    cin >> size;
    tnode* Tree = nullptr;
    int* Array = new int[size];

    for (int i = 0; i < size; ++i) {
        cin >> Array[i];
    }

    for (int i = size - 1; i >= 0; i--) {
        Tree = addnode(Array[i], Tree);
    }

    RightTreePrint(Tree);

    return 0;
}

