#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    int cnt = 1;
    string ans;
    cin >> n;
    stack<int> S;
    while (n--) {
        cin >> k;
        while (cnt <= k) {
            S.push(cnt);
            ans += "+\n";
            cnt++;
        }
        if (S.top() != k) {
            cout << "NO";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
    return 0;
}