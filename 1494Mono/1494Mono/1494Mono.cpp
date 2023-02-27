#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int amount;
    cin >> amount;

    queue<int> takenballs;

    int tempball;
    for (int i = 0; i < amount; i++) {
        cin >> tempball;
        takenballs.push(tempball);
    }

    stack<int> s1;

    for (int i = 1; i <= amount; i++) {
        s1.push(i);
        
        while ( (!s1.empty() && !takenballs.empty()) && (takenballs.front() == s1.top()) ) {
            s1.pop();
            takenballs.pop();
        }
        
    }

    if (s1.empty()) {
        cout << "Not a proof" << endl;
    }
    else {
        cout << "Cheater" << endl;
    }
}