#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n, k, cnt = 0;
    string s;

    cin >> n >> k;
    cin >> s;

    stack<char> st;
    stack<char> st2;

    for(char i : s) {
        while(!st.empty() && cnt < k && i > st.top()) {
            cnt++;
            st.pop();
        }
        st.push(i);
    }
    while(cnt < k) {
        cnt++;
        st.pop();
    }
    while(!st.empty()) {
        st2.push(st.top());
        st.pop();
    }
    while(!st2.empty()) {
        cout << st2.top();
        st2.pop();
    }

    return 0;
}