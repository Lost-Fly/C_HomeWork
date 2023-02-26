#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) {
        value = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void bubbleSort() {
        if (head == NULL) {
            return;
        }
        bool swapped = true;
        Node* ptr1;
        Node* lptr = NULL;
        while (swapped){
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->value > ptr1->next->value) {
                    swap(ptr1->value, ptr1->next->value);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
    }
};

int main() {
    LinkedList list;

    list.addNode(6);
    list.addNode(2);
    list.addNode(8);
    list.addNode(1);
    list.addNode(9);

    cout << "Before sorting:" << endl;
    list.printList();

    list.bubbleSort();

    cout << "After sorting:" << endl;
    list.printList();

    return 0;
}
