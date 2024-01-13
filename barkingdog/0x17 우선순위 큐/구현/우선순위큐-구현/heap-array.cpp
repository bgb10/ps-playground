#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
	sz++;
	heap[sz] = x;
	int idx = sz;
	while(idx != 1) {
		int par = idx / 2;
		if(heap[par] < heap[idx]) break;
		swap(heap[par], heap[idx]);
		idx = par;
	}
}

int top(){
	return heap[1];
}

void pop(){
	swap(heap[1], heap[sz]); // 루트와 마지막 자식을 교환
	sz--;
	int idx = 1;
	while(2*idx <= sz) { // 왼쪽 자식의 인덱스보다 사이즈가 크거나 같을 때만 반복
		int lc = 2*idx, rc = 2*idx+1;
		int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
		if(rc <= sz && heap[lc] > heap[rc]) // 오른쪽 자식이 존재하고 오른쪽 자식이 왼쪽 자식보다 작다면
			min_child = rc; // 작은 자식을 오른쪽 자식으로 변경
		if(heap[idx] <= heap[min_child]) break; // 작은 자식이 부모보다 더 큰 경우 더이상 교환할 필요가 없으므로 종료
		swap(heap[idx], heap[min_child]);
		idx = min_child;
	}
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}