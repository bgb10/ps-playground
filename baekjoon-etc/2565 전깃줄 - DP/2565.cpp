/*

*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> con;
vector<int> dp;  // con의 index 에 따른 최대 개수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        con.push_back({a, b});
        dp.push_back(1);
    }
    sort(con.begin(), con.end());
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (con[j].X >= con[i].X || con[j].Y >= con[i].Y) continue;
            mx = max(mx, dp[j]);
        }
        dp[i] = max(dp[i], 1 + mx);
    }
    cout << n - *max_element(dp.begin(), dp.end());
    return 0;
}