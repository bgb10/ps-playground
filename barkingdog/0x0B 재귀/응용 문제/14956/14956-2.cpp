/*
재귀 항 사이의 관계를 파악하고, 시계방향과 반시계방향으로 회전함에 따른 방문
순서의 변화를 파악해야 하는 문제. 
항 정의: f(현재 항의 사이즈, 현재 항에서 목적지까지의 위치, 현재 항의 x좌표, 현재 항의 y좌표) 
항 사이의 관계: f(n, m, a, b) <- f(n/2) 항을 호출하는데 4 사분면으로 면을 나눠서 호출한다. 함수를 호출해서 좌표가 반환되면, 각 사분면에 따른 회전 방향을 고려해서 대칭해준다.
base condition: n == 1 일 때 {a, b} 반환

4개씩 연산량을 줄이므로 시간복잡도는 log4(n) 이다.

이전 풀이와는 다르게 먼저 함수를 호출한 후 뒤집어줬다. 뒤집고 나서 함수를 호출하는 경우 생각하기가 조금 부담스러운데, 
먼저 정방향이라고 생각한 후 아래 항에서 좌표를 구하고 나온 값을 방향에 따라 뒤집으니 생각이 간단해진다.

# 시계방향, 반시계방향으로 회전하는 것은 도형의 방정식에서 x=y, x+y=1 대칭과도
같다. 이를 어떻게 표현할지 고민해보자. # a, b 를 직접 회전시키기 보다 변화량을
회전시키는게 훨씬 쉽다. # 배열 순회할 때 값이 복사되므로 변경하려면 참조형을
사용해야 한다.
# 출력을 base condition 에서 하는게 아니라 base condition 에서 반환된 값을 위로 타고 올라오면서 변환하는 방법도 있다.
굳이 base condition 에서 출력해야 한다는 강박을 버리자.
*/
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int ni, mi;

const int CLOCKWISE = 1, COUNTERCLOCKWISE = -1, NONE = 0;
pair<int, int> delta[] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
int rot[] = {CLOCKWISE, NONE, NONE, COUNTERCLOCKWISE};

pair<int, int> flip(pair<int, int> cur, int a, int b, int size, int dir) {
    auto res = cur;
	if (dir == CLOCKWISE) {
		int tmp = res.X;
        res.X = res.Y + a - b;
		res.Y = tmp - a + b;
    } else if (dir == COUNTERCLOCKWISE) {
        int s;
		int tmp = res.X;
		s = a + b + size - 1;
		res.X = s - res.Y;
		res.Y = s - tmp;
    }
    // when dir == NONE, do nothing.
	return res;
}

pair<int, int> f(int n, int m, int a, int b) {
    if (n == 1) {
        return {a, b};
    }
    int portion = (n / 2) * (n / 2);
    for (int i = 1; i <= 4; i++) {
        if (m <= portion * i) {
			// 항을 먼저 구한다.
            auto cur = f(n / 2, m - ((i - 1) * portion), a + delta[i - 1].X * n / 2, b + delta[i - 1].Y * n / 2);
			// 그 다음에 뒤집는다.
            return flip(cur, a + delta[i - 1].X * n / 2, b + delta[i - 1].Y * n / 2, n / 2, rot[i-1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> ni >> mi;
    auto ans = f(ni, mi, 1, 1);
	cout << ans.X << ' ' << ans.Y;
    return 0;
}