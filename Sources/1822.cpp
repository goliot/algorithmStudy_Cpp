#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    set<int> s;
    for(int i=0; i<a; i++) {
        int n;
        cin >> n;
        s.insert(n);
    }
    for(int i=0 ;i<b; i++) {
        int n;
        cin >> n;
        s.erase(n);
    }

    cout << s.size() << '\n';

    if(!s.empty()) {
        for(auto it : s) {
            cout << it << ' ';
        }
    }

    return 0;
}