#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005
int dist[SIZE];
queue<int> Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist+SIZE, -1);
    int n, k;
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    Q.push(n);
    dist[n] = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nx : {cur-1, cur+1, cur*2}) {
            if(nx == k) {
                cout << dist[cur] + 1;
                return 0;
            }
            if(nx < 0 || nx >= SIZE) continue;
            if(dist[nx] != -1) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    return 0;
}