#include <bits/stdc++.h>
using namespace std;

int arr[22];
int n, s;
int cnt;

void func(int k, int tot) {
    if(k == n) { // 모든 원소의 포함 여부를 한번씩 다 결정한 경우
        if(tot == s) 
            cnt++;
        return;
    }
    // 해당 항에서 같은 높이의 노드들을 모두 처리 및 다음 항 호출
    // 다른 문제들도 위와 비슷하게 작성
    func(k + 1, tot); // 포함 X
    func(k + 1, tot + arr[k]); // 포함 O
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--; // 공집합 제외
    cout << cnt;
    return 0;
}