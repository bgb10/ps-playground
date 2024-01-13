/*
STL 의 priority queue 를 사용한 풀이

compare 함수를 작성해서 PQ 의 우선순위가 될 수의 기준을 주었다.
절대값이 작은 경우를 루트에 놓고, 같은 경우는 수가 더 작은 경우를 루트에 두도록
했다.

# compare 함수만 잘 작성하면 되는 쉬운 문제이다.
# 비어있는 PQ에 top, pop 을 하면 런타임 에러가 나니 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;

class cmp {
   public:
    bool operator()(int a, int b) {
        if (abs(a) != abs(b)) return abs(a) > abs(b);
        return a > b;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    priority_queue<int, vector<int>, cmp> PQ;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (PQ.empty())
                cout << 0 << '\n';
            else {
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        } else {
            PQ.push(x);
        }
    }
}