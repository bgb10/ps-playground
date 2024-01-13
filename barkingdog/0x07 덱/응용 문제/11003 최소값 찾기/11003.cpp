#include <bits/stdc++.h>
using namespace std;

deque<int> DQ;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for(int i=0; i<l-1; i++) DQ.push_back(INT_MIN);
    int a;
    int cnt = 0;
    int pcnt = 0;
    cin >> a;
    DQ.push_back(a);
    for(int i=1; i<n; i++) {
        cin >> a;
        if(DQ.front() == INT_MIN)
            cnt++;
        else {
            if(cnt != 0) {
                for(int j=0; j<cnt + 1; j++) {
                    cout << DQ.front() << ' ';
                    pcnt++;
                }
                cnt = 0;
            } else {
                cout << DQ.front() << ' ';
                pcnt++;
            }
        }
        DQ.pop_front();

        int poped = 0;
        while(!DQ.empty() && a < DQ.back()) {
            if(cnt != 0 && DQ.size() == 1) break;
            DQ.pop_back();
            poped++;
        }
        for(int j=0; j<poped; j++)
            DQ.push_back(INT_MIN);
        
        DQ.push_back(a);

        // cout << "\nDQ\n";
        // for(int num : DQ) {
        //     cout << num << ' ';
        // }
        // cout << "END\n";
    }
    while(!DQ.empty() && DQ.front() == INT_MIN)
        DQ.pop_front();
    for(int i=pcnt; i<n; i++)
        cout << DQ.front() << ' ';
    return 0;
}