#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> fail(const string &p) {
    vector<int> table(p.length(), 0);
    int j = 0;
    for(int i=1; i<p.length(); i++) {
        while(j > 0 && p[i] != p[j]) j = table[j - 1];
        if(p[i] == p[j]) table[i] = ++j;
    }
    return table;
}

int main() {
    string p;
    while(true) {
        cin >> p;
        if(p == ".") break;

        int n = (int)p.length();
        vector<int> table = fail(p);
        int repeat = n - table[n-1];
        if(n % repeat) cout << 1 << '\n';
        else cout << n / repeat << '\n';
    }

    return 0;
}