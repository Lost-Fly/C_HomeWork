
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


class Clone {
public:

    void SetNumber(int value) {
        this->CloneNumber = value;
    }

    int GetNumber() {
        return this->CloneNumber;
    }

    void Learn(int value) {
        this->learnedprogramms.push(value);
    }

    void RollBack() {
        this->rollbackhistory.push(learnedprogramms.top());
        this->learnedprogramms.pop();
    }

    void Relearn() {
        this->learnedprogramms.push(rollbackhistory.top());
        this->rollbackhistory.pop();
    }

    void Check() {

        if (!learnedprogramms.empty()) {
            cout << learnedprogramms.top() << endl;
        }
        else {
            cout << "basic" << endl;
        }

    }

private:
    int CloneNumber = NULL;
    stack<int> learnedprogramms;
    stack<int> rollbackhistory;
};

void ReadString(string, string&, int&, int&);
void MakeCommand(string, int, int, vector<Clone>&);
void MakeCopy(Clone c, vector<Clone>&);

int main()
{

    int requestamount, programsamount;
    cin >> requestamount;
    cin >> programsamount;

    string temp, operation;
    int clonenum, prognum, opnum;

    vector<Clone> CVSorigin;

    Clone ZERO;
    CVSorigin.push_back(ZERO);

    Clone C_1;

    C_1.SetNumber(1);

    CVSorigin.push_back(C_1);

    for (int i = 0; i <= requestamount; i++) {
        getline(cin, temp);

        ReadString(temp, operation, clonenum, prognum);

        MakeCommand(operation, clonenum, prognum, CVSorigin);

    }

}

void ReadString(string line, string& operation, int& clonenum, int& prognum) {
    istringstream iss(line);
    int num1 = -1;
    int num2 = -1;
    string word;
    if (iss >> word) {
        if (iss >> num1) {
            if (iss >> num2) {
                operation = word;
                clonenum = num1;
                prognum = num2;
            }
            else {
                operation = word;
                clonenum = num1;
            }
        }
        else {
            operation = word;
        }
    }
}

void MakeCommand(string operation, int clonenum, int prognum, vector<Clone>& CVS) {

    if (operation == "learn") {
        CVS[clonenum].Learn(prognum);
    }
    else if (operation == "rollback") {
        CVS[clonenum].RollBack();
    }
    else if (operation == "relearn") {
        CVS[clonenum].Relearn();
    }
    else if (operation == "clone") {
        MakeCopy(CVS[clonenum], CVS);
    }
    else if (operation == "check") {
        CVS[clonenum].Check();
    }

}

void MakeCopy(Clone C, vector<Clone>& CVS) {
    Clone newC;
    newC = C;
    newC.SetNumber(C.GetNumber() + 1);
    CVS.push_back(newC);
}
