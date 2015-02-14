#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

// Map for variables
map<string, int> mp;
// Stack for all values that get pushed
stack<string> stk;

// Error message wrapper
void error_msg (string msg) {
    cout << "Error for operator: " << msg << endl;
    exit(0);
}

int get_value () {
    // Check if value is a variable
    if(mp.count(stk.top())) {
        // Return mapped variable
        return mp[stk.top()]; 
    } else {
        // Convert stack value to int
        return stoi(stk.top());
    }
}

int main () {
    string in, ID;
    int VALUE, a(0), b(0);
    
    // Cin while not EOF
    while (cin >> in) {
        if(in == "PUSH") {
            if(cin >> in)
                stk.push(in);
            else
                error_msg("PUSH, missing argument!"); 
        } else if (in == "PRINT") {
            if(stk.empty()) // Check if PRINT has something to print
                error_msg(in + ", not enough values on stack!");
            cout << get_value() << endl;
        } else if (in == "ADD" || in =="SUB" || in == "MULT") {
            if(stk.size() < 2) // Check if OPPS have values to work with
                error_msg(in + ", not enough values on stack!");
            a = get_value();
            stk.pop();
            b = get_value();
            stk.pop();
            // Check which opperation to perform
            if(in == "ADD")
                b += a;
            else if(in == "SUB")
                b -= a;
            else
                b *= a;
            stk.push(std::to_string((long long)b));
        } else if (in == "ASSIGN") {
            if(stk.size() < 2) // Check is ASSIGN has values to ASSIGN
                error_msg(in + ", not enough values on stack!");
            VALUE = get_value();
            stk.pop();
            ID = stk.top();
            stk.pop();
            // Insert new variable into map
            mp.insert(make_pair(ID, VALUE));
        } else
            error_msg(in);
    }
}
