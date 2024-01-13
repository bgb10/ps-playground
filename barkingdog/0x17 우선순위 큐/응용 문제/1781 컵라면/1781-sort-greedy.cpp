/*
정렬, 그리디와 함께 우선순위 큐를 사용해야 하는 문제. 논리적인 증명을 요하는 문제다.

데드라인(D)와 컵라면(C)이 섞여 있으면 알고리즘을 짜기 어렵다는 생각이 들어 D와 C 순으로 오름차순 정렬한다.

현재 정렬된 D, C 배열에서 i번째까지 읽고, k일까지 l(l <= k)개의 문제를 풀었다고 가정하자.
이때 i+1 번째 문제에 대해, C가 여태까지 푼 문제의 최소 C보다 크다면?
-> 최소 C를 가진 문제(m)를 풀지 말고 i+1 문제를 풀면 된다.
이때 D 순으로 정렬되어 있기 때문에 기존의 문제를 대체해도 상관이 없다.
i+1 문제는 D가 m 보다 크거나 같기 때문이다. (m보다 같은 데드라인을 가지거나 더 나중에 풀어도 되는 문제)

시간복잡도는 O(NlgN) 이다.
*/
#include <bits/stdc++.h>

#define D first
#define C second
using namespace std;
using ll = long long;

vector<pair<int, ll>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int d;
        ll c;
        cin >> d >> c;
        V.push_back({d, c});
    }
    sort(V.begin(), V.end());
    priority_queue<int, vector<int>, greater<int>> min_PQ;
    for (auto i : V) {
        if (min_PQ.size() < i.D) {
            min_PQ.push(i.C);
        } else {
            if (min_PQ.top() < i.C) {
                min_PQ.pop();
                min_PQ.push(i.C);
            }
        }
    }
    ll ans = 0;
    while (!min_PQ.empty()) {
        ans += min_PQ.top();
        min_PQ.pop();
    }
    cout << ans;
    return 0;
}