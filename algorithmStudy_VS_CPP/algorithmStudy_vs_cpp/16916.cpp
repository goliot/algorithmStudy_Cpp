#include <iostream>
#include <string>
#include <vector>
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
    for(char i : s) {
        while(i != p[j] && j > 0) j = table[j - 1];
        if(i == p[j]) {
            if(++j == p.length()) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> table = fail(p);
    cout << kmp(s, p, table);

    return 0;
}