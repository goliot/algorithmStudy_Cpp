#include <iostream> //7662
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, n, x;
    char c;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        multiset<int> ms;
        while(n--) {
            cin >> c >> x;
            if(c == 'I') {
                ms.insert(x);
            } else {
                if(!ms.empty() && x == -1) {
                    ms.erase(ms.begin());
                } else if(!ms.empty()&&x==1) {
                    auto it = ms.end();
                    it--;
                    ms.erase(it);
                }
            }
        }
        if(ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            auto it2 = ms.end();
            it2--;
            cout << *it2 << " " << *ms.begin() << '\n';
        }
    }

    return 0;
}