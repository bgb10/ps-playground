/*
Merge Sort 에서 수를 재귀적으로 쪼갠 후에 수를 비교하는 아이디어를 알고 있는가?
해당 아이디어를 이용해서 풀면 쉽게 풀 수 있다.
Merge Sort 에서 두 수열을 비교할 때는 정렬되었다는 전제가 있다.
따라서, 듣지 못한 사람과 보도 못한 사람을 정렬한 후(이때 사전순이 된다.) 두 수열에 포인터를 하나씩 두고 비교해가면서 출력하면 된다.

# 간단하게 set 을 사용해서 풀어도 된다.
# 이분 탐색을 사용하면 O(nlgn) 도 가능할 듯
*/

#include <bits/stdc++.h>

using namespace std;

string a[500001];
string b[500001];
vector<string> c;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+m);
    int it1 = 0, it2 = 0;
    int cnt = 0;
    while(it1 < n && it2 < m) {
        if(a[it1] == b[it2]) {
            c.push_back(a[it1]);
            cnt++;
            it1++;
            it2++;
        }
        else if(a[it1] > b[it2]) {
            it2++;
        }
        else {
            it1++;
        }
    }
    cout << cnt << '\n';
    for(string e : c) {
        cout << e << '\n';
    }
    return 0;
}