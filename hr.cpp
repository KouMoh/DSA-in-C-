#include <iostream>
#include <stack>
using namespace std;

bool matches(char x, char y) {
    return ((x == '(' && y == ')') || (x == '{' && y == '}') || (x == '[' && y == ']'));
}

string isBalanced(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (!st.empty() && matches(ch, st.top())) {
                st.pop();
            } else {
                return "NO";
            }
        }
    }

    if (st.empty()) {
        return "YES"; // Return "YES" for balanced parentheses
    } else {
        return "NO";
    }
}
