def hanoiCount(n):
    if n == 1:
        return 1
    return 2 * hanoiCount(n-1) + 1

def hanoi(k, f, m, t):
    if k == 1:
        print(f, t)
        return
    hanoi(k-1, f, t, m)
    hanoi(1, f, m, t)
    hanoi(k-1, m, f, t)

k = int(input())
print(hanoiCount(k))
if k <= 20:
    hanoi(k, 1, 2, 3)