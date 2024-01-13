/*
이분탐색을 이용한 풀이.

두 수를 단순히 선택하면 O(N^2) 이지만, 정렬을 이용한다면 O(NlgN) 으로 줄일 수 있다.
어떤 수 i를 선택했을 때, 차이가 M 이상이면서 가장 작은 차이를 고르려면 i+M 과 같은 수거나, 큰 수중에 가장 작은 수를 찾으면 된다.
따라서 stl 의 lower_bound 를 사용할 수 있다.

# 투포인터로도 풀 수 있다.
*/


#include <bits/stdc++.h>
using namespace std;

int a[100002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int mn = INT_MAX;
	for(int i=0; i<n-1; i++) {
		int idx = lower_bound(a+i+1, a+n, a[i]+m) - a;
		if(idx != n) {
			mn = min(mn, a[idx] - a[i]);
		}
	}
	cout << mn;
	return 0;
}