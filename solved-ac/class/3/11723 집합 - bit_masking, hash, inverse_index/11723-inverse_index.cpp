/*
역인덱스 방식을 이용한 풀이. 
*역인덱스: 배열에 수가 들어가는게 아니라, 인덱스가 곧 수를 의미하고 값에는 개수나 존재 여부(0, 1) 이 들어가도록 한 것.

수의 범위가 굉장히 한정적이고, 메모리 제한도 굉장히 빠듯한 문제다.
또한 x가 있는지, 없는지를 계속 체크를 해야 하는데, M이 굉장히 크기 때문에 매 순간마다 선형탐색을 한다면 시간초과가 난다.
따라서, 해시 테이블처럼 수를 관리해서 수를 체크하는데 O(1) 만에 할 수 있다면, 시간안에 해결할 수 있을 것이다.
따라서 역인덱스 방식을 사용했다.

all 과 empty 를 반복하는 최악의 경우 O(20 * 3,000,000) 의 시간복잡도를 가진다.
*/

#include <bits/stdc++.h>
using namespace std;

bool s[21];

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    string cmd;
    int x;
    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd == "add") {
            cin >> x;
            s[x] = 1;
        }
        else if(cmd == "remove") {
            cin >> x;
            s[x] = 0;
        }
        else if(cmd == "check") {
            cin >> x;
            cout << s[x] << '\n';
        }
        else if(cmd == "toggle") {
            cin >> x;
            s[x] = !s[x];
        }
        else if(cmd == "all") {
            fill(s+1, s+21, 1);
        }
        else {
            fill(s+1, s+21, 0);
        }
    }
	return 0;
}