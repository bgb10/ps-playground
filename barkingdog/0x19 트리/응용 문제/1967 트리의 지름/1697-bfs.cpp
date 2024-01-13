/*
BFS 를 사용하려면 리프 노드 부터 리프 노드 까지의 거리를 구해야 한다.
문제에서는 루트 노드 가 1로 고정되어 있기 때문에, 문제에서 주어진 자식/부모 관계
대신 인접 리스트로 노드간의 관계를 표현해야 한다.
이후 리프 노드(인접 리스트의 크기가 1)에 대해 BFS를 진행해서 트리의 지름을 구하면 된다.

시간복잡도는 O(N^2) 이다. 1초였으면 애매했겠지만 2초이므로 해볼만 하다.

# Tree DP 를 사용하면 시간복잡도를 O(N) 으로 줄일 수 있다.
*/

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<int> adjs[10002];
int dist[10002];
map<pair<int, int>, int> weights;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        adjs[p].push_back(c);
        adjs[c].push_back(p);
        weights.insert({{p, c}, w});
        weights.insert({{c, p}, w});
    }
    int mx = 0;
    for(int v = 1; v <= n; v++) {
        if(adjs[v].size() != 1) continue;
        memset(dist, -1, sizeof(int) * (n+1));
        queue<int> Q;
        dist[v] = 0;
        Q.push(v);
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for(int nxt : adjs[cur]) {
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + weights.at({cur, nxt});
                Q.push(nxt);
                mx = max(mx, dist[nxt]);
            }
        }
    }
    cout << mx;
    return 0;
}