#include <bits/stdc++.h>
using namespace std;

// 너무 복잡하게 짰다.

int n;
int es[10];
int ew[10];
int mx = INT_MIN;

int count_broken() {
    int cnt = 0;
    for(int i=0; i<n; i++)
        if(es[i] <= 0) cnt++;
    return cnt;
}

int find_next(int me) {
    int nxt = -1;
    for(int i=me+1; i<n; i++) {
        if(es[i] <= 0) continue;
        nxt = i;
    }

    return nxt;
}

void func(int me) {
    bool leaf = true;
    for(int i=0; i<n; i++) {
        if(i == me) continue;
        if(es[i] <= 0) continue;
        es[me] -= ew[i];
        es[i] -= ew[me];
        int nxt = find_next(me);
        if(nxt != -1) func(nxt);
        else mx = max(mx, count_broken());
        es[me] += ew[i];
        es[i] += ew[me];
        leaf = false;
    }
    if(leaf) mx = max(mx, count_broken());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> es[i] >> ew[i];
    func(0);
    cout << mx;
    return 0;
}