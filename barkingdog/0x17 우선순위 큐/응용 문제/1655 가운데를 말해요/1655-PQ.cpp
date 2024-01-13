/*
수학적으로 상황을 정리하고, 우선순위 큐를 이용해 푸는 문제. Median-heap 알고리즘으로 알려져있다.

수를 입력할 때마다 '중간값' 을 찾아야 하는데, 중간값은 계속 변할 수 있다.
이때 중간값은 현재 중간값 위치에서 왼쪽 또는 오른쪽으로 한칸씩만 이동하면 된다.
이를 이용해, 현재 중간값이 정해졌다고 가정했을 때 "추후 중간값이 될 값을 생각해보면",
i) 중간값보다 큰 값 중 최소 값
ii) 중간값보다 작은 값 중 최대 값
이라고 생각할 수 있다.
i), ii) 를 구현하기 위해 최소/최대 힙을 사용하면 된다.
이후 수가 들어옴에 따라 최소/최대 힙의 균형을 유지하면서 중간값을 구하면 된다.

시간복잡도는 힙의 균형을 유지하는 경우 3lgN(삽입 -> 삭제 -> 삽입) 이기 때문에 O(3NlgN) = O(NlgN) 이 된다.

# 힙 2개를 이용하는 재밌는 문제다.
*/
#include <bits/stdc++.h>

#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> min_PQ;  // 중간값보다 큰 값 중 최소 힙
    int mid = 0;
    priority_queue<int, vector<int>, greater<int>> max_PQ;  // 중간값보다 작은 값 중 최대 힙
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            mid = x;
        } else {
            if (x < mid) {
                min_PQ.push(x);
            } else {
                max_PQ.push(x);
            }
            // 불균형 해소 및 중간값 구하기.
            // 왼쪽으로 쏠린 경우
            if (min_PQ.size() >= max_PQ.size() + 1) {
                max_PQ.push(mid);
                mid = min_PQ.top();
                min_PQ.pop();
            }
            // 오른쪽으로 쏠린 경우
            else if (min_PQ.size() + 2 <= max_PQ.size()) {
                min_PQ.push(mid);
                mid = max_PQ.top();
                max_PQ.pop();
            }
        }
        cout << mid << '\n';
    }

    return 0;
}