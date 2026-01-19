#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B;
    cin >> A >> B;

    const int MAX = 10000000;
    vector<int> v(MAX + 1, 0);

    for (int i = 2; i <= MAX; ++i) v[i] = i;

    for (int i = 2; 1LL * i * i <= MAX; ++i) {
        if (v[i] == 0) continue;
        for (long long j = 1LL * i * i; j <= MAX; j += i) {
            v[(int)j] = 0;
        }
    }

    long long count = 0;

    for (int i = 2; i <= MAX; ++i) {
        if (v[i] == 0) continue;

        long long p = v[i];
        long long x = p;

        while (x <= B / p) {   
            x *= p;           
            if (x >= A) count++;
        }
    }

    cout << count;
    return 0;
}
