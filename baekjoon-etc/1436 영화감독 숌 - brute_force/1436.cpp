#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    // 대충 10000번째 수를 6660000 라고 하면, 연산량이 천만 이하이므로 O(n) 안에 brute force 가능 
    for(int i=666; ; i++) {
        string s = to_string(i);
        if(s.find("666") == std::string::npos) continue;
        cnt++;
        if(cnt == n) {
            cout << i;
            break;
        }
    }
    return 0;
}