/*
그리디적인 접근을 요하는 문제.

비행기가 순차적으로 게이트에 들어가야 하기 때문에 비행기를 게이트에 넣을 때
최대한 제한에 가까운 게이트에 넣어야 효율적이라고 생각할 수 있다(그리디)
이때 넣을 수 있는지, 없는지를 판단할 때 배열을 통해 순차적으로 판단하게 되면,
O(N^2) 이므로 시간초과에 걸린다.
따라서, BST를 이용해 O(lgN) 에 가장 가까운 게이트(lower_bound 사용)를 찾으면 되고,
이는 O(NlgN) 이다.
이때 lower_bound에서 반환된 iterator 가 start 를 가르키는데 start 에 있는 수와 찾는 수가 다를 경우,
어느 게이트에도 도킹할 수 없는 것이므로 공항을 폐쇄하면 된다.

# 나올 수 있는 경우(큰 경우, 같은 경우, 작은 경우)를 그려가면서 나눠서 살펴봐야 한다.
# lower_bound 는 찾는 수의 '이상'인 수를 찾는다.
*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005

int g[SIZE];

set<int> BST;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int G, P;
    cin >> G >> P;
    for (int i = 1; i <= G; i++) {
        BST.insert(i);
    }
    for (int i = 1; i <= P; i++) {
        cin >> g[i];
    }
    int cnt = 0;
    for (int i = 1; i <= P; i++) {
        auto it = BST.lower_bound(g[i]);
        if (g[i] != *it) {
            if (it == BST.begin()) break;
            it--;
        }
        BST.erase(it);
        cnt++;
    }
    cout << cnt;
    return 0;
}