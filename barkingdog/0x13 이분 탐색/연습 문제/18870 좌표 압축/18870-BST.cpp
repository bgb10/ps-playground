/*
BST 를 사용한 풀이.

하지만 시간초과가 나는데, BST 는 노드 할당이나 자가균형 트리 유지를 위한 자원이 많이 들기 때문에
NlgN 이라도 느린 NlgN 에 속한다. N=100만일 경우 TLE가 나올 가능성이 크다.
BST는 삽입, 삭제가 빈번한 상황에서 쓰자. 이 문제에서는 사실 삽입은 많이 일어나지만, 삭제는 많이 일어나지 않으니
이분 탐색으로 충분히 해결할 수 있다.
*/

#include <bits/stdc++.h>
using namespace std;

int x[1000002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> S;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        S.insert(x[i]); // 중복을 허용하지 않는 BST 이기 때문에 자동으로 중복 제거
    }
    for(int i=0; i<n; i++) {
        cout << distance(S.begin(), S.find(x[i])) << ' ';
    }
	return 0;
}