/*
백트래킹이 시간초과가 나서 안될 것 같지만, 백트래킹으로 푸는 문제

각 자리에 숫자 1, 2, 3 을 추가하고, 이를 DFS 형식으로 최대한 작은 숫자를 추가한다.
만약 나쁜수열일 경우 부모 노드로 돌아가서 pruning을 하면 된다.

나쁜 수열인 것을 확인하는 것이 O(N^2) 이고, pruning 이 안된다는 전제 하에 O(2^N) 이라 백트래킹이 아닐 줄 알았다.
하지만 백트래킹으로 풀어본 결과 거의 모든 가지가 극적으로 가지치기가 되어서, N=5000 일때도 1초 안에
결과가 나온다.

# 백트래킹으로 안될 것 같다고 해도, 그 방법밖에 떠오르지 않으면 일단 해보자. pruning 이 극적으로 될 경우
충분히 시간안에 들어올 수 있다.
# short circuit evaluation 을 사용해 깔끔하게 풀이했다.
*/

#include <bits/stdc++.h>
using namespace std;

int n;

// O(N^2)
bool check(string s, int k) {
    for(int len=1; len<=k/2; len++) {
        int st = k - len * 2;
        if(s.substr(st, len) == s.substr(st + len, len)) return false;
    }
    return true;
}

bool solve(string s, int k) {
    if(k == n) {
        cout << s;
        return true;
    }
    return (check(s + "1", k+1) && solve(s + "1", k+1)) ||
    (check(s + "2", k+1) && solve(s + "2", k+1)) ||
    (check(s + "3", k+1) && solve(s + "3", k+1));
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve("1", 1) || solve("2", 1) || solve("3", 1); // short circuit evaluation
	return 0;
}