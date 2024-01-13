N, M = map(int, input().split())
money = []
for i in range(N):
    money.append(int(input()))

INF = 999999999
d = [INF] * 100000
for i in money:
    d[i] = 1

for i in range(1, M+1):
    for j in range(N):
        prev = i - money[j]
        if prev >= 0:
            d[i] = min(d[i], d[prev] + 1)

print(d[M] if d[M] != INF else -1)
