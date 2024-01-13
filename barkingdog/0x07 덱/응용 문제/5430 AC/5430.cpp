#include <bits/stdc++.h>
using namespace std;

// 테스트 할 때는 버퍼를 비우기 위해 끝에 endl 사용.
// 나는 parsing 하는게 그지같았으니까, parsing 하는걸 일단 나중에 구현하고 나머지를 구현해놓는게
// 빨리 푸는 방법일듯.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string f;
        cin >> f;
        int len;
        cin >> len;
        string n;
        cin >> n;
        deque<int> DQ;
        bool reversed = false;
        //parsing 하는 부분
        int cur = 0;
        for(int i = 1; i+1 < n.size(); i++) // [, ] 는 건너뛰기
        {
            if(n[i] == ','){
                DQ.push_back(cur);
                cur = 0;
            }
            else{
                cur = 10 * cur + (n[i] - '0');
            }
        }
        if(cur != 0) // 맨 마지막에 남아있는 수 (ex. [1,2,3] 에서 3)
            DQ.push_back(cur);
        // 답 구하는 부분
        string ans;
        for(char c : f) {
            if(c == 'R') {
                reversed = !reversed;
            } else if(c=='D') {
                if(reversed) {
                    if(DQ.size() == 0) {
                        ans = "error";
                        break;
                    }
                    DQ.pop_back();
                } else {
                    if(DQ.size() == 0) {
                        ans = "error";
                        break;
                    }
                    DQ.pop_front();
                }
            }
        }
        if(ans!="error") {
            ans += "[";
            if(reversed) {
                for(int i=DQ.size()-1; i>=0; i--) {
                    if(i == 0) {
                        ans += to_string(DQ[i]);
                        break;
                    }
                    ans += (to_string(DQ[i]) + ",");
                }
            } else {
                for(int i=0; i<DQ.size(); i++) {
                    if(i == DQ.size()-1) {
                        ans += to_string(DQ[i]);
                        break;
                    }
                    ans += (to_string(DQ[i]) + ",");
                }
            }
            ans += "]";
        }

        cout << ans << '\n';
    }

    return 0;
}