#include <bits/stdc++.h>
using namespace std;

vector<int> sel;
int n, m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) sel.push_back((i < m) ? 0 : 1);
    // next_permutation 은 do~while 과 함께 사용
    // 가장 작은 값부터 가장 큰 값이 앞에 올 때까지 사전 순으로 배치
    do {
        for(int i=0; i<n; i++) {
            if(sel[i] == 0) cout << i+1 << ' ';
        }
        cout << '\n';
    } while(next_permutation(sel.begin(), sel.end()));
    return 0;
}