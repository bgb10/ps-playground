#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 1;
    stack<int> S;
    string res;
    while(n--) {
        int k;
        cin >> k;
        while(cnt <= k) {
            S.push(cnt);
            res += "+\n";
            cnt++;
        }
        if(S.top() != k) {
            cout << "NO";
            return 0;
        }
        S.pop();
        res += "-\n";
    }

    cout << res;

    return 0;
}