#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> Dels(int n) {
    vector <int> res;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            //res += to_string(n / i);
        }
    }

    return res;
}

bool CanDoPhrase(string s) {
    bool flag = false;

    string langcount ="";
    int unkcount = 0;
    for (int i = 0; i <= s.length()-4; i+=4) {
        if (s.substr(i, 4) != "unkn") {
            if ( langcount.find(s.substr(i, 4)) > langcount.length() ) {
                langcount += s.substr(i, 4);
            }
        }
        if (s.substr(i, 4) == "unkn") {
            unkcount += 1;
        }
        
    }

    if (langcount.length() == 4 || s.length() == 4 || s.length()==unkcount*4) {
        flag = true;
    }

    return flag;
}

string Language(string s) {
    string lang;
    int unkcount = 0;
    for (int i = 0; i <= s.length() - 4; i += 4) {
        if (s.substr(i, 4) != "unkn") {   
            if (lang.find(s.substr(i, 4)) > lang.length()) {
                lang += s.substr(i, 4);
                break;
            }
        }
        if (s.substr(i, 4) == "unkn") {
            unkcount += 1;
        }

    }

    if (s.length() == unkcount * 4) {
        return "unkn";
    }

    return lang;
}

bool CheckString(int ncountt,int num, string s) {
    bool flag = false;
    int n = ncountt/num;
    int count =0;
    int f = 0;
    string tempstr, tmp2;
    for (int i = 0; i <= s.length() - n*4; i += n*4) {
        tempstr = s.substr(i, 4*n);
        if (CanDoPhrase(tempstr)) {
            if (    ( (tmp2.find(Language(tempstr)) > tmp2.length() || tmp2.find(Language(tempstr)) < 0) && Language(tempstr) != "unkn") || Language(tempstr) == "unkn") {
                if (Language(tempstr) != "unkn") {
                    tmp2 += Language(tempstr);
                }
                count++;
            }
            else if (Language(tempstr) != "unkn") {
                f = 1;           
            }
        }
    }

    if (n == ncountt && tmp2.length() != 4) {
        return false;
    }

    if (count * n == ncountt && f !=1) {
        flag = true;
    }

    return flag;
}

int main()
{
    int n;
    cin >> n;

    string tempstr, strlang2, ans, strlang;
    int unknown = 0;
    int stopflag = 0;

    strlang = "";
    for (int i = 0; i < n; i++) {
        tempstr = "";
        cin >> tempstr;
        strlang2 += tempstr.substr(0, 4);

        if ( ( ( strlang.find(tempstr.substr(0, 4)) > strlang.length()) && (tempstr!="unknown")) || (tempstr == "unknown") ) {
            strlang += tempstr.substr(0, 4);
        }
        else {           
            stopflag = 1;
        }
        if (tempstr == "unknown") {
            unknown += 1;
        }
 
    }

    if (unknown * 4 == strlang2.length()) {
        ans = "";
        vector <int> dels = Dels(n);
        for(int i =0; i < dels.size(); i++){
            ans += to_string(dels[i]);
        }      
    }
    else if (n % 2 != 0) {
        if (CanDoPhrase(strlang2)) {
            ans = "1";
        }
        else if (CheckString(n, 1, strlang2)) {
            ans = to_string(n);
        }
    }
    else {
        vector <int> dels = Dels(n);
        ans = "";
        for (int i = 0; i < dels.size(); i++) {
            if (CheckString(n,dels[i], strlang2)) {
                ans += to_string(dels[i]);
            }
        }
    }

    if (stopflag == 1 && ans == "") {
        cout << "Igor is wrong." << endl;
    }


    for (int i = 0; i < ans.length(); i++) {
        cout << ans[i];
        if (i < ans.length() - 1) {
            cout << ' ';
        }
    }

    //tests
    //cout << ' ' << endl;
    //cout << " " << endl;
    //cout << strlang2 << endl;
    //cout << unknown << endl;
    //cout << strlang.find("engl") / 4 << endl;
    //cout << strlang.substr(0,12)  << endl;
    //cout << strlang.substr(12,24)  << endl;


}

