#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

void error_msg (string msg) {
    cout << "Error: " << msg << endl;
    exit(0);
}

int get_value (map<string, int> mp, stack<string> stk) {
    if(mp.count(stk.top())) {
        return mp[stk.top()];
    } else {
        return stoi(stk.top());
    }
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
            cout << get_value(mp, stk) << endl;
            stk.pop();
        } else if (in == "ADD") {
            a = get_value(mp, stk);
            stk.pop();
            b = get_value(mp, stk);
            stk.pop();
            b += a;
            stk.push(std::to_string((long long)b));
        } else if (in == "SUB") {
            a = get_value(mp, stk);
            stk.pop();
            b = get_value(mp, stk);
            stk.pop();
            b -= a;
            stk.push(to_string((long long)b));
        } else if (in == "MULT") {
            a = get_value(mp, stk);
            stk.pop();
            b = get_value(mp, stk);
            stk.pop();
            b *= a;
            stk.push(to_string((long long)b));
        } else if (in == "ASSIGN") {
            VALUE = get_value(mp, stk);
            stk.pop();
            ID = stk.top();
            stk.pop();
            mp.insert(make_pair(ID, VALUE));
        } else {
            error_msg("Wrong command!");
        }
    }
}
