#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int N, M;
int arr[MAXN+1];
int tree[4*(MAXN+1)];

void init(int node, int start, int end) {
    if (start == end) tree[node] = arr[start];
    else {
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INT_MAX;
    if (left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return min(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    init(1, 1, N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        cout << query(1, 1, N, a, b) << "\n";
    }
    return 0;
}
