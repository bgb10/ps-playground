/*
전형적인 Flood Fill 문제. BFS 로 해결하면 된다.

노드 사이의 연결을 배열에 표시하고 나서 모든 노드를 순회하면서 각각을 큐에 넣고 Flood Fill 을 진행하면 된다.
이때 이미 방문된 노드의 경우는 연결 요소(Connected Component)에 포함되므로 Flood Fill 을 진행하지 않는다.
Flood Fill 이 진행되는 만큼, 연결 요소가 존재한다고 판단할 수 있다.

# '2606 바이러스' 문제와 거의 똑같은 문제다. 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nxts[1002];
bool vis[1002];
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    int m;
    cin >> m;

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        nxts[a].push_back(b); // a->b
        nxts[b].push_back(a); // b->a
    }

    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(vis[i] == 1) continue;
        queue<int> Q;
        vis[i] = 1;
        Q.push(i);
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nxt : nxts[cur]) {
                if(vis[nxt] == 1) continue;
                vis[nxt] = 1;
                Q.push(nxt);
            }
        }
        ans++;
    }
    
    cout << ans;
	return 0;
}