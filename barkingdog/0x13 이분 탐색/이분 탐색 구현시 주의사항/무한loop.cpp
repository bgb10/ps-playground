/*
target 보다 작은 원소의 가장 오른쪽 위치를 찾는 이분탐색 알고리즘 구현
a[mid] < target : st = mid
a[mid] >= target : en = mid - 1
하지만 위 그대로 이분탐색을 구현하면 무한 loop에 빠지게 된다.

# 이분탐색을 조금이라도 응용한 문제는 binary_search, lower_bound, upper_bound 로 풀 수 없이, 직접 이분탐색을 정의하도록 만든다.
이 경우, 무한 loop 에 빠지지 않게 주의하자.
*/

#include <bits/stdc++.h>
using namespace std;

int a[10] = {2,7,11,11,16,19,22,22,22,32};
int n = 10;

/*
해당 함수는 구간이 균등하게 나눠지지 않을 뿐만 아니라, st와 en이 1 차이날 때 무한 loop 에 빠질 수 있다.
*/
int func1(int target, int len) {
    int st = -1;
    int en = len - 1;
    while(st < en) {
        int mid = (st + en) / 2;
        if(a[mid] < target) st = mid;
        else en = mid - 1;
    }
    return st;
}

/*
구간이 균등하게 나눠지고, st와 en이 1 차이날 때 mid가 st가 아닌 en을 가르키게 함.
*/
int func2(int target, int len) {
    int st = -1;
    int en = len - 1;
    while(st < en) {
        int mid = (st + en + 1) / 2; // 올림
        if(a[mid] < target) st = mid;
        else en = mid - 1;
    }
    return st;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << func1(16, 10);
    cout << func2(16, 10);
	return 0;
}