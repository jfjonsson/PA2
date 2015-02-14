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
    map<string, int> mp; // Map to hold our variables
    stack<string> stk; // Stack to hold values and variables
    string in, ID; 
    int VALUE, a(0), b(0);

    while (cin >> in) {
        if(in == "PUSH") {
            if(cin >> in) {
                stk.push(in);
            } else {
                error_msg("Missing argument!\n"); 
            }
        } else if (in == "PRINT") {
            if(mp.count(stk.top())) {
                cout << mp[stk.top()] << endl;
            } else {
                error_msg("No such variable!\n");
            }
            stk.pop();
        } else if (in == "ADD" || in == "SUB" || in == "MULT") {
            // Check if variable in map, else use as value
            if(mp.count(stk.top())) {
                a = mp[stk.top()];
            } else {
                a = stoi(stk.top());
            }
            stk.pop();
            // Check if variable in map, else use as value
            if(mp.count(stk.top())) {
                b = mp[stk.top()];
            } else {
                b = stoi(stk.top());
            }
            stk.pop();
            if(in == "ADD") {
                b += a;
            } else if (in == "SUB") {
                b -= a;
            } else {
                b *= a;
            }
            stk.push(to_string((long long)b));
        } else if (in == "ASSIGN") {
            // Check if variable in map, else use as value
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
            error_msg("Wrong command!\n"); // Input was not defined
        }
    }
}
