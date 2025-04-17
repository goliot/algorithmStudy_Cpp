#include <iostream> //16139
#include <string>
using namespace std;
#define MAX 200000

char arr[MAX + 1];
int pre[27][MAX + 1];
char alphabet[27];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for(int i=1; i<=26; i++) {
        alphabet[i] = i+96;
    }

    string s;
    int q;
    cin >> s;

    for(int i=1; i<=s.size(); i++) {
        arr[i] = s[i-1];
//        cout << arr[i] << " ";
    }
//    cout << endl;
    for(int i=1; i<=26; i++) {
//        cout << alphabet[i] << ": ";
        for(int j=1; j<=MAX; j++) {
            if(arr[j]==alphabet[i]) {
                pre[i][j] = pre[i][j-1] + 1;
            } else pre[i][j] = pre[i][j-1];
//            cout << pre[i][j] << " ";
        }
//        cout << endl;
    }

    cin >> q;
    for(int i=0; i<q; i++) {
        char c;
        int a, b, cnt;
        cin >> c >> a >> b;
//        for(int j=0; j<26; j++) {
//            if(c==alphabet[j]) cnt = j;
//        }
        cnt = c-96;
        cout << pre[cnt][b+1] - pre[cnt][a] << '\n';
    }

    return 0;
}

