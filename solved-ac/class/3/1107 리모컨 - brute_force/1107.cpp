/*
brute force 로 푸는 문제. 얼핏 보면 1차원 BFS 처럼 보이지만... 사실 아니다!

목표인 채널과 가장 가까운 채널로 이동한 후 - 또는 + 버튼을 이용해 이동하면, 그게 바로 최소다.
이때 가장 가까운 채널이라도 이동할 수 없는 버튼을 통해 나온 채널일 수 있다.
따라서, 0번 채널부터 모든 채널을 다 돌면서 숫자 버튼을 통해 이동할 수 있는 채널인 경우, 목적지까지의 거리를 재면 된다.
이때 탐색할 가장 큰 채널은 1,000,000 으로 했다. 
현재 100 에 위치해 있기 때문에 무식하게 + 또는 - 버튼으로만 이동해도 500,000 번 이하로 나오기 때문이다.

시간복잡도는 대략 O(1000000 * 7) 이므로, 충분히 시간안에 들어온다.
*/

#include <bits/stdc++.h>
using namespace std;

bool broken[11]; // vector 에 고장난 버튼을 저장하면 탐색 비용 O(10) 이 들기 때문에 역인덱스 또는 해시 사용해서 O(1)로 줄일 수 있다.

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int t;
        cin >> t;
        broken[t] = 1;
    }
    if(n == 100) {
        cout << 0;
        return 0;
    }
    int mn = abs(n - 100);
    for(int i=0; i<=1000000; i++) {
        string s = to_string(i);
        bool movable = true;
        for(char c : s) {
            if(broken[c - '0'] == 1) {
                movable = false;
                break;
            }
        }
        if(movable) {
            int cnt = s.length() + abs(n - i);
            mn = min(mn, cnt);
        }
    }
    cout << mn;
	return 0;
}