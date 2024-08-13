#include <iostream> //10986
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> count(M, 0);
    count[0] = 1;
    int prefixSum = 0;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        prefixSum = (prefixSum + A[i]) % M;
        answer += count[prefixSum];
        count[prefixSum]++;
    }

    cout << answer << endl;

    return 0;
}