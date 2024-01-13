/*
이진검색트리를 사용한 풀이

삽입과 삭제가 빈번하고, 원소들의 최대값과 최대값을 찾아야 한다는 것에서 이진검색트리가 필요한 것을
알 수 있다.
배열을 쓸 경우 O(k^2) 이고, 해시를 쓸 경우에는 삽입과 삭제는 O(1) 안에 되지만 최대값과 최소값을 효율적으로 찾을 수 없다.
이진검색트리를 사용한다면 O(lgN) 안에 삽입, 삭제, 최대값, 최소값 찾기를 할 수 있다.

이진검색트리를 사용한 stl 인 set 을 사용할 것이고, 중복이 허용되므로 multiset 을 선택했다.

# 우선순위 큐는 우선순위의 기준이 하나지만, 해당 문제에서는 최소값과 최대값으로 기준이 2개라서 '이중 우선순위 큐' 라고
이름지은 것 같다.
# 상황을 관찰하고 적절한 자료구조를 선택하자.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        multiset<int> MS;
        while(k--) {
            char cmd;
            int n;
            cin >> cmd >> n;
            if(cmd == 'I') {
                MS.insert(n);
            }
            else if(n == -1) {
                auto it = MS.begin();
                if(it != MS.end()) MS.erase(it);
            }
            else {
                if(MS.size() == 0) continue;
                MS.erase(prev(MS.end()));
            }
        }
        if(MS.size() == 0) {
            cout << "EMPTY\n";
        }
        else {
            cout << *prev(MS.end()) << ' ' << *MS.begin() << '\n';
        }
    }

    return 0;
}