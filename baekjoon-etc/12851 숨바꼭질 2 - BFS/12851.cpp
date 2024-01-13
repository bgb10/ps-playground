/*
최단거리 뿐만 아니라 경로의 횟수도 찾아야 하는 문제.

일반적으로 BFS 를 구현할 때 한 번 방문한 경로는 다시 방문하지 않으므로, BFS 구현을 변형해야지
풀 수 있다.

이 문제는 두 문제로 쪼갤 수 있다.
첫번째, 도착지까지의 최단 경로를 구하는 것.
두번째, 도착지까지 가는 경로의 경우의 수를 구하는 것.

만약 BFS를 한 번만 돌아서 처리하면 여러 예외가 발생할 수 있기 때문에,
BFS 를 2번 돌려서 풀기로 했다. 이렇게 해도 시간 복잡도 문제는 없다.

최단 경로 mn 를 구하면 도착지까지의 경로를 구하기 위해 BFS 를 다시 돌려야 한다.
이때 BFS 의 노드의 깊이가 mn 이상 깊어지면 안된다! 그러면 이미 최단 경로로 도착지에 도달할 수 없기 때문이다.
아마 여기서 pruning 을 하지 않으면 메모리 초과가 날 것이다.

하지만 위의 조건까지만 처리하게 되면 틀리게 된다.
위의 조건으로만 쓰게 되면 거리를 덮어씌워 줄 때 최단경로가 아닌 경우에도 덮어씌워지기 때문이다.
BFS 의 queue 에는 자동으로 최단경로 순으로 좌표가 저장되고, 최단경로 순으로 배열에 거리가 체크된다.
그런데 이미 최단경로인 배열에 다시 방문하는 경우가 생길 때, 거리를 체크하지 않으면 다시 덮어씌워지므로 문제가 생긴다.

# 둘이 같이 처리하기 복잡하면 단계를 나눠서 처리하자.
*/

#include <bits/stdc++.h>
#define SIZE 100004

using namespace std;


int n, k;
int dist[SIZE];

int main() {
    cin >> n >> k;
    fill(dist, dist+SIZE, -1);
    queue<int> Q1;
    dist[n] = 0;
    Q1.push(n);
    int mn = 100000;
    if(n == k) {
        cout << 0 << '\n' << 1;
        return 0;
    }
    bool isvisited = false;
    while(!Q1.empty()) {
        int cur = Q1.front(); Q1.pop();
        for(int nxt : {cur - 1, cur + 1, cur * 2}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            if(nxt == k) {
                mn = dist[cur] + 1;
                isvisited = true;
                break;
            }
            Q1.push(nxt);
        }
        if(isvisited) break;
    }
    fill(dist, dist+SIZE, -1);
    queue<int> Q2;
    dist[n] = 0;
    Q2.push(n);
    int cnt = 0;
    while(!Q2.empty()) {
        int cur = Q2.front(); Q2.pop();
        for(int nxt : {cur - 1, cur + 1, cur * 2}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[cur] + 1 > mn) continue; 
            if(dist[nxt] != -1 && dist[nxt] < dist[cur] + 1) continue; // 최단경로가 아니면 덮어씌우지 않는다.
            dist[nxt] = dist[cur] + 1;
            if(nxt == k) {
                cnt++;
                continue;
            }
            Q2.push(nxt);
        }
    }
    
    cout << dist[k] << '\n' << cnt;
    return 0;
}