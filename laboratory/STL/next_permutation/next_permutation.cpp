#include <bits/stdc++.h>
using namespace std;

vector<int> sel;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    n = 3;
    cout << "주어진 수열이 오름차순 경우 사용, 처음에는 그냥 수열을 출력해야 하므로 do~while 문 사용" << '\n';
    for(int i=0; i<n; i++) sel.push_back(i);
    do {
        for(int i=0; i<n; i++) cout << sel[i] << ' ';
        cout << '\n';
    } while(next_permutation(sel.begin(), sel.end()));
    
    sel = vector<int>();
    cout << "오름차순 아닐 경우 예상 밖의 결과 발생!!" << '\n';
    for(int i=n-1; i>=0; i--) sel.push_back(i);
    do {
        for(int i=0; i<n; i++) cout << sel[i] << ' ';
        cout << '\n';
    } while(next_permutation(sel.begin(), sel.end()));
    
    return 0;
}