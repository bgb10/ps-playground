/*
BST 의 성질을 이용해서 풀 수 있는 문제

단순하게 모든 수를 BST에 넣으면 메모리 초과가 나온다. 2억개의 int 가 저장되기 때문.
수를 일부만 저장하고 문제를 해결할 방안을 찾아야 하는데,
BST 내의 원소를 5개만 유지하면서 원소가 들어올 때마다 가장 작은 원소를 하나씩 빼서 원소의 크기 5개를 유지한다.
모든 원소를 다 들여보냈으면, 답은 BST 의 가장 작은 원소이다.
공간복잡도는 O(5개의 int) 이고, 시간복잡도는 N^2lg(N^2) 이다.

# 정말 쉬운 문제인데 착각해서 돌고 돌아 풀었다. 문제를 먼저 완전히 이해하고 풀자.
# 매 순간마다 정렬을 하게 되면 N^2 * N^2lgN(N^2) 이다. 문제를 읽어보면
# 굳이 매 순간마다 정렬할 필요 없이 각 순간의 최소값만 알면 됨을 알 수 있다.
# 정렬을 하게되면, 나머지 값들도 모두 순서가 정렬되기 때문에 시간 낭비가 된다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sz = n * n;
    set<int> S;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        S.insert(x);
    }
    for (int i = n; i < sz; i++) {
        cin >> x;
        S.insert(x);
        S.erase(S.begin());
    }
    cout << *S.begin();
    return 0;
}