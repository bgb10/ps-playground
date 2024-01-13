#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

// 초기항, 마지막 항과 같은 경계 조건이 문제이다. 
// 이런 경우 더미 데이터나 시작할 때 값을 특수하게 두는 것을 통해서 통해 경계를 해결할 수 있다.
int main() {
    string s;
    cin >> s;

    int sl = s.length();
    int answer = sl;
    for(int vl=1; vl<=sl; vl++) {
        string v;
        // 단어를 처음에 생성해야 하는데, 순회를 들어가기 전이라 초기값을 넣어야 함.
        // 초기값을 넣을 경우, 처음 읽는 블록이 무조건 같기 때문에 문제가 있다.
        // 이 부분을 따로 처리하기 위해 반복 횟수의 초기값을 0으로 두어야 한다. (이게 핵심!!)
        // 하지만 그냥 두번째 단어부터 읽는 것도 나쁘지 않다. 그것도 초기항 처리니까.
        int r = -1; // 반복 횟수
        int cnt = 0;
        v = s.substr(0, vl);
        string cur;
        // 단어 처리
        for(int i=0; i<sl/vl; i++) {
            cur = s.substr(i * vl, vl);
            if(v == cur)
                r++;
            else {
                v = cur; // 새 단어 등장
                if(r == 0)
                    cnt += vl;
                else
                    cnt += vl + to_string(r + 1).length();
                r = 0;
            }
        }
        // 마지막 단어에 대한 처리
        if(r == 0)
            cnt += vl;
        else
            cnt += vl + to_string(r + 1).length();

        // 단어로 들어가지 않은 나머지 문자열에 대한 처리
        cnt += sl % vl;

        answer = min(cnt, answer);
    }
    cout << answer;
}