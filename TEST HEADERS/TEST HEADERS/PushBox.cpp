#include "Node.h"

void PushBox(BoxPtr el, BoxPtr &Top) {
    el->prev = Top;
    Top = el;
}
