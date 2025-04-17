#include <iostream> //1644
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> chk(n+1, true);
    vector<int> prime;

    for(int i=2; i*i<=n; i++) {
        if(chk[i]) {
            for(int j=i+i; j<=n; j+=i) {
                chk[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(chk[i]) prime.push_back(i);
    }
    int cnt = 0, s = 0, e = 0, sum = 0;
    while(true) {
        if(sum >= n) sum -= prime[s++];
        else if(e==prime.size()) break;
        else sum += prime[e++];

        if(sum==n) cnt++;
    }
    cout << cnt;

    return 0;
}