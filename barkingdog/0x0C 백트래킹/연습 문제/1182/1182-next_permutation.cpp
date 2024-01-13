#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int choose[30];
int cnt = 0;

void solve() {
    do {
        int tot = 0;
        for(int i=0; i<n; i++)
            if(choose[i] != 0)
                tot+=arr[i];
        if(tot == s)
            cnt++;
    } while(next_permutation(choose, choose+n));
}

// next_permutation 사용
// 순열: 각각 다른 수를 넣어줌
// 조합: 0과 1로 수를 넣어줌
/* 해당 문제에서는 n개의 수 중에서 부분집합을 뽑는 순열 문제
0개를 뽑거나 ~ n개를 뽑거나 */
void permutation() {
    for(int i=0; i<n; i++) {
        fill(choose+n-i, choose+n, 1);
        solve();
        fill(choose, choose+n, 0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    permutation();
    if(s == 0) cnt--;
    cout << cnt;
    return 0;
}