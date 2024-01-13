/*
문제를 잘못 이해한 그리디 풀이.

데드라인이 2인 경우, 1일 때도 끝낼 수 있다는 것을 고려하지 못했다.
해당 풀이는 데드라인이 임박했을 경우만 문제를 푼다.
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
    sort(V.begin(), V.end(), greater<pair<int, ll>>());
    int cur_d = 0;
    ll cnt = 0;
    for (auto i : V) {
        if (cur_d == i.D) continue;
        if (cur_d == 0) {
            cur_d = i.D;
            cnt += i.C;
            continue;
        }
        cur_d = i.D;
        cnt += i.C;
    }
    cout << cnt;
    return 0;
}