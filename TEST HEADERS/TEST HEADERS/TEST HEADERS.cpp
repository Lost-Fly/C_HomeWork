//Node source

#include "Node.h"
using namespace std;

int main() {
    BoxPtr Top = nullptr;


    int n = 15;
    int k = 2;
    for (int i = 0; i < n; i++) {
        PushBox(Init(i), Top);
    }
    PrintStack(Top);

    DeleteBox(k, Top);

    PrintStack(Top);
}

