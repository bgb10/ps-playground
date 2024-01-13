#include <bits/stdc++.h>
using namespace std;

int a[500002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n); // 이분 탐색을 진행하기 위해 정렬
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        cout << binary_search(a, a+n, x) << ' ';
    }
	return 0;
}