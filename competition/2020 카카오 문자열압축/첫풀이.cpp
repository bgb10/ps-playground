#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 초기항 처리가 힘드네...
// 이전항 다음항을 넘나드는게 힘듦.
int main() {
    string s;
    cin >> s;

    int sl = s.length();
    int answer = sl;

    for(int vl=1; vl<=sl; vl++) {
        string v;
        int r = 1; // 반복 횟수
        int cnt = 0;
        v = s.substr(0, vl);
        string cur;
        for(int i=1; i<sl/vl; i++) {
            cur = s.substr(i * vl, vl);
            if(v == cur)
                r++;
            else {
                v = cur; // 새 단어 등장
                if(r == 1)
                    cnt += vl;
                else
                    cnt += vl + to_string(r).length();
                r = 1;
            }
        }
        if(r == 1)
            cnt += vl;
        else
            cnt += vl + to_string(r).length();

        cnt += sl % vl;
        cout << cnt << '\n';
            
        answer = min(cnt, answer);
    }

    cout << answer;
        
    
    return answer;
}