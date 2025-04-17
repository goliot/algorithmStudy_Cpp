#include <iostream> //14501
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> Ti(16, 0);
vector<int> Pi(16, 0);
vector<int> ans(16, 0);

void dp() {
    int deadline;
    for(int i=n; i>0; i--) {
        deadline = i + Ti[i];
        if(deadline > n+1) {
            ans[i] = ans[i+1];
        }
        else {
            ans[i] = max(ans[i+1], ans[deadline] + Pi[i]);
        }
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> Ti[i] >> Pi[i];
    }
    dp();
    cout << ans[1];

    return 0;
}
