#include <bits/stdc++.h>
using namespace std;

string ages[202]; // 인덱스는 나이를 지칭, 값은 해당 나이 값을 가지고 있는 사람들의 이름을 개행과 함께 가지고 있음

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int age;
    string name;
    cin >> t;
    while(t--) {
        cin >> age;
        cin >> name;
        ages[age] += to_string(age) + ' ' + name + '\n';
    }
    for(int i=1; i<=200; i++) {
        if(ages[i] == "") continue;
        cout << ages[i];
    }
    return 0;
}