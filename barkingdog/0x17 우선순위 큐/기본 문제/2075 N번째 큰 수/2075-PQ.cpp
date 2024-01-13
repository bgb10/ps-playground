/*
메모리 제한을 맞추기 위해 우선순위 큐를 적절히 활용해야 하는 문제.

우선순위 큐의 요소의 개수를 n개로 유지하고, 최소힙을 구하면 그것이 n번째 큰 수이다.
수를 읽을 때마다 우선순위 큐에 무조건 집어넣되, 루트는 계속해서 삭제해주면 된다.
시간복잡도는 O(N^2lg(N^2)) 이다.

# 메모리 제한에 주의하자. 메모리 제한이 널널하다면 그냥 다 넣고 위에서부터 n개 빼도 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> PQ;
    // PQ에 5개의 수 넣기
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        PQ.push(x);
    }
    // 5개의 수를 유지하면서 수를 계속 넣고, root 를 빼기.
    int sz = n * n;
    for (int i = n; i < sz; i++) {
        cin >> x;
        PQ.push(x);
        PQ.pop();
    }
    cout << PQ.top();
    return 0;
}