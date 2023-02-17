#include "Node.h"
BoxPtr DeleteBox(int idx, BoxPtr &Top) {
    BoxPtr pr, curr;
    pr = curr = Top;

    if (idx == Top->num) {
        Top = Top->prev;
        delete curr;
        return Top;
    }
    curr=pr->prev;
    
    while (curr!=nullptr) {          
        if (idx == curr->num) {
            pr->prev = curr->prev;
            delete curr;
            return Top;
        }
        pr = curr;
        curr = curr->prev;
    }
    
    return Top;
    
}

