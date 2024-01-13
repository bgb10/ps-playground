#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 1;
    string ans = "";
    stack<int> S;
    while (n--) {
        int k;
        cin >> k;
        while (cnt <= k) {
            S.push(cnt);
            ans += "+\n";
            cnt++;
        }
        if (S.top() == k) {
            S.pop();
            ans += "-\n";
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << ans;
}