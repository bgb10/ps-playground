/*
전형적인 구현 문제. 문제를 보자마자 시간 처리도 해야하고, 숨이 턱 막힌 문제이다.
어려운 알고리즘을 알고 있다기 보다 빨리, 정확하게 구현할 수 있는지를 묻는 문제이다.
문제 자체도 길고, 이해하기도 오래 걸리는 문제이다.
이런 구현 문제에 대해서도 어느정도 익숙해야겠지.

# 계획을 확실히 세우고 문제를 풀자.
# 변수명을 똑바로 짓자. i, j 등이 남발하면 이런 구현 문제에서는 햇갈릴 가능성이 농후하다.
*/

#include <bits/stdc++.h>
using namespace std;
#define BASE 1000
#define W "wrong"
#define S "solve"

unordered_map<string, int> name_to_score;            // 점수와 사람 정렬하기 위함.
unordered_map<string, pair<int, int>> problem[102];  // 사람과 시간 및 풀이여부(0, 1, -1(invalid))
unordered_map<string, int> score[102];               // 푼 사람들의 걸린 시간.
string people[102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> people[i];
    }
    // 문제에 풀이기록 남기기
    for (int i = 0; i < p; i++) {
        int num;
        string time_str, name, res;
        cin >> num >> time_str >> name >> res;
        int time_num = ((time_str[0] - '0') * 10 + (time_str[1] - '0')) * BASE +
                       ((time_str[3] - '0') * 10 + (time_str[4] - '0'));
        if (problem[num].find(name) == problem[num].end()) {
            if (res == W) {
                problem[num].insert({name, make_pair(time_num, 0)});
            }
            if (res == S) {
                problem[num].insert({name, make_pair(time_num, -1)});
            }
        } else {
            auto it = problem[num].find(name)->second;
            if (it.second == -1) continue;     // invalid 의 경우 그냥 skip
            if (it.second == 0 && res == S) {  // 이미 한번 틀리고 지금 성공한 경우
                score[num].insert({name, time_num - it.first});
                problem[num].find(name)->second.second = 1;
            }
        }
    }
    // 각 문제별로 점수 책정
    for (int i = 1; i <= n; i++) {
        if (problem[i].empty()) {
            continue;  // 아무도 문제를 시도한 적이 없으면 같은 점수를 더해주므로 skip
        }
        // 푼 사람들에 대해 점수 매기기
        vector<pair<int, string>> V;
        for (auto j : score[i]) {
            string name = j.first;
            int duration = j.second;
            V.push_back({duration, name});
        }
        sort(V.begin(), V.end());
        int cnt = 1;
        for (auto j : V) {
            int duration = j.first;
            string name = j.second;
            name_to_score[name] += cnt;
            cnt++;
        }
        // 못 푼 사람들에 대해 점수 매기기
        for (int j = 0; j < m; j++) {
            string name = people[j];
            // 시도도 안한 사람일 경우
            if (problem[i].find(name) == problem[i].end()) {
                name_to_score[name] += m + 1;
            }
            // 부정의 경우
            else if (problem[i].at(name).second == -1) {
                name_to_score[name] += m + 1;
            }
            // 시도는 하지만 실패한 사람일 경우
            else if (problem[i].at(name).second == 0) {
                name_to_score[name] += m;
            }
        }
    }
    // 모든 점수에 대해 열거하고, 정렬하기.
    vector<pair<int, string>> ans;
    for (auto it : name_to_score) {
        ans.push_back({it.second, it.first});
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i.second << '\n';
    }
    return 0;
}