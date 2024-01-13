/*
시간 문자열을 파싱하고, 해시를 이용해 개강총회에 참여한 학생의 수를 세는 문제
더불어 EOF의 처리까지 고민해야 하는 문제다.

우선, 시간 문자열을 대응되는 숫자로 파싱한다. 시간은 60진수기 때문에 10진수 정수로 변환해주면 된다.
시간과 함께 학생의 이름이 주어지는데, 시간에 따라 개총 전에 참여한 것으로 판단하거나, 개총 끝까지 남아있었거나로 판단할 수 있다.
시간을 읽어서 개총 전에 등장한 이름은 개총에 참여한걸로 하고, 이를 해시에 저장한다.
그리고 개총 후에 등장한 이름은 개총 스트리밍이 끝나기 전까지의 이름을 조사해서, 해시에 있는 경우(개총에 참여한 경우)
출석을 확인하면 된다.

# 문제를 읽다가 착각할 수 있는게, 시작 "한시간" 이 아니라 "시작한" 시간이다.
# 채팅 기록의 개수가 주어지지 않기 때문에 EOF 까지 받아야 한다. 백준은 파일로 입출력을 받기 때문에
EOF 가 있지만, 콘솔 입출력에 경우 EOF(아스키코드 26)를 직접 넣어주어야 확인할 수 있다.
윈도우의 경우 Ctrl + Z 를 누르면 되고, linux 계열의 경우 Ctrl + D 를 누르면 EOF 가 입력된다.
*/

#include <bits/stdc++.h>
using namespace std;

int parseTime(string t) {
    return 60 * stoi(t.substr(0, 2)) + stoi(t.substr(3, 2));
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    string t;
    cin >> t;
    int S = parseTime(t);
    cin >> t;
    int E = parseTime(t);
    cin >> t;
    int Q = parseTime(t);

    unordered_set<string> US;
    int cur = -1;
    string name;
    int ans = 0;
    while(!cin.eof()) { // EOF 까지 받기
        cin >> t;
        cur = parseTime(t);
        cin >> name;

        if(cur <= S) {
            US.insert(name);
        }
        else if(E <= cur && cur <= Q) {
            if(US.find(name) != US.end()) {
                ans++;
                US.erase(name);
            }
        }
    }
    cout << ans;
	return 0;
}