/*
정렬을 이용한 풀이.

문제의 조건을 관찰해보면, 각 우주 안에 있는 행성 사이의 대소관계가 존재하고,
쌍을 이루는 행성은 행성 사이의 대소관계가 일치한다.
따라서, 쌍을 이루는 우주라면 각 우주 안의 행성을 크기순으로 정렬했을 때 기존 행성들의 상대적 위치가 동일해야 한다.
하지만, 정렬시에 두 행성의 크기가 같은 경우와 뒤에 있는 행성의 크기가 큰 경우를 구분하지 못하기 때문에
만약 크기가 같은 행성이 존재하면 쌍을 이루는 우주도 같은 위치에서 크기가 같은지를 확인해야 한다.

시간복잡도는 O(M^2 * N) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int m, n;
pair<int, int> a[101][10001];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            a[i][j] = make_pair(x, j);
        }
    }
    for(int i=0; i<m; i++) {
        sort(a[i], a[i]+n);
    }
    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            bool balanced = 1;
            int bfi = a[i][0].X;
            int bfj = a[j][0].X;
            for(int k=0; k<n; k++) {
                if(k != 0) {
                    if(bfi == a[i][k].X && bfi != a[j][k].X) {
                        balanced = 0;
                        break;
                    }
                }
                if(a[i][k].Y != a[j][k].Y) {
                    balanced = 0;
                    break;
                }
                bfi = a[i][k].X;
                bfj = a[j][k].X;
            }
            if(balanced) cnt++;
        }
    }
    cout << cnt;
	return 0;
}