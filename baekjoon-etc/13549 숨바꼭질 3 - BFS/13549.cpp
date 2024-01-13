/*
BFS 를 조금 응용해서 풀어야 하는 문제.

방문을 최대한 빨리 할 수 있는 노드들을 방문할 수 있을 때 방문해놓는다. 그리고 방문한 노드들은 큐에 저장한다.
이미 방문되어 있는 노드들은 최단경로로 방문한 노드들이기에 더 이상 방문할 필요가 없다.
큐에 있는 모든 방문 예정 노드들을 다 방문하고 나서 큐를 비우면, 모든 경로의 최단경로를 기록할 수 있다.
*/
#include <bits/stdc++.h>
#define SIZE 100004

using namespace std;

int n, k;
int dist[SIZE];

int main() {
	fill(dist, dist+SIZE, -1);
    cin >> n >> k;
	queue<int> Q;
	dist[n] = 0;
	Q.push(n);
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(int nxt : {cur*2, cur-1, cur+1}) {
			if(nxt < 0 || nxt > 100000) continue;
			if(dist[nxt] != -1) continue;
			if(nxt == cur*2) {
				int i = cur;
				while(i <= 100000) {
					dist[i] = dist[cur];
					Q.push(i);
					i *= 2;
				}
			}
			else {
				dist[nxt] = dist[cur] + 1;
				Q.push(nxt);
			}
		}
	}
	cout << dist[k];
    return 0;
}