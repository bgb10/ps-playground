/*
DP[k] = min(DP[k-A1], DP[k-A2], ...) + 1
-> O(NK) 이기 때문에 시간초과 발생!
*/