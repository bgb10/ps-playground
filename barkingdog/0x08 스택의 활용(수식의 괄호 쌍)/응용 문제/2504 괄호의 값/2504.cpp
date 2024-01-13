#include <bits/stdc++.h>
using namespace std;

// 굳이 스택이 아니라 재귀로 푸는게 더 깔끔해 보이는데?
// 근데 스택이 곧 재귀잖아 ㅋㅋㅋㅋㅋㅋ
// 숫자랑 괄호들이랑 따로 저장하면 좋을듯.
// 복잡하게 푸니까 꼬여서 시간만 오래 걸리네 ㅋㅋㅋㅋ 이런 ㅋㅋㅋㅋㅋ

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 0;
    stack<int> S;
    
    for(char c : s) {
        if(!S.empty() && (S.top() == -1 && c == ')')) {
            S.pop();
            S.push(2);
        } else if(!S.empty() && (S.top() == -3 && c == ']')) {
            S.pop();
            S.push(3);
        } else if(c == ')') {
            int sum = 0;
            if(S.empty()) {
                cout << 0;
                return 0;
            }
            while(!S.empty() && S.top() != -1) {
                if(S.top() < 0 && S.top() != -1) {
                    cout << 0;
                    return 0;
                }
                sum += S.top();
                S.pop();
            }
            
            if(S.empty()) {
                cout << 0;
                return 0;
            }
            S.pop();
            S.push(sum * 2);
        } else if(c == ']') {
            int sum = 0;
            if(S.empty()) {
                cout << 0;
                return 0;
            }
            while(!S.empty() && S.top() != -3) {
                if(S.top() < 0 && S.top() != -3) {
                    cout << 0;
                    return 0;
                }
                sum += S.top();
                S.pop();
            }

            if(S.empty()) {
                cout << 0;
                return 0;
            }
            S.pop();
            S.push(sum * 3);
        } else {
            if(c == '(') {
                S.push(-1);
            }
            else {
                S.push(-3);
            }
        }
    }

    int total = 0;
    while(!S.empty()) {
        total += S.top();
        S.pop();
    }

    cout << total;

    return 0;
}