#include <iostream>
using namespace std;

struct tnode {
    int field;           // поле данных
    tnode* left;  // левый потомок
    tnode* right; // правый потомок
};

void RightTreePrint(tnode* tree) {
    if (tree != nullptr) { //Пока не встретится пустой узел
        RightTreePrint(tree->right); //Рекурсивная функция для правого поддерева
        RightTreePrint(tree->left); //Рекурсивная функция для левого поддерева
        cout << tree->field << endl; //Отображаем корень дерева
    }
}

tnode* addnode(int x, tnode* tree) {
    if (tree == nullptr) { // Если дерева нет, то формируем корень
        tree = new tnode; // память под узел
        tree->field = x;   // поле данных
        tree->left = nullptr;
        tree->right = nullptr; // ветви инициализируем пустотой
    }
    else  if (x < tree->field)   // условие добавление левого потомка
        tree->left = addnode(x, tree->left);
    else    // условие добавление правого потомка
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

