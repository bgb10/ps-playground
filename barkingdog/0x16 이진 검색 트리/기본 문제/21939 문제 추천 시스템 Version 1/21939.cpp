/*
우선순위 큐와 집합과 맵을 동시에 사용해야 하는 문제.

최대값(가장 어려운 문제), 최소값(가장 쉬운 문제)이 존재하고, 
삽입, 삭제, 조회가 빈번한 경우 '이진 검색 트리' 로 해결할 수 있다.
set 에 <문제 번호, 난이도> 로 저장한다면 삽입할 때마다 정렬이 되어 최소, 최대를 구하기 용이하다.

이미 난이도가 정해진 문제가 난이도가 변경될 수 있기 때문에, 이를 unordered_map(해시 맵) 으로 처리할 수 있다.
해시맵에는 어떤 문제 번호에 대해 가장 마지막에 들어간 난이도가 저장될 것이고, 이것과 비교해서
다를 경우 트리에서 제거해주면 된다.

# 변수나 순서를 똑바로 정하자. 문제는 P, 난이도는 L 이고, add 에서 주어질 때 P 다음 L 순으로 주어진다.
# 상황에 맞는 적절한 자료구조를 선택하자. 이 문제는 set 만으로는 해결할 수 없으니, 다른 자료구조도 같이 사용해야 한다.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	set<pair<int, int>> recommendation;
	unordered_map<int, int> P2L;
	for(int i=0; i<n; i++) {
		int P, L; 
		cin >> P >> L;
		recommendation.insert({L, P});
		P2L[P] = L;
	}
	cin >> n;
	for(int i=0; i<n; i++) {
		string cmd;
		cin >> cmd;
		int P, L;
		if(cmd == "add") {
			cin >> P >> L;
			recommendation.insert(make_pair(L, P));
			P2L[P] = L;
		}
		else if(cmd == "solved") {
			cin >> P;
			recommendation.erase(make_pair(P2L[P], P));
			P2L.erase(P);
		}
		else {
			int k;
			cin >> k;
			if(k == -1) {
				int P = (*recommendation.begin()).second;
				while(P2L[P] != (*recommendation.begin()).first) {
					recommendation.erase(recommendation.begin());
					P = (*recommendation.begin()).second;
				}
				cout << (*recommendation.begin()).second << '\n';
			}
			else {
				int P = (*prev(recommendation.end())).second;
				while(P2L[P] != (*prev(recommendation.end())).first) {
					recommendation.erase(prev(recommendation.end()));
					P = (*prev(recommendation.end())).second;
				}
				cout << (*prev(recommendation.end())).second << '\n';
			}
		}
	}
	return 0;
}