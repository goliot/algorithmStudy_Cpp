#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minRes = INT_MAX, maxRes = INT_MIN;
int n, x;
vector<int> numbers;
int operators[4];

void dfs(int res, int idx) {
    if(idx == n) {
        minRes = min(res, minRes);
        maxRes = max(res, maxRes);
        return;
    }

    for(int i=0; i<4; i++) {
        if(operators[i] > 0) {
            operators[i]--;
            if(i==0) {
                dfs(res + numbers[idx], idx + 1);
            }
            else if(i==1) {
                dfs(res - numbers[idx], idx + 1);
            }
            else if(i==2) {
                dfs(res * numbers[idx], idx + 1);
            }
            else {
                dfs(res / numbers[idx], idx + 1);
            }
            operators[i]++;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        numbers.push_back(x);
    }
    for(int i=0; i<4; i++) {
        cin >> operators[i];
    }
    dfs(numbers[0], 1);

    cout << maxRes << '\n' << minRes;

    return 0;
}