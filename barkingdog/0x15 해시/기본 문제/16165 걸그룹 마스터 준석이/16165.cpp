/*
해시 맵을 사용한 풀이

멤버 이름을 통해 팀을 조회해야 하고, 팀 이름을 통해 멤버들을 조회해야 한다.
위 동작 말고 별도의 연산은 없고, 삽입 및 조회만 하므로 해시 맵을 사용하기로 했다.

이때 멤버를 통해 팀을 조회하는 것은 key 가 string, value 가 string 인 맵으로 해결이 가능하지만,
팀을 통해 멤버를 조회하는 것은 key 가 string, value 가 배열(vector) 로 해결해야 한다.
하지만 배열에 있는 값을 결국 정렬해서 출력해야 하기 때문에, 처음에 넣을 때부터 정렬해놓는 것이 좋다.
따라서 key 가 string, value 가 set(이진검색트리)로 map 을 구성한다면, 여러번 출력할 때도 정렬 비용이 들지 않을 것이다.

# 팀을 통해 멤버들을 조회하는 것을 구현할 때, unordered_multimap<string(팀), string(멤버)> 은 사용할 수 없다. 
unordered_multimap 은 value이 아닌 key가 중복되는 것이다. 따라서 팀의 중복은 표현할 수 있지만 멤버의 중복은 표현할 수 없다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, string> member2team;
	unordered_map<string, multiset<string>> team2member;
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		string team;
		cin >> team;
		string member;
		int x;
		cin >> x;
		for(int j=0; j<x; j++) {
			cin >> member;
			member2team[member] = team;
			team2member[team].insert(member);
		}
	}
	for(int i=0; i<m; i++) {
		string s;
		int cmd;
		cin >> s >> cmd;
		if(cmd == 0) {
			for(string i : team2member[s]) {
				cout << i << '\n';
			}
		}
		else {
			cout << member2team[s] << '\n';
		}
	}
	
	return 0;
}