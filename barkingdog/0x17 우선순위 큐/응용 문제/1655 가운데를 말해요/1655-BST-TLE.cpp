/*
BST 를 이용한 풀이.

시간복잡도는 O(NlgN) 이다.
시간제한이 0.1초인데, BST는 굉장히 느린 NlgN이므로 터질 가능성이 매우 높다.
*/
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> MS;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        MS.insert(x);
        auto it = MS.begin();
        auto ite = MS.end();
        ite--;
        auto mid = distance(it, ite) / 2;
        advance(it, mid);
        cout << *it << '\n';
    }
    return 0;
}