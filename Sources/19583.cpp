#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int ans = 0;
    string s, e, q;
    cin >> s >> e >> q;
    string time, name;
    unordered_set<string> us;
    while(cin >> time >> name) {
        if(time <= s) {
            us.insert(name);
        }
        else if(time >= e && time <= q) {
            if(us.find(name) != us.end()) {
                us.erase(name);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}