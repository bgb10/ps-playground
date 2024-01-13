#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        queue<int> Q;
        int priority[103];
        int cnt = 0;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> priority[i];
            Q.push(i);
        }
        while(!Q.empty()) {
            while(priority[Q.front()] < *max_element(priority, priority + n)) {
                Q.push(Q.front());
                Q.pop();
            }
            // 출력
            cnt++;
            if(Q.front() == m) {
                cout << cnt << '\n';
                break;
            }
            priority[Q.front()] = 0;
            Q.pop();
        }
    }

    return 0;
}