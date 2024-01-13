/*
STL의 unique 를 사용해서 구현
*/

#include <bits/stdc++.h>
using namespace std;

int x[1000002];
vector<int> uni;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        uni.push_back(x[i]);
    }
    // 정렬
    sort(uni.begin(), uni.end());
    // STL unique 를 사용해서 중복 원소 제거(원소가 정렬되어있을 때만 사용 가능)
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    // 정렬된 배열에서 수의 위치 검색 (이분 탐색)
    for(int i=0; i<n; i++) {
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
	return 0;
}