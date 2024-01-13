#include <bits/stdc++.h>

#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;
#define X first
#define Y second

set<pair<int, int>> BST;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // std::set 이 random-access iterator 가 아니기 때문에 stl에 있는 lower_bound 를 사용하면 느리다.
        // 이분 탐색을 진행할 때 iterator 가 random-access 를 지원한다는 전제하에 하기 때문에, logN이 최대 logN번 진행될
        // 수 있는 듯. auto it = lower_bound(BST.begin(), BST.end(), make_pair(x, 0));

        // 따라서 BST의 lower_bound 멤버 함수를 사용하면 된다.
        auto it = BST.lower_bound(make_pair(x, 0));
        if (it == BST.begin()) {
            BST.insert({x, 1});
        } else {
            it--;
            int dp = (*it).Y + 1;
            ans = max(ans, dp);
            BST.insert({x, dp});
        }
    }
    cout << ans;
    return 0;
}