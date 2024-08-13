#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> edge[26];

void preorder(char cur) {
    if(cur=='.') return;
    cout << cur;
    preorder(edge[cur-'A'].first);
    preorder(edge[cur-'A'].second);
}

void inorder(char cur) {
    if(cur=='.') return;
    inorder(edge[cur-'A'].first);
    cout << cur;
    inorder(edge[cur-'A'].second);
}

void postorder(char cur) {
    if(cur=='.') return;
    postorder(edge[cur-'A'].first);
    postorder(edge[cur-'A'].second);
    cout << cur;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        edge[a-'A'] = {b, c};
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}