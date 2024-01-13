#include <bits/stdc++.h>
using namespace std;

// pair 는 보통 좌표값을 데이터와 함께 저장할 때 사용
// 내 이전 풀이는 뒤에서 부터 접근 했는데, 이분은 앞에서부터 접근
// 앞에 dummy data 를 넣어서 예외처리 없이 쉽게 풀 수 있도록 한 센스...

int N;
stack<pair<int, int>> tower;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    tower.push({100000001, 0}); // 더미데이터 넣어주는게 신의 한수.
    for(int i=1; i<=N; i++) {
        int h;
        cin >> h;
        while(tower.top().first < h)
            tower.pop();
        cout << tower.top().second << " ";
        tower.push({h, i});
    }

    return 0;
}