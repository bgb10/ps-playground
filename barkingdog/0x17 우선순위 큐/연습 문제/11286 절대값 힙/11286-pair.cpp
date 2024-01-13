/*
STL 의 priority queue 를 사용한 풀이

절대값 처리와 간단한 정렬을 위해 pair 를 사용했다.
first 에는 수의 절대값을 주고, second 에는 원래 값을 준다. 그렇게 되면 최소힙으로
우선순위 큐를 돌릴 때 먼저 절대값 순으로 비교해서 작은 수를 우선하고,
절대값이 같을 경우는 작은 수, 즉 음수인 수를 우선한다.
*/

#include <bits/stdc++.h>
using namespace std;

#define abs first
#define ori second

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (PQ.empty())
                cout << 0 << '\n';
            else {
                auto t = PQ.top();
                cout << t.ori << '\n';
                PQ.pop();
            }
        } else {
            if (x > 0) {
                PQ.push({x, x});
            } else {
                PQ.push({-x, x});
            }
        }
    }
}