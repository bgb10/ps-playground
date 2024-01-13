#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
	sz++;
	heap[sz] = x;
	int cur = sz;
	while(heap[cur] < heap[cur/2]) {
		if(cur == 1) break;
		swap(heap[cur], heap[cur/2]);
		cur /= 2;
	}
}

int top(){
	if(sz == 0) return -1;
	return heap[1];
}

void pop(){
	if(sz == 0) return;
	swap(heap[1], heap[sz]);
	sz--;
	int cur = 1;
	while(2*cur <= sz) {
		int lc = 2*cur, rc = 2*cur+1;
		int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
		if(rc <= sz && heap[lc] > heap[rc])
			min_child = rc;
		if(heap[cur] <= heap[min_child]) break;
		swap(heap[cur], heap[min_child]);
		cur = min_child;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int x;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x == 0) {
			int ans = top();
			if(ans == -1) cout << 0;
			else cout << top();
			cout << '\n';
			pop();
		}
		else {
			push(x);
		}
	}
}