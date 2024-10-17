#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail(string &p) {
    int j = 0;
    vector<int> table(p.length(), 0);
    for(int i=1; i<p.length(); i++) {
        while(j > 0 && p[i] != p[j]) j = table[j-1];
        if(p[i] == p[j]) table[i] = ++j;
    }
    return table;
}
int main() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    vector<int> table = fail(s);
    cout << l - table[s.length() - 1];

    return 0;
}