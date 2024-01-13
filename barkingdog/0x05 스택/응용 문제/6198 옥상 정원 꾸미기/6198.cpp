#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int arr[80001];
stack<pair<int, int>> S; // X: 건물의 높이, Y: 건물이 가린 건물
long long cnt = 0;
int destroyed = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=n-1; i>=0; i--)
        cin >> arr[i];
    S.push({INT_MAX, 0});
    for(int i=0; i<n; i++) {
        while(S.top().X < arr[i]) {
            cnt += S.top().Y + 1; // 앞의 건물 뿐만 아니라 앞의 건물이 가린 건물도 모두 보이므로, 그것도 포함해야 함.
            destroyed += S.top().Y + 1; // 내가 가린 건물 개수는 앞 건물과 앞 건물이 가린 건물
            S.pop();
        }
        S.push({arr[i], destroyed});
        destroyed = 0;
    }
    cout << cnt;
    return 0;
}