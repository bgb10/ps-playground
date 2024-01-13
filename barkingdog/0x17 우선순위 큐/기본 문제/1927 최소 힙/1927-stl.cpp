/*
STL 의 priority queue 를 사용한 풀이
priority_queue 의 기본값이 최대 힙이기 때문에 최소 힙으로 바꿔주려면 따로 인자를 줘야 한다.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int x;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x == 0) {
			if(PQ.empty()) cout << 0 << '\n';
			else {
				cout << PQ.top() << '\n';
				PQ.pop();
			}
		}
		else {
			PQ.push(x);
		}
	}
}