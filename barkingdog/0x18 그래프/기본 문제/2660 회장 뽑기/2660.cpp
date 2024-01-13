/*
사람들을 노드로 두고, 각 노드에 대해 BFS 를 통해 다른 노드와의 거리를 구해서 최대 거리가 곧 가까운 정도를 나타낸다.
최대 거리가 가장 작은 사람들이 회장 후보다.

시간복잡도는 O(N * (N+E)) 이다. (E는 친구 관계의 개수, 즉 간선의 개수)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> adjs[52];
int dist[52];
int score[52];
vector<int> candidates;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // 입력
    while (1) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    // 각 노드마다 BFS 및 점수 측정
    for (int u = 1; u <= n; u++) {
        fill(dist+1, dist+n+1, -1);
        queue<int> Q;
        dist[u] = 0;
        Q.push(u);
        int mn = 0;
        while(!Q.empty()) {
            int from = Q.front(); Q.pop();
            for(int to : adjs[from]) {
                if(dist[to] != -1) continue;
                dist[to] = dist[from] + 1;
                Q.push(to);
                mn = max(mn, dist[to]);
            }
        }
        score[u] = mn; // 가장 먼 친구와의 거리가 곧 점수이다.
    }
    // 점수에 따라 후보자 구하기
    int candidates_score = *min_element(score+1, score+n+1);
    for(int u=1; u<=n; u++) {
        if(score[u] == candidates_score)
            candidates.push_back(u);
    }
    // 답 출력
    cout << candidates_score << ' ' << candidates.size() << '\n';
    for(int candidate : candidates) {
        cout << candidate << ' ';
    }
    return 0;
}