#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main(){
    string word,boom;
    cin >> word >> boom;

    stack<char> s;

    string ans;
    for(char c : word){

        s.push(c); // 스택에 넣음

        if(c == boom[boom.length()-1] && s.size() >= boom.length()){
            string tmp;
            for(int j = 0; j < boom.length(); j++){
                tmp.push_back(s.top());
                s.pop();
            }
            reverse(tmp.begin(),tmp.end()); // 뺀 문자열 뒤집기

            // 뒤집은 문자열과 폭발문 문자열 같은지 판단
            if(tmp != boom){
                for(char i : tmp) s.push(i);
            }
        }
    }

    // 스택에 남은 원소들을 ans에 넣음
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(),ans.end()); // 뒤집어서 순서대로 나오게함
    if(ans.empty()) cout << "FRULA"; // 스택이 비어있다면 모두 폭발한 것
    else cout << ans;
}