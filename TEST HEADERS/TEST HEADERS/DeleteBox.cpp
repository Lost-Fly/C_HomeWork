#include "Node.h"
void DeleteBox(int idx, BoxPtr &Top) {
    BoxPtr pr, curr;
    pr = curr = Top;

    if (idx == Top->num) {
        Top = Top->prev;
    }
    else {
        curr = pr->prev;
        while (curr != nullptr) {
            if (idx == curr->num) {
                pr->prev = curr->prev;
            }
            pr = curr;
            curr = curr->prev;
        }
    }
    delete curr;
}

