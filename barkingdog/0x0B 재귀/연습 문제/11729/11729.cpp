#include <bits/stdc++.h>
using namespace std;

int hanoiCount(int n) {
    if(n == 1) return 1;
    return 2 * hanoiCount(n-1) + 1;
}

void hanoi(int from, int to, int n) {
    if(n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    hanoi(from, 6-from-to, n-1);
    hanoi(from, to, 1);
    hanoi(6-from-to, to, n-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    // cout << hanoiCount(n) << '\n';
    cout << (1<<n) - 1 << '\n';
    hanoi(1, 3, n);

    return 0;
}