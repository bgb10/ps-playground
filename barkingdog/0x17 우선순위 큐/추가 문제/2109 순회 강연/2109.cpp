/*
# 1781 컵라면 문제와 똑같다.
*/
#include <bits/stdc++.h>

#include <queue>
using namespace std;
#define D first
#define P second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> V;
    while (n--) {
        int p, d;
        cin >> p >> d;
        V.push_back({d, p});
    }
    sort(V.begin(), V.end());
    priority_queue<int, vector<int>, greater<int>> min_PQ;
    for (auto i : V) {
        if (min_PQ.size() < i.D) {
            min_PQ.push(i.P);
        } else {
            if (min_PQ.top() < i.P) {
                min_PQ.pop();
                min_PQ.push(i.P);
            }
        }
    }
    int cnt = 0;
    while (!min_PQ.empty()) {
        cnt += min_PQ.top();
        min_PQ.pop();
    }
    cout << cnt;
    return 0;
}