#include <iostream> //2167
#include <vector>
using namespace std;
#define MAX 300

int n, m;

vector<vector<int> > v(MAX+1, vector<int>(MAX+1, 0)); //최초 입력 배열
vector<vector<int> > pre(MAX + 1, vector<int>(MAX+1, 0)); //누적합 배열

int Sum(int x1, int y1, int x2, int y2) { //구간합 구하는 함수
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) { //최초 배열 채우기
        for(int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }

    for(int i=1; i<=n; i++) { //O(N^2) 에 누적합 배열 완성
        for(int j=1; j<=m; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + v[i][j];
        }
    }

    int k;
    cin >> k;

    for(int i=1; i<=k; i++) { //질의마다 O(1)
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << Sum(a, b, c, d) << '\n';
    }

    return 0;
}
