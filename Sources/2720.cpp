#include <iostream> //2720
using namespace std;

int t, c;
int arr[4] = {0, };

void cal(int x) {
    while(x>0) {
        if(x-25 >= 0) {
            arr[0]++;
            x -= 25;
        }
        else if(x-10>=0) {
            arr[1]++;
            x -= 10;
        }
        else if(x-5>=0) {
            arr[2]++;
            x -= 5;
        }
        else {
            arr[3]++;
            x -= 1;
        }
    }
    for(int i : arr) {
        cout << i << " ";
    }
    cout << '\n';
    for(int & i : arr) {
        i = 0;
    }
}

int main() {
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> c;
        cal(c);
    }
    return 0;
}
