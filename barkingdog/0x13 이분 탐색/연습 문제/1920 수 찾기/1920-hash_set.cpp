/*
이진탐색 의 경우 O(NlgN + MlgN) 이고 
해시를 이용한 탐색의 경우 O(N + M) 이다.
그런데 왜 실제 결과에서는 이진탐색이 더 빠르게 나올까?
*/

#include <bits/stdc++.h>
using namespace std;

unordered_set<int> a;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x;
    for(int i=0; i<n; i++) {
        cin >> x;
        a.insert(x);
    }
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> x;
        cout << (a.find(x) != a.end()) << '\n';
    }
	return 0;
}