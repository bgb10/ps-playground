/*
전형적인 Flood Fill 문제. BFS 로 해결하면 된다.

컴퓨터 사이의 연결은 다음 노드를 표시하는 배열 사용하면 된다.
이때 a와 b가 연결되어 있다면 a->b 만 표시할게 아니라 b->a 도 표시해야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nxts[102];
bool vis[102];
int ans = 0;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    int c;
    cin >> c;

    int a, b;
    for(int i=0; i<c; i++) {
        cin >> a >> b;
        nxts[a].push_back(b); // a->b
        nxts[b].push_back(a); // b->a
    }

    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt : nxts[cur]) {
            if(vis[nxt] == 1) continue;
            vis[nxt] = 1;
            ans++;
            Q.push(nxt);
        }
    }
    cout << ans;

	return 0;
}