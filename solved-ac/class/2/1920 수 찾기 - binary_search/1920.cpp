#include <bits/stdc++.h>
using namespace std;

int arr[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    for(int i=0; i<m; i++) {
        int dest;
        cin >> dest;
        int left = 0, right = n-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(arr[mid] == dest) {
                cout << 1;
                break;
            }
            else if(arr[mid] > dest) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if(left > right) {
            cout << 0;
        }
        cout << '\n';
    }
    return 0;
}