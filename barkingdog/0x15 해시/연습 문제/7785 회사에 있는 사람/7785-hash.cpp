/*
해시를 사용한 풀이.

enter 는 unordered_set 에 추가하는 연산이고, leave 는 삭제하는 연산이다.
이후 set 에 남아있는 원소들을 배열에 넣고 정렬하면 간단하게 풀린다.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string name;
    string cmd;
    unordered_set<string> S;
    for(int i=0; i<n; i++) {
        cin >> name >> cmd;
        if(cmd == "enter") {
            S.insert(name);
        }
        else {
            S.erase(name);
        }
    }
    vector<string> ans(S.begin(), S.end()); // 단순 값 복사의 경우 for 문으로 도는 것보다 이렇게 넣는게 깔끔하다.
    sort(ans.begin(), ans.end(), greater<string>());
    for(string i : ans) {
        cout << i << '\n';
    }
    return 0;
}