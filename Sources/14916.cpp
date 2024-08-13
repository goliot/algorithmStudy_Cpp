#include <iostream> //14916
using namespace std;

int main() {
    int n;
    cin >> n;
    int start = n/5;
    int remain = (n-start*5) % 2;

    while(remain!=0) {
        if(start==0) {
            cout << -1;
            return 0;
        }
        start -= 1;
        remain = (n - start * 5) % 2;
    }

    cout << start + (n - start * 5) / 2;

    return 0;
}