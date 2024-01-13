/*
보자마자 MST 문제임을 알았지만 최소와 최대를 모두 표현해야 하는 문제

최소 피로도로 학교 탐방을 하려면 최소한의 오르막길을 타야하고, 따라서 내리막길의 가중치를 0, 오르막길의 가중치를 1로 주고 MST를 구하면 된다.
최대 피로도로 학교 탐방을 하려면 최소한의 내리막길을 타야하고, 따라서 내리막길의 가중치를 1, 오르막길의 가중치를 0로 주면 된다.
또는 문제에서 주어지는 그대로 받은 다음에 방문할 노드의 순서를 오름차순, 내림차순으로 바꿔도 된다. 

# 최소는 곧 최대가, 최대는 곧 최소가 될 수 있다는 사실을 기억하자.
# 배열의 정렬 기준에 따라 방문 기준이 달라질 수 있다. 꼭 최대, 최소만 있는게 아니다.
*/
#include <bits/stdc++.h>
using namespace std;

int p[1005];

void make_set(int x) {
    p[x] = x;
}

int find(int x) {
    if(p[x] == x) {
        return x;
    }
    else {
        return p[x] = find(p[x]);
    }
}

void uni(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    p[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> to_visit;
    for(int i=0; i<m+1; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        to_visit.push_back({!cost, a, b});
    }
    
    int cnt = 0;
    int k = 0;

    n++; // 입구 포함

    for(int i=0; i<=n; i++) {
        make_set(i);
    }
    
    sort(to_visit.begin(), to_visit.end());
    for(auto edge : to_visit) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if(find(a) == find(b)) continue;
        cnt++;
        k += cost;
        uni(a, b);
        if(cnt == n-1) break;
    }
    int mn = k * k;

    cnt = 0;
    k = 0;

    for(int i=0; i<=n; i++) {
        make_set(i);
    }
    
    sort(to_visit.begin(), to_visit.end(), greater<tuple<int, int, int>>());
    for(auto edge : to_visit) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if(find(a) == find(b)) continue;
        cnt++;
        k += cost;
        uni(a, b);
        if(cnt == n-1) break;
    }
    int mx = k * k;

    cout << mx - mn;
    return 0;
}