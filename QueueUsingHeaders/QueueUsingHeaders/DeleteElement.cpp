#include "Queue.h"

void DeleteElement(Queue &q, int value) {

    if (q.isEmpty()) {
        cout << "Error: Queue is empty\n";
        return;
    }
    bool findEl = false;
    int i;
    int pos;
    for (i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE) {
        if (q.arr[i] == value) {
            pos = i;
            findEl = true;
        }
    }
    if (q.arr[i] == value) {
        pos = i;
        findEl = true;

    }
    if (!findEl) {
        cout << "Error: Element has not found!\n";
        return;
    }

    if (pos == q.front) {
        q.dequeue();
    }
    else if (pos == q.rear) {
        q.rear = (q.rear - 1) % MAX_SIZE;
    }
    else {
        for (int j = pos; j != q.rear ;  j = (j + 1) % MAX_SIZE) {
            q.arr[j] = q.arr[j+1];
        }

        q.rear = (q.rear - 1) % MAX_SIZE;

    }


}