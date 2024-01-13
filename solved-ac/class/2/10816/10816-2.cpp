#include <bits/stdc++.h>
using namespace std;

vector<int> V;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        V.push_back(x);
    }
    sort(V.begin(), V.end());
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> x;
        auto a = lower_bound(V.begin(), V.end(), x);
        auto b = upper_bound(V.begin(), V.end(), x);
        cout << b - a << ' ';
    }
    return 0;
}