/*
정렬을 통해 문제를 해결.

enter 배열과 leave 배열을 합쳐서 정렬한 후에 같은 이름이 나오는 동안
enter 개수와 leave 개수를 각각 +1, -1 로 더해주고, cnt 된 값이 양수인 경우
아직 회사에 남아있는 것으로 판단.

마지막에 데이터가 남으므로 더미데이터를 통해 별도의 예외처리 없이 값을
비워줄 수 있다.
*/

#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

pair<string, int> a[100002]; 

int main()
{
    int n;
    cin >> n;
    string name;
    string cmd;
    for(int i=0; i<n; i++) {
        cin >> name >> cmd;
        if(cmd == "enter") {
            a[i] = {name, 1};
        }
        else {
            a[i] = {name, -1};
        }
    }
    sort(a, a+n, greater<pair<string, int>>());
    a[n] = {"DUMMY12345", 0};
    int cnt = 0;
    string bf = a[0].X;
    for(int i=0; i<=n; i++) {
        if(bf != a[i].X) {
            if(cnt > 0) 
                cout << bf << '\n';
            cnt = a[i].Y;
        }
        else {
            cnt += a[i].Y;
        }
        bf = a[i].X;
    }
    return 0;
}
