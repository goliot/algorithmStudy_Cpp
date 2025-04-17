#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

int main() {
    cin >> str;

    stack<char> s;

    for(char i : str) {
        if(i>='A' && i<='Z') {
            cout << i;
            continue;
        }
        if(i=='(')
            s.push(i);
        else if(i==')') {
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(i=='*' || i=='/') {
            while(!s.empty() && (s.top()=='*' || s.top()=='/')) {
                cout << s.top();
                s.pop();
            }
            s.push(i);
        }
        else if(i=='+' || i=='-') {
            while(!s.empty() && s.top()!='(') {
                cout << s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}