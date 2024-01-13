/*

*/
#include <bits/stdc++.h>
using namespace std;

int parent[10005];
int rrank[10005];

void MakeSet(int x) {
    parent[x] = x;
    rrank[x] = 0;
}

int Find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return Find(parent[x]);
    }
}

int FindByPathCompression(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = FindByPathCompression(parent[x]);
    }
}

void Union(int x, int y) {
    int rootX = Find(x);
    int rootY = Find(y);
    if (rootX == rootY)
        return;
    else {
        parent[rootY] = rootX;
        return;
    }
}

void UnionByRank(int x, int y) {
    int rootX = FindByPathCompression(x);
    int rootY = FindByPathCompression(y);
    if (rootX == rootY)
        return;
    else {
        if (rrank[rootX] > rrank[rootY]) {
            parent[rootY] = rootX;
        } else if (rrank[rootX] < rrank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rrank[rootX]++;
        }
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 연산 당 시간복잡도 O(NlogN + M) (N은 원소의 개수, M은 연산 횟수)

    MakeSet(1);
    MakeSet(2);
    MakeSet(3);
    MakeSet(4);
    MakeSet(5);

    cout << Find(1) << '\n';
    cout << Find(2) << '\n';
    Union(1, 2);
    cout << Find(1) << '\n';
    cout << Find(2) << '\n';

    cout << Find(4) << '\n';
    cout << Find(5) << '\n';
    Union(4, 5);
    cout << Find(4) << '\n';
    cout << Find(5) << '\n';

    Union(2, 5);
    cout << Find(1) << '\n';
    cout << Find(2) << '\n';
    cout << Find(3) << '\n';
    cout << Find(4) << '\n';
    cout << Find(5) << '\n';

    cout << "-----------------------------" << '\n';
    // 연산 당 시간복잡도 O(logN)

    MakeSet(6);
    MakeSet(7);
    MakeSet(8);
    MakeSet(9);
    MakeSet(10);

    cout << FindByPathCompression(6) << '\n';
    cout << FindByPathCompression(7) << '\n';
    UnionByRank(6, 7);
    cout << FindByPathCompression(6) << '\n';
    cout << FindByPathCompression(7) << '\n';

    cout << FindByPathCompression(7) << '\n';
    cout << FindByPathCompression(8) << '\n';
    UnionByRank(7, 8);
    cout << FindByPathCompression(7) << '\n';
    cout << FindByPathCompression(8) << '\n';
    return 0;
}