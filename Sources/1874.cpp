#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
stack<int> s;
vector<char> res;

int main() {
    int cnt = 1;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        while(cnt <= x) {
            s.push(cnt);
            cnt += 1;
            res.push_back('+');
        }
        if(s.top() == x) {
            s.pop();
            res.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    auto itr = res.begin();
    for_each(itr, itr + res.size(), [](auto& n) {
        cout << n << '\n';
    });
    
    return 0;
}