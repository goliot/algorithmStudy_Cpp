#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
// 내 위에 있는 것을 찾기
if(idx % w == 0) +1;

+ w * 2 - idx % w - (idx % w - 1)

7 -> + 12 - 1 = 18 -> -0
8 -> + 12 - 2 = 18 -> -1
9 -> + 12 - 3 = 18 -> -2
10 -> + 12 - 4 - 3= 18 -> -3
11 -> + 12 - 5 - 4= 18 -> -4
14 -> + 12 - 2 = 24 -> -1
*/
int findUpper(const int& w, int current)
{
    if (current % w == 0)
    {
        return current + 1;
    }

    return current + w * 2 - (current % w + (current % w - 1));
}


int solution(int n, int w, int num) {
    int answer = 0;

    int current = num;
    int upper = 0;
    while (upper <= n)
    {
        upper = findUpper(w, current);
        current = upper;
        cout << upper << '\n';
        if (upper <= n) answer++;
    }

    return ++answer;
}

int main()
{
    solution(13, 3, 6);

    return 0;
}