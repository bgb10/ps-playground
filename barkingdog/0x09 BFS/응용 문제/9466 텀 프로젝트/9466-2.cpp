#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005
int team[SIZE]; // team 미결정 -1, 없음 0, 있음 1, 방문 중 2
int sel[SIZE];

queue<int> Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fill(team, team+n+1, -1);
        for(int i=1; i<=n; i++)
            cin >> sel[i];
        for(int i=1; i<=n; i++) {
            if(team[i] != -1) continue;
            team[i] = 2;
            // 기본적으로 방문시 팀을 구성하지 못하는 것으로 넣어준다.
            // 이후 사이클이 형성되게 된다면 그 부분만 팀을 구성한다고 해주면 된다.
            Q.push(i);
            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                int nxt = sel[cur];
                // 사이클이 생긴 경우 사이클 안에 있는 모든 노드들은 팀을 구성한다.
                if(team[nxt] == 2) {
                    int noteam = i;
                    team[noteam] = 0;
                    noteam = sel[noteam];
                    while(noteam != nxt) {
                        team[noteam] = 0;
                        noteam = sel[noteam];
                    }
                    int yesteam = nxt;
                    team[yesteam] = 1;
                    yesteam = sel[yesteam];
                    while(yesteam != nxt) {
                        team[yesteam] = 1;
                        yesteam = sel[yesteam];
                    }
                    break;
                }
                // 이번 탐색에 방문한 적은 없지만, 팀이 이미 결정이 된 노드를 만날 경우 이전 노드들은 모두 팀을 구성하지 못한다.
                if(team[nxt] != 2 && team[nxt] != -1) {
                    int noteam = i;
                    team[noteam] = 0;
                    noteam = sel[noteam];
                    while(noteam != nxt) {
                        team[noteam] = 0;
                        noteam = sel[noteam];
                    }
                    break;
                }
                team[nxt] = 2;
                Q.push(nxt);
            }
            Q = queue<int>();
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(team[i] != 1) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}