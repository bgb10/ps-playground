/*
양쪽으로 뺄 수도 있고, 넣을 수도 있는 자료구조가 필요 -> Deque
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m; 
    deque<int> DQ;
    for(int i=1; i<=n; i++) 
        DQ.push_back(i);
    int dest;
    int ans = 0;
    for(int i=0; i<m; i++) {
        cin >> dest;
        int cnt = 0;
        deque<int> temp = DQ;
        while(DQ.front() != dest) {
            DQ.push_back(DQ.front());
            DQ.pop_front();
            cnt++;
        }
        if(cnt > DQ.size()-cnt) {
            DQ = temp;
            cnt = 0;
            while(DQ.front() != dest) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
                cnt++;
            }
        }
        DQ.pop_front(); // 앞에서만 뺄 수 있다.
        ans += cnt;
    }
    
    cout << ans;
    return 0;
}