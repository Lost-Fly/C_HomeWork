#include <iostream>
#include <string>
#include <stack>

using namespace std;

int SetPriority(char c) {
    int p;
    switch (c)
    {
    case '(':
        p = 0;
    case ')':
        p = 1;
    case '+':
    case '-':
        p = 5;
        break;
    case '*':
    case '/':
        p = 4;
        break;
    case '^':
        p = 2;
        break;
    default:
        break;
    }
    return p;
}



int main() {
    stack<char> stk;
    cout << "Enter your equation " << endl;
    string q, w, tmp;
    cin >> q;
    for (int i = 0; i < q.length(); i++) {
        cout << q[i] << "\n";
        if (!isdigit(q[i])) {
            if (stk.empty()) {
                stk.push(q[i]);
            }
            else if ((SetPriority(q[i]) >= SetPriority(stk.top()))) {
                if (q[i] == ')') {
                    while (stk.top() != '(') {
                        w += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                else {
                    stk.push(q[i]);
                }
            }
            else {
                while (!stk.empty()) {
                    w += stk.top();
                    stk.pop();
                }
                stk.push(q[i]);
            }
        }
        else {
            w += q[i];
            cout << w << endl;
        }
    }
    while (!stk.empty()) {
        w += stk.top();
        stk.pop();
    }
    cout << w << endl;

    return 0;
}