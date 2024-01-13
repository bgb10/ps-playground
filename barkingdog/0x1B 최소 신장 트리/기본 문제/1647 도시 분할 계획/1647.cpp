/*
마을 안에 집을 연결해야 하고, 이때 유지비의 합이 최소가 되어야 하므로 MST를 이용한 문제다.
그런데, 마을이 2개로 분리되어야 하는데 이를 어떻게 할 수 있을까?
MST를 통해 묶인 집들은 하나의 마을로 묶이게 된다.
그런데 여기에서 하나의 길을 지우게 된다면, 두개의 마을로 묶이게 된다.
왜 그럴까? 귀류법을 통해서 증명할 수 있다.
'MST를 구한 다음 임의의 하나의 간선을 뺐을 때 3개 이상의 마을로 묶여있을 수 있다.' 라고 하자.
이 경우 MST를 완성하기 위한 길을 하나 추가하더라도 1개의 마을로 묶일 수 없다.
즉, MST가 만들어지지 않는다.
따라서, MST를 구한 다음 가중치가 가장 높은 하나의 간선을 빼게 되면 2개의 마을로 나눠진다.

Kruskal 알고리즘을 이용해 간선을 선택해가는 과정에서 n-2 개까지 간선을 선택하면 된다.

# 약간의 수학적 증명을 통해 쉽게 풀 수 있는 문제다. 개인적으로 골드4는 아니고 골드3 정도인듯.
*/
#include <bits/stdc++.h>
using namespace std;

int parent[100005];

void make_set(int x) { parent[x] = x; }

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void uni(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    vector<tuple<int, int, int>> to_visit;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        to_visit.push_back({cost, a, b});
    }
    sort(to_visit.begin(), to_visit.end());
    int cnt = 0;
    int ans = 0;
    for (auto edge : to_visit) {
        int cost, a, b;
        tie(cost, a, b) = edge;
        if (find(a) == find(b)) continue;
        cnt++;
        ans += cost;
        uni(a, b);
        if (cnt == n - 2) break;
    }
    cout << ans;
    return 0;
}