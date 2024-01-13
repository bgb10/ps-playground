/*
상황을 관찰해서 풀 수 있는 그리디 문제.

현재 일수에서 주식을 매수할지 말지는 이후의 주가에 따라 결정되기 때문에, 앞에서는 결정할 방법이 없다.
따라서, 뒤에서부터 주식이 가장 비쌀때를 찾고 그 앞에 일자에서 주식이 그보다 싸다면 매수하면 된다.

무식하게 경우의 수를 구하면 O(2^N) 이겠지만, 관찰을 통해 탐색 범위를 줄여서 O(N)이 되었다.

# 1일부터 n일까지 차례로 보는 대신에 n일에서 이전 일수를 바라보는 '거꾸로 보는 시각'이 필요하다.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1000002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        int sell = a[n-1];
        for(int i=n-2; i>=0; i--) {
            if(a[i] > sell) {
                sell = a[i];
            }
            else {
                ans += sell - a[i];
            }
        }
        cout << ans << '\n';
    }
	return 0;
}