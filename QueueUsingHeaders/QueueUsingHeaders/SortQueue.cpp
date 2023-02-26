#include "Queue.h"

int partitionQueue(Queue&, int, int);
void quickSortQueue(Queue&, int, int);

void quickSortQueue(Queue& q, int front, int rear) {
    if (front < rear) {
        int pivot = partitionQueue(q, front, rear);
        quickSortQueue(q, front, pivot - 1);
        quickSortQueue(q, pivot + 1, rear);
    }
}

int partitionQueue(Queue& q, int front, int rear) {
    int pivot = q.arr[rear];
    int i = front - 1;
    for (int j = front; j < rear; j++) {
        if (q.arr[j] < pivot) {
            i++;
            swap(q.arr[i], q.arr[j]);
        }
    }
    swap(q.arr[i + 1], q.arr[rear]);
    return i + 1;
}


void SortQueue(Queue& q) {
    if (q.isEmpty()) {
        cout << "Error: Queue is empty\n";
        return;
    }
    quickSortQueue(q, q.front, q.rear);
}
