#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t, n;
vector<pair<int, int > > v;

int main() {
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        int maxVote, winner = 0;
        map<int, int> m;
//        vector<int> winnerV;
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            if (m.find(x) != m.end()) {
                m[x]++;
            } else m[x] = 1;
            maxVote = max(maxVote, m[x]);
            if(m[x] == maxVote) {
                winner = x;
            }
        }
        if(m[winner] > n/2) cout << "majority winner " << winner << '\n';
        else if(m[winner] <= n/2) cout << "minority winner " << winner << '\n';
    }

    return 0;
}
