#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> quest) {
    int answer = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for(const auto& q : quest) {
        pq.emplace(q[0], q[1]);
    }

    int curExp = 0;

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if(curExp >= cur.first) {
            curExp += cur.second;
            answer++;
        }
    }

    return answer;
}