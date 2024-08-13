#include <iostream>
#include <cmath> //1275
using namespace std;

typedef long long ll;

int n, q, x, y, a;
ll b;
ll *tree;
ll arr[100001];

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(2*node, start, mid) + init(2*node+1, mid+1, end);
}

ll sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
    if(idx < start || idx > end) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(node*2, start, mid, idx, diff);
    update(node*2+1, mid+1, end, idx, diff);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int height = ceil(log2(n));
    tree = new ll[1 << (height+1)];
    init(1, 0, n-1);

    for(int i=0; i<q; i++) {
        cin >> x >> y >> a >> b;
        if(x <= y) cout << sum(1, 0, n-1, x-1, y-1) <<'\n';
        else cout << sum(1, 0, n-1, y-1, x-1) << '\n';
        update(1, 0, n-1, a-1, b-arr[a-1]);
        arr[a-1] = b;
    }

    return 0;
}