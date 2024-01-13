#include <bits/stdc++.h>
using namespace std;

// 야매 circular linked list 구현
// 배열을 읽을 때 배열 안 인덱스를 먼저 읽으면 이해하기 편하다.
// ex. pre[nxt[addr]] : addr 의 다음 노드(nxt)의 이전 노드(pre)

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX]; // -1로 초기화
int unused = 1; // 0번은 더미 데이터

void insert(int addr, int num){
  dat[unused] = num;
  pre[unused] = addr;
  nxt[unused] = nxt[addr];
  if(nxt[addr] != -1) {
    pre[nxt[addr]] = unused;
  } else {
    pre[0] = unused; // 추가하는 위치가 마지막이었을 경우
  }
  nxt[addr] = unused;
  unused++;
}

void erase(int addr){
  if(nxt[addr] != -1) {
    pre[nxt[addr]] = pre[addr];
  } else {
    pre[0] = pre[addr]; // 삭제하는 위치가 마지막이었을 경우
  }
  nxt[pre[addr]] = nxt[addr];
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void last_element() {
  cout << "last: " << dat[pre[0]] << "\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  last_element();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
  last_element();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  last_element();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
  last_element();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();
}