#include <iostream> //2920

using namespace std;

int main() {
    int arr[8];
    for(int i=0; i<8; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for(int i=1; i<8; i++) {
        if(arr[i-1]<arr[i]) cnt++;
        else cnt--;
    }
    if(cnt==7) cout << "ascending";
    else if(cnt==-7) cout << "descending";
    else cout << "mixed";

    return 0;
}
