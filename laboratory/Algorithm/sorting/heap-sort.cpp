/*
Heap Sort (힙 정렬)

우선순위 큐를 구현하기 위해 만들어진 힙 자료구조를 사용해서 정렬을 하는 방법

시간복잡도: O(NlgN)
*/

#include <bits/stdc++.h>
using namespace std;

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;

void printArray() {
  for(int i=0; i<n; i++) {
    cout << arr[i] << ' ';
  }
}


int main() {
	priority_queue<int, vector<int>, greater<int>> PQ;
	// 최소 힙에 n 개의 원소를 넣느라 NlgN 사용
	for(int i=0; i<n; i++) {
		PQ.push(arr[i]);
	}
	// 최소 힙의 루트 노드를 탐색하는데 O(1), 삭제 O(lgN) 사용
	// 순회하는데 드는 비용 N 까지 포함해서 O(NlgN)
	for(int i=0; i<n; i++) {
		arr[i] = PQ.top(); PQ.pop();
	}
	printArray();
	return 0;
}