/*
길이별 부분문자열 처리와 중복 제거를 위한 해시(unordered_set) 을 이용한 풀이

길이가 n 인 문자열에서 길이가 1인 부분 문자열부터 n 인 부분 문자열까지 구한 다음, 해시 집합에 넣어서
중복을 제거하면 된다.
부분문자열을 추출할 때의 시간복잡도는 O(1 * n + 2 * n/2 + 3 * n/3 + ...) 이고, 해싱은 O(1) 이다.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin >> s;
	unordered_set<string> US;
	int msz = s.length();
	for(int sz = 1; sz <= msz; sz++) {
		for(int i = 0; i<=msz-sz; i++) {
			US.insert(s.substr(i, sz));
		}
	}
	cout << US.size();
	return 0;
}