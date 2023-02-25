#include "Node.h"

BoxPtr Init(int number) {
    BoxPtr Top = new Node;
    Top->num = number;
    Top->prev = nullptr;
    return Top;
}
