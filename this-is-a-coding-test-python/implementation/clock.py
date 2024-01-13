N = int(input())

ans = 0

for h in range(N+1):
    for m in range(60):
        for s in range(60):
            hhmmss = f'{h}{m}{s}'
            if '3' in hhmmss:
                ans += 1

print(ans)
