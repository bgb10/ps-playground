#include <bits/stdc++.h>
using namespace std;

int t[500004];
int ans[500004];

struct top_data {
    int index;
    int h;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<top_data> S;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> t[i];
    for(int i=n; i>=1; i--) {
        while(!S.empty()) {
            top_data s = S.top();
            if(s.h < t[i]) {
                ans[s.index] = i;
                S.pop();
            } else {
                break;
            }
        }
        struct top_data d;
        d.h = t[i];
        d.index = i;
        S.push(d);
    }

    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}