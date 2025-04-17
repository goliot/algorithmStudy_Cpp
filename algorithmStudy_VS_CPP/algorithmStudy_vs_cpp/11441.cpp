#include <iostream> //11441
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int arr[100001] = {0, };
    int pre[100001] = {0, };

    int n, m;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1] + arr[i];
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << '\n';
    }

    return 0;
}