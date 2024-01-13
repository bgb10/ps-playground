/*
정렬된 배열에서는 같은 수가 서로 인접해있다는 성질을 이용한 풀이.
정렬된 배열이기 때문에 좌표를 찾을 때 선형으로 O(N^2) 찾을 필요 없이 이분 탐색 O(NlgN)을 사용한다. 
*/

#include <bits/stdc++.h>
using namespace std;

int x[1000002];
int s[1000002];
vector<int> uni;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        s[i] = x[i];
    }
    // 정렬
    sort(s, s+n);
    // 정렬된 배열에는 같은 원소들이 서로 인접해있는 성질 이용해서 중복 제거
    uni.push_back(s[0]);
    int bf = s[0];
    for(int i=1; i<n; i++) {
        if(bf == s[i]) continue;
        uni.push_back(s[i]);
        bf = s[i];
    }
    // 정렬된 배열에서 수의 위치 검색 (이분 탐색)
    for(int i=0; i<n; i++) {
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
    }
	return 0;
}