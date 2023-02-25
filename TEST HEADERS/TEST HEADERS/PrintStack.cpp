#include "Node.h"
#include <iostream>

using namespace std;

void PrintStack(BoxPtr Top)
{
    while (Top != nullptr) {
        cout << Top->num << ' ';
        Top = Top->prev;
    }
    cout << endl;
}