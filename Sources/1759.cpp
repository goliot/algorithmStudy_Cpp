#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l, c;
vector<char> num;
vector<char> password;

bool check() {
    int m = 0;
    for(int i=0; i<l; i++) {
        if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
            m++;
        }
    }
    if(m>=1 && l-m>=2) return true;
    return false;
}

void dfs(int d) {
    if((int)password.size() == l) {
        if(check()) {
            for(int i=0; i<l; i++) {
                cout << password[i];
            }
            cout << endl;
        }
        return;
    }
    else {
        for(int i=d; i<c; i++) {
            password.push_back(num[i]);
            dfs(i+1);
            password.pop_back();
        }
    }
}

int main() {
    cin >> l >> c;
    for(int i=0; i<c; i++) {
        char t;
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    dfs(0);

    return 0;
}