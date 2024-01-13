#include <bits/stdc++.h>
using namespace std;

const int MX = 3;
int dat[MX];
int head = 0, tail = 0;

void push(int x){
    dat[tail++] = x;
    if(tail == MX) tail = 0;
}

void pop(){
    head++;
    if(head == MX) head = 0;
}

int front(){
    return dat[head];
}

int back(){
  if(tail == 0) return dat[MX-1];
  return dat[tail-1];
}

void test(){
  push(10); push(20); push(30);
  cout << front() << '\n'; // 10
  cout << back() << '\n'; // 30
  pop(); pop();
  push(15); push(25); // 사이즈 이상으로 push 했는데도 앞에서 pop 을 2번 했고, circular 이기 때문에 정상 작동
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 25
}

int main(void) {
  test();  
}