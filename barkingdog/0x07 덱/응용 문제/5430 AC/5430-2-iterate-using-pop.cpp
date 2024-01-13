#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        deque<int> DQ;
        string p;
        cin >> p;
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        // 숫자가 0~9만 나오는게 아님. 문제를 잘 읽어볼 것.
        // tokenizing
        int cur = 0;
        for(int i=1; i < arr.size() - 1; i++) {
            if(arr[i] == ',') {
                DQ.push_back(cur);
                cur = 0;
            }
            else {
                cur = 10 * cur + arr[i] - '0';
            }
        }
        // 맨 마지막에 남아있는 수 추가
        if(cur != 0)
            DQ.push_back(cur);
        
        bool reversed = false;
        bool iserror = false;
        for(char c : p) {
            if(c == 'R') reversed = !reversed;
            else {
                if(DQ.empty()) {
                    cout << "error" << '\n';
                    iserror = true;
                    break;
                }
                if(reversed)
                    DQ.pop_back();
                else
                    DQ.pop_front();
            }
        }
        if(iserror) {
            continue;
        }

        // DQ 로 iteration 을 돌면 , 처리가 불편하다.
        cout << '[';
        if(!reversed) {
            while(!DQ.empty()) {
                cout << DQ.front();
                if(DQ.size() != 1) cout << ',';
                DQ.pop_front();
            }
        }
        else {
            while(!DQ.empty()) {
                cout << DQ.back();
                if(DQ.size() != 1) cout << ',';
                DQ.pop_back();
            }
        }
        cout << ']' << '\n';

    }
    return 0;
}