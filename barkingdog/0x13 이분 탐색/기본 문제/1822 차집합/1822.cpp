/*
BST 로도 풀 수 있고, 해시 맵으로도 풀 수 있고, 이진 탐색으로도 풀 수 있다.
여기서는 이진 탐색으로 풀었다.

n = 500000 일때
O(nlgn 정렬 + nlgn 정렬 + nlgn a의 원소가 b에 있는지 탐색) = O(nlgn)이다.
*/

#include <bits/stdc++.h>
using namespace std;

int a[500002];
int b[500002];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int na, nb;
    cin >> na >> nb;
    for(int i=0; i<na; i++) {
        cin >> a[i];
    }
    sort(a, a+na);
    for(int i=0; i<nb; i++) {
        cin >> b[i];
    }
    sort(b, b+nb);
    vector<int> ans;
    for(int i=0; i<na; i++) {
        if(!binary_search(b, b+nb, a[i])) ans.push_back(a[i]);
    }
    if(ans.empty()) cout << 0;
    else {
        cout << ans.size() << '\n';
        for(int i : ans) {
            cout << i << ' ';
        }
    }
	return 0;
}