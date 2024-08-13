#include <iostream> //13305
using namespace std;
typedef long long ll;

ll dist[100001];
ll price[100001];
ll n, sum=0, greedy=1000000000;

int main() {

    cin >> n;
    for(int i=1; i<=n-1; i++) {
        cin >> dist[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> price[i];
    }
    for(int i=1; i<=n-1; i++) {
        if(price[i]<greedy) greedy = price[i];
        sum += greedy * dist[i];
    }
    cout << sum;

    return 0;
}