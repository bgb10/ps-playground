/*
이미 연결된 간선이 있을 때 MST를 구하는 문제.

황선자씨 및 우주선을 노드, 통로를 간선 이라고 하고, 통로의 길이의 합을 '최소'가 되게
통로를 만들어야 하므로 전형적인 MST문제이다.
하지만 '이미 연결된 통로'가 있기 때문에, 이를 고려해서 MST를 구해야 한다.
Kruskal 알고리즘의 경우 이미 연결된 통로가 있는 경우를 연결된 노드들이 서로 같은 집합이라고 생각하고
알고리즘을 진행하면 된다. 같은 집합을 잇는 노드는 MST에 추가하지 않는 것이다.

통로들의 길이의 합의 최소 -> MST
이미 연결된 통로 -> 통로 양 끝에 연결된 노드들은 같은 집합

# 코드를 짤 때 x, y 또는 a, b 등 기호를 잘 구분하자. 햇갈린다.
원소들의 순서를 a, b로 하고, 좌표를 x,y 로 해야지, 둘을 혼용하면 코드 쓸 때 계속 햇갈린다.
# 큰 수에 대한 제곱이기 때문에 수의 범위가 벗어나지는 않았는지 의심하자.
x, y의 범위가 백만이지만, 이를 제곱할 경우 int 범위가 초과된다. 9% 에서 틀리는 사람은 그런 이유였던 것.
# 소수점을 고정출력할 경우 cout << fixed 를 사용한 다음, precision 을 주면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

using ll = long long;

int p[1005];

vector<pair<ll, ll>> locations;

void make_set(int x) { p[x] = x; }

int find(int x) {
    if (p[x] == x) {
        return x;
    } else {
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
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    locations.push_back({INT_MAX, INT_MAX});  // 더미 노드
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        locations.push_back({x, y});
    }
    double ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) continue;
        uni(a, b);
        cnt++;
    }
    vector<tuple<double, int, int>> to_visit;
    // 방문할 간선 배열 구하기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (find(i) == find(j)) continue;
            double dist = sqrt((locations[i].X - locations[j].X) * (locations[i].X - locations[j].X) +
                               (locations[i].Y - locations[j].Y) * (locations[i].Y - locations[j].Y));
            to_visit.push_back({dist, i, j});
        }
    }
    sort(to_visit.begin(), to_visit.end());
    for (auto i : to_visit) {
        double cost;
        int a, b;
        tie(cost, a, b) = i;
        if (find(a) == find(b)) continue;
        uni(a, b);
        cnt++;
        ans += cost;
        if (cnt == n - 1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    return 0;
}