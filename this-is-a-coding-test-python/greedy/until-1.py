N, K = map(int, input().split())

result = 0

while True:
    if N == 1:
        break
    if N % K == 0:
        N /= K
    else:
        N -= 1
    result += 1

print(result)
