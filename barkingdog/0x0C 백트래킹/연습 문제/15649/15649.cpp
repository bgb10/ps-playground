#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10]; // isused 는 깊이가 다른 노드 간의 중복을 막기 위해 사용

void func(int k) { // k 는 트리의 깊이, 수열에 포함된 수를 의미
    // 깊이가 m 이 된 경우 이전 항(k-1)에서 수열이 완성된 것이므로 출력
    if(k == m) {
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    // 깊이가 m 이 되지 않은 경우 수열을 완성하기 위해 재귀함수 호출
    for(int i=1; i<=n; i++) {
        if(isused[i]) continue;
        isused[i] = true;
        arr[k] = i;
        func(k+1);
        isused[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0); // 깊이가 0인 트리부터 백트래킹
    return 0;
}