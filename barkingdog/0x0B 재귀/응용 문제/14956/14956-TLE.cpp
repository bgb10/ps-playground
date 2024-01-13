/*
최적화 없이 배열에 원소를 직접 넣으면서 모든 방문 순서를 찾는 풀이.
방문 순서를 하나씩 트래킹해야 한다면 좋은 풀이겠지만, 현재 위치만을 필요로 하는 문제이므로 cost 가 너무 크다.
배열을 전달할 때 값의 복사가 엄청나게 많이 일어나기 때문에 시간안에 풀 수 없다.

# 문제를 풀 때 시간초과가 나지는 않는지 확인하자.
# 문제를 풀기위한 과정에서 너무 불필요한 값을 많이 구하지는 않는지 생각하자.
# 논리적 교착 상태에 빠지지 말자.
*/

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const int CLOCKWISE = 1;
const int COUNTERCLOCKWISE = 2;
const int NORMAL = 3;

void flip(vector<pair<int, int>>& f, int x, int y, int d, int dir) {
	if(dir == CLOCKWISE) {
		for(auto& i : f) {
			int tmp = i.X;
			i.X = i.Y + x - y;
			i.Y = tmp - x + y;
		}
	}
	else if(dir == COUNTERCLOCKWISE) {
		for(auto& i : f) {
			int s;
			int tmp = i.X;
			s = x + y + d - 1;
			i.X = s - i.Y;
			i.Y = s - tmp;
		}
	}
}

vector<pair<int, int>> solve(int n, int x, int y) {
	if(n == 1) {
		vector<pair<int,int>> V;
		V.push_back(make_pair(x, y));
		return V;
	}
    
	vector<pair<int, int>> f;
	vector<pair<int, int>> portion;
	portion = solve(n / 2, x, y);
	flip(portion, x, y, n / 2, CLOCKWISE);
	f.insert(f.end(), portion.begin(), portion.end());
    
	portion = solve(n / 2, x, y + n / 2);
	flip(portion, x, y + n / 2, n / 2, NORMAL);
	f.insert(f.end(), portion.begin(), portion.end());
    
	portion = solve(n / 2, x + n / 2, y + n / 2);
	flip(portion, x + n / 2, y + n / 2, n / 2, NORMAL);
	f.insert(f.end(), portion.begin(), portion.end());
    
	portion = solve(n / 2, x + n / 2, y);
	flip(portion, x + n / 2, y, n / 2, COUNTERCLOCKWISE);
	f.insert(f.end(), portion.begin(), portion.end());
    
	return f;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ans = solve(n, 1, 1);
  	cout << ans[m-1].X << ' ' << ans[m-1].Y;
	return 0;
}
