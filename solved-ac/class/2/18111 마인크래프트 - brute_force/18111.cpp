/*
땅 고르기 하는 과정을 따지는 것은 괴장히 복잡하기에, 일단 주어진 블록이 무한하다고 생각하고 블록을 맘대로 놓거나, 빼면서 시간을 측정한다.
이후 땅이 고르게 되었을 때 현재 블록이 유효한 개수인지를 확인하면 된다. 만약 유효할 경우, 최단 시간인지 확인한다.

# 얼핏 보면 그래프, 백트래킹 문제 같지만, 그렇게 풀 수 있을지도 의문이고 풀어도 효율적이라고는 할 수 없다.
# 땅 고르기 하는 과정을 모두 따지는 것은 굉장히 복잡하다. 고르기를 하는 과정에 초점을 두기보다 
고르고 난 이후에 정상적인 고르기 과정을 거쳤는지 확인하는게 더 쉬울 것이다.
# M, N, 땅의 높이를 관찰하니 brute force 가 가능하지 않을까? O(500 * 500 * 256) 이기 때문.
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int block[502][502];

int main()
{
    int n, m;
    ll b;
    int mn = 256;
    int mx = 0;
    cin >> n >> m >> b;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> block[i][j];
            mn = min(mn, block[i][j]);
            mx = max(mx, block[i][j]);
        }
    }
    int ans = INT_MAX;
    int ansh = 0;
    for(int i=mn; i<=mx; i++) {
        int cnt = 0;
        ll curb = b;
        for(int x=0; x<n; x++) {
            for(int y=0; y<m; y++) {
                int diff = i - block[x][y];
                if(diff == 0) continue;
                if(diff > 0) {
                    cnt += diff;
                    curb -= diff;
                }
                else {
                    cnt += (-diff) * 2;
                    curb += (-diff);
                }
            }
        }
        if(ans >= cnt && curb >= 0) {
            ans = cnt;
            ansh = i;
        }
    }
    cout << ans << ' ' << ansh;
    return 0;
}