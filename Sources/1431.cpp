#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sumCmp(const string& s) {
    int sum = 0;
    for(char c : s) {
        if(isdigit(c))
            sum += c - '0';
    }
    return sum;
}

bool cmp(const string& a, const string& b) {
    if(a.size() != b.size()) {
        return a.size() < b.size();
    }

    int sumA = sumCmp(a);
    int sumB = sumCmp(b);
    if(sumA != sumB) {
        return sumA < sumB;
    }

    return a < b;
}

int main() {
    int n;
    string x;
    vector<string> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), cmp);
    for(const string& s : v) {
        cout << s << endl;
    }

    return 0;
}