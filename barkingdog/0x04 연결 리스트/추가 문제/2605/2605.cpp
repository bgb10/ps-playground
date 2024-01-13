#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    list<int> L;
    int b;
    auto it = L.end();
    for(int i=1; i<=n; i++) {
        cin >> b;
        while(b--)
            it--;
        L.insert(it, i);
        it = L.end();
    }
    for(int a : L)
        cout << a << ' ';

    return 0;
}