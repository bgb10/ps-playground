/*
재귀 항 사이의 관계를 파악하고, 시계방향과 반시계방향으로 회전함에 따른 방문 순서의 변화를 파악해야 하는 문제.
항 정의: f(현재 항의 사이즈, 현재 항에서 목적지까지의 위치, 현재 항의 x좌표, 현재 항의 y좌표, 현재 항의 회전 상태)
항 사이의 관계: f(n, m, a, b, dir) <- 방문 순서를 dir 에 따라 바꾸고, f(n/2) 항을 호출하는데 4 사분면으로 면을 나눠서 호출한다.
base condition: n == 1 일 때 a, b 를 출력한다.

4개씩 연산량을 줄이므로 시간복잡도는 log4(n) 이다.

# 시계방향, 반시계방향으로 회전하는 것은 도형의 방정식에서 x=y, x+y=1 대칭과도 같다. 이를 어떻게 표현할지 고민해보자.
# a, b 를 직접 회전시키기 보다 변화량을 회전시키는게 훨씬 쉽다.
# 배열 순회할 때 값이 복사되므로 변경하려면 참조형을 사용해야 한다.
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int ni, mi;

const int CLOCKWISE = 1, COUNTERCLOCKWISE = -1, NONE = 0;
pair<int, int> delta[] = {{0,0}, {0,1}, {1,1}, {1,0}};
int rot[] = {CLOCKWISE, NONE, NONE, COUNTERCLOCKWISE};

void flip(int dir) {
	if(dir == CLOCKWISE) {
		for(auto &i : delta) { // 아... 참조형으로 써야지 안그럼 값 복사다..
			swap(i.X, i.Y);
		}
	}
	else if(dir == COUNTERCLOCKWISE) {
		for(auto &i : delta) {
			int tmp = i.X;
			i.X = 1 - i.Y;
			i.Y = 1 - tmp;
		}
	}
	// when dir == NONE, do nothing.
}

void f(int n, int m, int a, int b, int dir) {
	if(n == 1) {
		cout << a << ' ' << b;
		return;
	}
	int portion = (n/2) * (n/2);
	for(int i=1; i<=4; i++) {
		if(m <= portion * i) {
			flip(rot[i-1]);
			f(n/2, m-((i-1)*portion), a + delta[i-1].X * n/2, b + delta[i-1].Y * n/2, rot[i-1]);
			return;
		}
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> ni >> mi;
  f(ni, mi, 1, 1, NONE);
  return 0;
}