/*
그리디와 허프만 코딩 개념이 들어간 문제이다.

두 파일이 합쳐지고 나서 또 하나의 파일이 되고, 나중에 이 파일이 또 합쳐져야 한다.
합쳐질 때마다 비용이 발생하므로, 합쳐진 파일이 최대한 작은 크기를 가져야 한다.
따라서, 매 순간마다 최소 크기인 2개의 파일을 선택하면 된다. (그리디 적인 접근)

매 순간마다 최소를 구하고(확인), 또 새로 만들어진 파일을 다시 저장해야 하므로(삽입)
우선순위 큐를 활용할 수 있다.

# 2075 N번째 큰 수와 정확히 똑같은 문제다.
# 허프만 코딩의 개념이 들어간 문제다.
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        priority_queue<ll, vector<ll>, greater<ll>> PQ;
        int x;
        for(int i=0; i<k; i++) {
            cin >> x;
            PQ.push(x);
        }
        long long ans = 0;
        while(PQ.size() != 1) {
            ll a = PQ.top();
            PQ.pop();
            ll b = PQ.top();
            PQ.pop();
            ans += a+b;
            PQ.push(a+b);
        }
        cout << ans << '\n';
    }
    return 0;
}