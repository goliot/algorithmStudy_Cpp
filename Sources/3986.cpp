#include <iostream>
#include <stack>
using namespace std;

int n;

int main()
{
    int cnt = 0;
    cin >> n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;

        stack<char> st;
        for(char j : s)
        {
            if(st.empty())
            {
                st.push(j);
            }
            else
            {
                if(st.top() == j)
                    st.pop();
                else
                    st.push(j);
            }
        }
        if(st.empty())
            cnt++;
    }

    cout << cnt;

    return 0;
}