/*
unordered_map 을 사용한 풀이

각 포켓몬들의 숫자를 통해 포켓몬의 이름을 찾을 때, 배열을 두거나 map 을 따로 둘 필요 없이
key 와 value 모두 string 인 map 을 사용하면 양방향 매핑이 가능해진다.
이를 통해 출력도 간단하게 할 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> UM;

int main()
{
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    for(int i=1; i<=n; i++) {
        cin >> s;
        string si = to_string(i);
        UM[s] = si;
        UM[si] = s;
    }
    for(int i=0; i<m; i++) {
        cin >> s;
        cout << UM[s] << '\n';
    }
    return 0;
}