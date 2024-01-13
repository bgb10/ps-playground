N, M = map(int, input().split())

result = 0

for _ in range(N):
    row = map(int, input().split())
    result = max(result, min(row))

print(result)
