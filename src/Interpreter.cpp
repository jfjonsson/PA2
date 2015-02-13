#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

void error_msg (string msg) {
    cout << "Error: " << msg << endl;
    exit(0);
}

int main () {
    map<string, int> mp;
    stack<string> stk;
    string in, ID;
    int VALUE, a(0), b(0);
    
    while (cin >> in) {
        if(in == "PUSH") {
            if(cin >> in) {
                stk.push(in);
            } else {
                error_msg("Missing argument!"); 
            }
        } else if (in == "PRINT") {
            if(mp.count(stk.top())) {
                cout << mp[stk.top()] << endl;
            } else {
                cout << stk.top();
            }
            stk.pop();
        } else if (in == "ADD") {
            if(mp.count(stk.top())) {
                a = mp[stk.top()];
            } else {
                a = stoi(stk.top());
            }
            stk.pop();
            if(mp.count(stk.top())) {
                b = mp[stk.top()];
            } else {
                b = stoi(stk.top());
            }
            stk.pop();
            b += a;
            stk.push(std::to_string((long long)b));
        } else if (in == "SUB") {
            if(mp.count(stk.top())) {
                a = mp[stk.top()];
            } else {
                a = stoi(stk.top());
            }
            stk.pop();
            if(mp.count(stk.top())) {
                b = mp[stk.top()];
            } else {
                b = stoi(stk.top());
            }
            stk.pop();
            b -= a;
            stk.push(to_string((long long)b));
        } else if (in == "MULT") {
            if(mp.count(stk.top())) {
                a = mp[stk.top()];
            } else {
                a = stoi(stk.top());
            }
            stk.pop();
            if(mp.count(stk.top())) {
                b = mp[stk.top()];
            } else {
                b = stoi(stk.top());
            }
            stk.pop();
            b *= a;
            stk.push(to_string((long long)b));
        } else if (in == "ASSIGN") {
            if(mp.count(stk.top())) {
                VALUE = mp[stk.top()];
            } else {
                VALUE = stoi(stk.top());
            }
            stk.pop();
            ID = stk.top();
            stk.pop();
            mp.insert(make_pair(ID, VALUE));
        } else {
            error_msg("Wrong command!");
        }
    }
}


