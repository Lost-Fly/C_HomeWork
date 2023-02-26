#pragma once

#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
//private:
public:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front ? true : false;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        int i;
        for (i = front; i != rear; i = ((i + 1) % MAX_SIZE) ) {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl;
    }

    void getPosition(int val) {
        if (isEmpty()) {
            cout << "Error: Queue is empty\n";
            return;
        }
        bool findEl = false;
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            if (arr[i] == val) {
                cout << "Position of your element in queue: " << i << endl;
                findEl = true;
                return;
            }
        }
        if (arr[i] == val) {
            cout << "Position of your element in queue: " << i << endl;
            findEl = true;
            return;
        }
        if (!findEl) {
            cout << "Error: Element has not found!\n";
            return;
        }
  
    }

};

void SortQueue(Queue&);
void DeleteElement(Queue&, int);

