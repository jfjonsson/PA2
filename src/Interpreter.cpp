#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<string, int> mp;
stack<string> stk;

void error_msg (string msg) {
    cout << "Error for operator: " << msg << endl;
    exit(0);
}

int get_value () {
    if(mp.count(stk.top())) {
        return mp[stk.top()];
    } else {
        return stoi(stk.top());
    }
}

int main () {
    string in, ID;
    int VALUE, a(0), b(0);
    
    while (cin >> in) {
        if(in == "PUSH") {
            if(cin >> in)
                stk.push(in);
            else
                error_msg("PUSH, missing argument!"); 
        } else if (in == "PRINT") {
            if(stk.empty())
                error_msg(in + ", not enough values on stack!");
            cout << get_value() << endl;
        } else if (in == "ADD" || in =="SUB" || in == "MULT") {
            if(stk.size() < 2)
                error_msg(in + ", not enough values on stack!");
            a = get_value();
            stk.pop();
            b = get_value();
            stk.pop();
            if(in == "ADD")
                b += a;
            else if(in == "SUB")
                b -= a;
            else
                b *= a;
            stk.push(std::to_string((long long)b));
        } else if (in == "ASSIGN") {
            if(stk.size() < 2)
                error_msg(in + ", not enough values on stack!");
            VALUE = get_value();
            stk.pop();
            ID = stk.top();
            stk.pop();
            mp.insert(make_pair(ID, VALUE));
        } else
            error_msg(in);
    }
}
