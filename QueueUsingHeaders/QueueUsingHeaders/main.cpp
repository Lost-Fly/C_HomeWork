#include "Queue.h"

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue: ";
    q.display();

    cout << "Dequeue: ";
    q.dequeue();
    q.display();

    cout << "Peek: " << q.peek() << endl;

    cout << "Enqueue: ";
    q.enqueue(1);
    q.display();

    cout << "GetPosition: ";
    q.getPosition(1);

    cout << "Delete: ";
    DeleteElement(q, 3);
    q.display();

    cout << "Sort: ";
    SortQueue(q);
    q.display();


    return 0;
}
