#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n, m, a, b, c;
vector<pair<int, int>> v[11];

// maxEdgeCost 이하의 간선 비용을 가진 경로가 있는지 확인하는 함수
bool canReachWithMaxEdgeCost(int maxEdgeCost) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    dist[a] = 0;
    q.emplace(0, a);

    while (!q.empty()) {
        int currentDist = q.top().first;
        int node = q.top().second;
        q.pop();

        if (currentDist > dist[node]) continue;

        for (const auto& edge : v[node]) {
            int nextNode = edge.first;
            int edgeCost = edge.second;

            if (edgeCost > maxEdgeCost) continue; // 최대 간선 비용을 초과하면 무시

            int newDist = currentDist + edgeCost;
            if (newDist <= c && newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                q.emplace(newDist, nextNode);
            }
        }
    }

    return dist[b] != INF; // 도착점까지 도달할 수 있으면 true
}

int main() {
    cin >> n >> m >> a >> b >> c;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }

    int low = 0;
    int high = 0;

    // 그래프의 모든 간선 비용 중 최대 비용을 찾습니다
    for (int i = 1; i <= n; i++) {
        for (const auto& edge : v[i]) {
            high = max(high, edge.second);
        }
    }

    int result = -1;

    // Binary Search로 최소 최대 간선 비용을 찾음
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canReachWithMaxEdgeCost(mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}
