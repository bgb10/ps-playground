/* 
  Topology Sort (위상 정렬)

  방문할 노드들 사이의 선후관계가 존재할 때 사용하는 정렬.

  시간복잡도: 0(V+E) (여기서 edge 는 각 노드에 따른 adjs 의 원소의 개수와 같다)
*/

#include <bits/stdc++.h>
#define SIZE 32002
using namespace std;

int indegree[SIZE];
vector<int> adjs[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        adjs[a].push_back(b);
    }
    queue<int> order;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) {
            order.push(i);
        }
    }
    while(!order.empty()) {
        int cur = order.front(); order.pop();
        cout << cur << ' ';
        for(int adj : adjs[cur]) {
            indegree[adj]--;
            if(indegree[adj] == 0) {
                order.push(adj);
            }
        }
    }
    return 0;
}