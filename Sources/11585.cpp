#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail(const string &p) {
    vector<int> table(p.length());
    int j = 0;
    for(int i=1; i<p.length(); i++) {
        while(p[i] != p[j] && j > 0) j = table[j - 1];
        if(p[i] == p[j]) table[i] = ++j;
    }
    return table;
}

int kmp(const string &s, const string &p, const vector<int> &table) {
    int j = 0;
    int count = 0;
    for (char i : s) {
        while (i != p[j] && j > 0) j = table[j - 1];
        if (i == p[j]) {
            j++;
        }
        if (j == p.length()) {
            count++;
            j = table[j - 1];
        }
    }
    return count;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    string s, p;
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        p.push_back(c);
    }
    s += s;
    s.pop_back();

    vector<int> table = fail(p);
    int a = kmp(s, p, table);
    int b = n;

    int x = gcd(a, b);
    cout << a / x << "/" << b / x;

    return 0;
}