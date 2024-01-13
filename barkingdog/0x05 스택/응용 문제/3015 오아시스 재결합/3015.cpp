#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long cnt = 0; // cnt 개수가 터질수도
    int n;
    cin >> n;
    int h;
    stack<pair<int, int>> S;
    while(n--) {
        cin >> h;
        int nseq = 1;
        while(!S.empty()) {
            int t = S.top().X;
            int seq = S.top().Y;
            if(t <= h) {
                if(t == h)
                    nseq += seq;
                cnt += seq;
                S.pop();
            } 
            else {
                cnt++;
                break;
            }
        }
        S.push({h, nseq});
    }

    cout << cnt;
    return 0;
}