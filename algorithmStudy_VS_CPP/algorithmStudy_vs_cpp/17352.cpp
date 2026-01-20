#include <iostream>
using namespace std;

const int MAX = 300001;
int parent[MAX];

int findParent(int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int rootA = findParent(a);
    int rootB = findParent(b);
    if (rootA != rootB)
        parent[rootB] = rootA;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = 0; i < n - 2; i++) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }

    int root = findParent(1);
    for (int i = 2; i <= n; i++) {
        if (findParent(i) != root) {
            cout << 1 << " " << i << "\n";
            break;
        }
    }

    return 0;
}