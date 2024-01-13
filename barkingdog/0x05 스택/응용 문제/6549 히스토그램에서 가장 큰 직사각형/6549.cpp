#include <bits/stdc++.h>
using namespace std;
#define height first
#define width second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int n;
        int x;
        long long mx = 0; // 넓이(W * H) 는 int 자료형 범위를 넘을 수 있게 때문에 long long 으로 처리.
        cin >> n;
        if(n == 0) break;
        stack<pair<int, int>> S;
        for(int i=0; i<=n; i++) {
            // 스택을 후처리 하는 대신에 마지막에 h=0 인 dummy 도형을 넣어줘서 쉽게 처리.
            if(i == n) 
                x = 0;
            else 
                cin >> x;
            if(S.empty() || S.top().height < x) {
                S.push({x, 1});
                continue;
            }
            int nw = 0;
            while(!S.empty() && S.top().height >= x) {
                int h = S.top().height;
                int w = S.top().width + nw;
                mx = max(mx, (long long)h*w); // long long 으로 강제 형변환을 시켜서 type 을 맞춰줌.
                nw += S.top().width;
                S.pop();
            }
            S.push({x, 1 + nw});
        }
        cout << mx << '\n';
        S = stack<pair<int, int>>();
    }
    return 0;
}