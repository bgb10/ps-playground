/*
STL 의 priority queue 를 사용한 풀이
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int x;
	priority_queue<int> PQ;
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