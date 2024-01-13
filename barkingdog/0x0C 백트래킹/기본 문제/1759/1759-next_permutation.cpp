#include <bits/stdc++.h>
using namespace std;

char ch[20];
int L, C;
const int vowel[5] = {'a','e','i','o','u'};

// 매 경우마다 m과 j를 카운트하므로 성능상 떨어질 수밖에 없다.
// 백트래킹을 이용하는 경우 자식 노드가 부모 노드의 데이터를 사용할 수 있기 때문에 for문을 도는 횟수가 떨어짐.
// 위 알고리즘은 동작은 하지만, 비효율적이다.

bool isvowel(char a) {
    for(char c : vowel) {
        if(a == c) return true;
    }
    return false;
}

bool iscrypto() {
    int m=0, j=0; // m >= 1, j >= 2
    for(int i=0; i<L; i++) {
        if(isvowel(ch[i])) m++;
        else j++;
    }
    if(m >= 1 && j >= 2) return true;
    else return false;
}

bool isascending() {
    for(int i=0; i<L-1; i++) {
        if(ch[i] >= ch[i+1]) return false;
    }
    return true;
}

void func() {
    do {
        if(iscrypto() && isascending()) {
            for(int i=0; i<L; i++)
                cout << ch[i];
            cout << '\n';
        }
        reverse(ch + L, ch + C);
    } while(next_permutation(ch, ch+C));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> C;
    // C permutation L (C 개 중에서 L 개를 뽑아 순서있이 정렬하는 순열 문제)
    for(int i=0; i<C; i++) 
        cin >> ch[i];
    sort(ch, ch + C);
    func();
    return 0;
}