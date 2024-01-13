/*
parametric search 를 이용한 풀이.

최대 랜선의 길이를 구하는 것을(최적화 문제), 랜선의 길이가 i 일때 n 보다 많이 랜선이 나오는가?(결정 문제)로 치환해서 푸는 문제이다.
랜선의 길이에 따른 랜선의 개수가 감소 함수(단조 함수) 형태이기 때문에 parametric search 를 사용해도 된다.
시간복잡도는 O(lg(2^31) * K) 이므로, O(K) 이다.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int k, n;
ll line[10001];

bool solve(ll x) {
    ll cur = 0;
    for(int i=0; i<k; i++) cur += line[i] / x;
    return cur >= n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i=0; i<k; i++) {
        cin >> line[i];
    }
    ll st = 1; ll en = INT_MAX;
    while(st < en) {
        ll mid = (st + en + 1) / 2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
    return 0;
}