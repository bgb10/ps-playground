/*
각 작업들마다 선후관계가 있기 때문에 위상정렬로 풀이할 수 있다.
이때 작업들 간의 수행시간이 존재하고, 동시에 수행이 가능하다.
각 작업의 입장에서 생각해보면,
선행 작업이 하나일 경우에는 이전 작업이 끝나는 대로 바로 시작하면 된다.
하지만 선행 작업이 여러개일 경우에는 이전 작업들 중 끝나는 시간이 가장 큰(최대 값) 작업이 끝나면 바로 시작하면 된다.
따라서 일반적인 위상 정렬을 수행하면서 indegree가 0일 경우 다음 노드로 넘어갈 때 선행 노드들 중
가장 마지막에 끝나는 시간을 기준으로 이어서 진행하면 된다.
이를 위해 노드를 저장하는 자료구조를 최대 힙으로 정하면 된다.

# 위상정렬 그래프를 그려서 생각해보면 쉽게 풀 수 있는 문제다.
*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define X first
#define Y second

int cost[10005];
int indeg[10005];
vector<int> adjs[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, k;
        cin >> c >> k;
        cost[i] = c;
        for (int j = 0; j < k; j++) {
            int bf;
            cin >> bf;
            adjs[bf].push_back(i);
            indeg[i]++;
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> to_visit;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) to_visit.push({0 + cost[i], i});
    }
    int ans = 0;
    while (!to_visit.empty()) {
        auto cur = to_visit.top();
        to_visit.pop();
        ans = cur.X;
        for (int nxt : adjs[cur.Y]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) {
                to_visit.push({cur.X + cost[nxt], nxt});
            }
        }
    }
    cout << ans;

    return 0;
}