/*
knapsack 문제의 일종으로, 그리디와 함께 적절한 자료구조(이진검색 트리)를 선택해야 하는 문제.

우선 0-1 knapsack 문제와 다르게 문제를 DP로 분할해서 풀 여지가 보이지 않는다.
문제를 관찰해보면, 가장 가격이 높은 보석부터 확인하며 담을 수 있는 최대 무게가 작은 가방부터 채워넣는게 최대 가격을
만드는 것이라는 판단을 할 수 있다.
왜냐하면 하나의 가방은 하나의 보석만 담을 수 있고, 최대한 가치가 높은 보석을 많이 담아야 하기 때문이다.
이때 단순 배열을 정렬해서 풀이한다면 각 배열을 정렬하는데 O(lgN), O(lgK) 가 들고, 
보석을 담을 수 있는 가방을 찾는데 O(NlgK)가 든다. 하지만 이미 담은 가방을 처리해야 하므로
배열의 삭제에 O(K) 가 추가로 들어 총 시간복잡도는 O(NKlgK) 가 되어 시간초과가 난다.

이 문제는 원소의 추가, 삭제가 빈번하고, 정렬이 필요로 하고, 최대, 최소값을 필요로 하는 문제이다.
따라서, 이 모든 것들을 O(lgK) 에 할 수 있는 이진검색트리를 사용해야 함을 짐작할 수 있다.

# 상황에 맞는 적절한 자료구조를 선택하자.
# 최대 가치가 int 범위를 초과할 수 있음에 주의하자.
*/

#include <bits/stdc++.h>
#define V first
#define M second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> jewel[300003];
    for(int i=0; i<n; i++) {
        cin >> jewel[i].M >> jewel[i].V;
    }
    sort(jewel, jewel+n);
    multiset<int> bag;
    int c;
    for(int i=0; i<k; i++) {
        cin >> c;
        bag.insert(c);
    }
    long long cnt = 0;
    for(int i=n-1; i>=0; i--) {
        auto it = bag.lower_bound(jewel[i].M);
        if(it != bag.end()) {
            cnt += jewel[i].V;
            bag.erase(it);
        }
    }
    cout << cnt;
    return 0;
}