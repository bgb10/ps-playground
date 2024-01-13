#include <bits/stdc++.h>
using namespace std;

// STL의 find 메서드를 이용해 복사 없이도 쉽게 푼 문제.
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    deque<int> DQ;
    for(int i=1; i<=n; i++) DQ.push_back(i);
    while(m--) {
        int k;
        cin >> k;
        int idx = find(DQ.begin(), DQ.end(), k) - DQ.begin(); // idx: t가 있는 위치
        while(DQ.front() != k) {
            if(idx < (int)DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            } else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }
        DQ.pop_front();
    }

    cout << ans;

    return 0;
}