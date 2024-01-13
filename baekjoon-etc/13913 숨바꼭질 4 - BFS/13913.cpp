#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005
#define X first
#define Y second

pair<int, int> dist[SIZE];
queue<int> Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(dist, dist+SIZE, make_pair(-1, 0));
    int n, k;
    cin >> n >> k;
    Q.push(n);
    dist[n] = {0, -1};
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, cur*2}) {
            if(nxt < 0 || nxt >= SIZE) continue;
            if(dist[nxt].X != -1) continue;
            dist[nxt].X = dist[cur].X + 1;
			dist[nxt].Y = cur;
            Q.push(nxt);
        }
    }
	cout << dist[k].X << '\n';
	vector<int> V;
	V.push_back(k);
	int nxt = dist[k].Y;
	while(nxt != -1) {
		V.push_back(nxt);
		nxt = dist[nxt].Y;
	}
	for(auto it = V.rbegin(); it != V.rend(); it++) {
		cout << *it << ' ';
	}
    return 0;
}