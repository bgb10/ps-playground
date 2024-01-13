/*
Binary Search 를 사용한 풀이. 

enter 배열과 leave 배열을 둔 후, 둘을 정렬한다.
이후 enter 배열의 원소를 확인한 후, enter 배열의 원소의 개수와 leave 배열의 원소의 개수를 비교한다.
enter 배열의 원소의 개수가 더 많을 경우, 아직 건물에 있는 것으로 판단할 수 있다.

# 이분 탐색이므로 투 포인터로도 풀린다.
# 해시 맵을 이용하는 방법도 있다. 그러면 구현이 훨씬 간단해진다.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> enter;
vector<string> leave;
vector<string> ans;

int main()
{
    int n;
    cin >> n;
    string name;
    string cmd;
    for(int i=0; i<n; i++) {
        cin >> name >> cmd;
        if(cmd == "enter") {
            enter.push_back(name);
        }
        else {
            leave.push_back(name);
        }
    }
    sort(enter.begin(), enter.end(), greater<string>());
    sort(leave.begin(), leave.end(), greater<string>());
    int enter_len = 0;
    int leave_len = 0;
    string bf = *enter.begin();
    for(auto it = enter.begin(); it != enter.end(); it++) {
        if(bf == *it) {
            enter_len++;
        }
        else {
            leave_len = upper_bound(leave.begin(), leave.end(), bf, greater<string>()) - lower_bound(leave.begin(), leave.end(), bf, greater<string>());
            if(enter_len > leave_len) {
                ans.push_back(bf);
            }
            bf = *it;
            enter_len = 1;
        }
    }
    leave_len = upper_bound(leave.begin(), leave.end(), bf, greater<string>()) - lower_bound(leave.begin(), leave.end(), bf, greater<string>());
    if(enter_len > leave_len) {
        ans.push_back(bf);
    }
    for(string i : ans) {
        cout << i << '\n';
    }
    return 0;
}