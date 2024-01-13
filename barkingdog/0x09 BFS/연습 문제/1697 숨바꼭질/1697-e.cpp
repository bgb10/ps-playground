#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 수빈이와 동생이 모두 움직일 수 있으면 BFS 와 함께 백트랙킹을 같이 써야했겠지?
// 그게 아니고 수빈이만 움직이고, 최단 거리를 찾는 거니까 BFS 를 쓰면 되는거고.

// 방문 여부를 반드시 기록해놔야 한다. 아니면 큐에 데이터가 계속 쌓임
int dist[100004];

// Segfault: 배열 범위 이상 접근시
// 메모리 초과: 지금 상황에서는 큐에 데이터가 너무 많이 들어가서

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 굳이 거리를 queue에 저장할 필요가 없었다.
    queue<int> Q;

    int n, k;
    cin >> n >> k;

    if(n >= k) {
        cout << n-k;
        return 0;
    }

    Q.push(n);
    dist[n] = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        // ranged-based for loop
        for(int nxt : {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != 0) continue;
            if(nxt == k) {
                cout << dist[cur] + 1;
                return 0;
            }
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    return 0;
}