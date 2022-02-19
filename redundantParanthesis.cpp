#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isRedundant(string str) {
    stack<char> s;

    for (auto ch : str) {
        if (ch != ')') {
            s.push(ch);
        }
        else {
            bool operator_found = false;
            while (!s.empty() && s.top() != '(') {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operator_found = true;
                }
                s.pop();
            }
            s.pop();

            if (operator_found == false) {
                return true;
            }
        }
    }


    return false;
}

int main(void) {
    string msg = "((a+b) + c)";

    if (isRedundant(msg) == true) {
        cout << "Has redundant paranthesis." << endl;
    }
    else {
        cout << "No redundant parenthesis." << endl;
    }


    return 0;
}
