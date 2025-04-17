#include <iostream> //1541
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 0;
    string num;
    bool isMinus = false;

    for(int i=0; i<=s.size(); i++) {
        if(s[i]=='-' || s[i]=='+' || i==s.size()) {
            if(isMinus) {
                res -= stoi(num);
                num = "";
            } else {
                res += stoi(num);
                num = "";
            }
        } else {
            num += s[i];
        }

        if(s[i] == '-') {
            isMinus = true;
        }
    }
    cout << res;

    return 0;
}