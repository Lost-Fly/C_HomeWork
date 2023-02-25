#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

int main() {
    setlocale(LC_ALL, "Ru");
    Queue q;
    int n;
    cout << "Введите количество элементов в массиве:" << endl;
    cin >> n;

    /*q.push(1);
    q.push(2);
    q.push(3);*/

    for (int i = 0; i < n; i++) {
        q.push(i);
        cout << q.pop() << ' ';
    }

    cout << endl;
    //cout << q.pop() << endl; // Output: 1
    //cout << q.pop() << endl; // Output: 2
    //cout << q.pop() << endl; // Output: 3

    for (int i = 0; i < n; i++) {
        cout << q.pop() << ' ';
    }


    return 0;
}