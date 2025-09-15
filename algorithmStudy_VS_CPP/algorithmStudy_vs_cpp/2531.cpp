#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    int answer = 0;

    cin >> n >> d >> k >> c;

    vector<int> rail(n);
    vector<int> counter(d + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> rail[i];
    }

    int uniqueCount = 0;
    for (int i = 0; i < k; ++i)
    {
        int sushi = rail[i % n];
        if (counter[sushi] == 0)
            uniqueCount++;
        counter[sushi]++;
    }

    for (int i = 0; i < n; ++i)
    {
        int current = uniqueCount + (counter[c] == 0 ? 1 : 0);
        answer = max(answer, current);

        int removeIdx = i;
        int addIdx = (i + k) % n;

        int removeSushi = rail[removeIdx];
        counter[removeSushi]--;
        if (counter[removeSushi] == 0)
            uniqueCount--;

        int addSushi = rail[addIdx];
        if (counter[addSushi] == 0)
            uniqueCount++;
        counter[addSushi]++;
    }

    cout << answer;
    return 0;
}