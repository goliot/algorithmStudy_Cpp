#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;

    stack<pair<int, int> > s;

    vector<int> res;

    for(int i=0; i<n; i++)
    {
        cin >> x;

        while(!s.empty())
        {
            pair<int, int> left = s.top();

            if(left.first >= x)
            {
                res.push_back(left.second);
                break;
            }
            else
            {
                s.pop();
            }
        }

        if(s.empty())
        {
            res.push_back(0);
        }

        s.emplace(x, i + 1);
    }

    for(int i : res)
    {
        cout << i << " ";
    }

    return 0;
}