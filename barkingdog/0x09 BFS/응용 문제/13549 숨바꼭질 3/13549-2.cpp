#include <bits/stdc++.h>
using namespace std;
#define SIZE 100003

int n, k;
int dist[SIZE];
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    fill(dist, dist+SIZE, -1);
    cin >> n >> k;
    if(n > k) {
        cout << n - k;
        return 0;
    }  
    queue<int> Q;
    for(int i=n; i<=SIZE; i*=2) {
        dist[i] = 0;
        Q.push(i);
    }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + 1, cur - 1, cur * 2}) {
            if(nxt < 0 || nxt >= SIZE) continue;
            int t = (nxt == cur * 2) ? dist[cur] : dist[cur] + 1;
            if(dist[nxt] != -1) {
                if(dist[nxt] > t) dist[nxt] = t;
                continue;
            }
            dist[nxt] = t;
            Q.push(nxt);
        }
    }
    cout << dist[k];
    return 0;
}